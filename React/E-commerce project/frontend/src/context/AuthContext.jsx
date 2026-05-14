import { createContext, useContext, useState, useEffect, useRef, useMemo } from "react";
import axios from "axios";

const AuthContext = createContext();
export { AuthContext };

const AuthContextProvider = (props) => {
  const currency = "BDT";
  const delivery_fee = 50;

  const [user, setUser] = useState(null);
  const [token, setToken] = useState(localStorage.getItem("access_token"));
  const [loading, setLoading] = useState(true);
  const [products, setProducts] = useState([]);
  const [categories, setCategories] = useState([]);
  const [cartItems, setCartItems] = useState(() => {
    const saved = localStorage.getItem("cart");
    return saved ? JSON.parse(saved) : [];
  });

  const tokenRef = useRef(token);
  useEffect(() => {
    tokenRef.current = token;
  }, [token]);

  const api = useMemo(() => {
    const instance = axios.create({
      baseURL: "http://localhost:8000/api",
    });
    instance.interceptors.request.use((config) => {
      if (tokenRef.current) {
        config.headers.Authorization = `Bearer ${tokenRef.current}`;
      }
      return config;
    });
    return instance;
  }, []);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const [productsRes, categoriesRes] = await Promise.all([
          axios.get("http://localhost:8000/api/products/"),
          axios.get("http://localhost:8000/api/products/category/list/"),
        ]);
        setProducts(productsRes.data);
        setCategories(categoriesRes.data);
      } catch (err) {
        console.error("Failed to fetch products/categories", err);
      }
    };
    fetchData();
  }, []);

  useEffect(() => {
    const loadUser = async () => {
      if (!token) {
        setLoading(false);
        return;
      }
      try {
        const payload = JSON.parse(atob(token.split('.')[1]));
        const userId = payload.user_id;
        const res = await api.get(`/user/profile/${userId}/`);
        setUser(res.data);
      } catch (err) {
        console.error("User load failed", err);
        logout();
      } finally {
        setLoading(false);
      }
    };
    loadUser();
  }, [token, api]);

  useEffect(() => {
    localStorage.setItem("cart", JSON.stringify(cartItems));
  }, [cartItems]);

  const login = async (email, password) => {
    try {
      const res = await axios.post("http://localhost:8000/api/user/token/", { email, password });
      localStorage.setItem("access_token", res.data.access);
      localStorage.setItem("refresh_token", res.data.refresh);
      setToken(res.data.access);
      return { success: true };
    } catch (err) {
      return {
        success: false,
        error: err.response?.data?.detail || "Invalid email or password",
      };
    }
  };

  const register = async (email, password, fullName, location, country, phone) => {
    try {
      await axios.post("http://localhost:8000/api/user/register/", {
        full_name: fullName,
        email,
        password,
        password2: password,
        location: location || "",
        country: country || "",
        cell: phone || "",
      });
      return await login(email, password);
    } catch (err) {
      const errorMsg = err.response?.data?.detail ||
                       err.response?.data?.password?.[0] ||
                       "Registration failed";
      return { success: false, error: errorMsg };
    }
  };

  const logout = () => {
    setUser(null);
    setToken(null);
    localStorage.removeItem("access_token");
    localStorage.removeItem("refresh_token");
    localStorage.removeItem("user");
  };

  const refreshUser = async () => {
    if (!token) return;
    try {
      const payload = JSON.parse(atob(token.split('.')[1]));
      const userId = payload.user_id;
      const res = await api.get(`/user/profile/${userId}/`);
      setUser(res.data);
      return res.data;
    } catch (err) {
      console.error("Refresh user failed", err);
      return null;
    }
  };

  const addToCart = (product, quantity = 1) => {
    setCartItems((prev) => {
      const existing = prev.find((item) => item.id === product.id);
      if (existing) {
        return prev.map((item) =>
          item.id === product.id ? { ...item, quantity: item.quantity + quantity } : item
        );
      } else {
        return [...prev, { ...product, quantity }];
      }
    });
  };

  const removeFromCart = (id) => setCartItems((prev) => prev.filter((item) => item.id !== id));
  const updateQuantity = (id, qty) => {
    if (qty < 1) return;
    setCartItems((prev) => prev.map((item) => (item.id === id ? { ...item, quantity: qty } : item)));
  };
  const getCartTotal = () => cartItems.reduce((sum, i) => sum + i.price * i.quantity, 0);
  const getCartCount = () => cartItems.reduce((sum, i) => sum + i.quantity, 0);
  const clearCart = () => setCartItems([]);

  const value = {
    currency,
    delivery_fee,
    user,
    token,
    loading,
    products,
    categories,
    cartItems,
    login,
    register,
    logout,
    refreshUser,
    addToCart,
    removeFromCart,
    updateQuantity,
    getCartTotal,
    getCartCount,
    clearCart,
    api,
  };

  return <AuthContext.Provider value={value}>{props.children}</AuthContext.Provider>;
};

export default AuthContextProvider;