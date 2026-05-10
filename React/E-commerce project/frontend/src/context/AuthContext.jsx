import { createContext, useState, useContext, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';

const AuthContext = createContext();

export const useAuth = () => useContext(AuthContext);

export const AuthProvider = ({ children }) => {
  const [user, setUser] = useState(null);
  const [loading, setLoading] = useState(true);
  const navigate = useNavigate();

  useEffect(() => {
    const storedUser = localStorage.getItem('babyToyUser');
    if (storedUser) {
      setUser(JSON.parse(storedUser));
    }
    setLoading(false);
  }, []);

  const register = (email, password, name) => {
    const users = JSON.parse(localStorage.getItem('babyToyUsers') || '[]');
    const exists = users.find(u => u.email === email);
    if (exists) throw new Error('User already exists');
    const newUser = { id: Date.now(), email, name, password };
    users.push(newUser);
    localStorage.setItem('babyToyUsers', JSON.stringify(users));
    const { password: _, ...userWithoutPassword } = newUser;
    setUser(userWithoutPassword);
    localStorage.setItem('babyToyUser', JSON.stringify(userWithoutPassword));
    return userWithoutPassword;
  };

  const login = (email, password) => {
    const users = JSON.parse(localStorage.getItem('babyToyUsers') || '[]');
    const foundUser = users.find(u => u.email === email && u.password === password);
    if (!foundUser) throw new Error('Invalid credentials');
    const { password: _, ...userWithoutPassword } = foundUser;
    setUser(userWithoutPassword);
    localStorage.setItem('babyToyUser', JSON.stringify(userWithoutPassword));
    return userWithoutPassword;
  };

  const logout = () => {
    setUser(null);
    localStorage.removeItem('babyToyUser');
    navigate('/');
  };

  return (
    <AuthContext.Provider value={{ user, login, register, logout, loading }}>
      {children}
    </AuthContext.Provider>
  );
};