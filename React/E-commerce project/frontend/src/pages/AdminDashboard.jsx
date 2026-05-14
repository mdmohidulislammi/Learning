// pages/AdminDashboard.jsx
import React, { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";
import AddProduct from "../components/AddProduct";

const AdminDashboard = () => {
  const { user, api } = useContext(AuthContext);
  const [stats, setStats] = useState({
    total_users: 0,
    total_products: 0,
    total_orders: 0,
    total_categories: 0,
    total_revenue: 0,
    recent_orders: [],
  });
  const [products, setProducts] = useState([]);
  const [categories, setCategories] = useState([]);
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [loadingUsers, setLoadingUsers] = useState(false);
  const [showProductForm, setShowProductForm] = useState(false);
  const [editingProduct, setEditingProduct] = useState(null);
  const [message, setMessage] = useState({ type: "", text: "" });

  useEffect(() => {
    if (!user?.is_staff) return;
    fetchDashboardData();
    fetchProducts();
    fetchCategories();
    fetchUsers();
  }, []);

  const fetchDashboardData = async () => {
    try {
      const res = await api.get("/dashboard/");
      setStats(res.data);
    } catch (err) {
      console.error("Stats error", err);
    }
  };

  const fetchProducts = async () => {
    try {
      const res = await api.get("/products/");
      console.log("Fetched products:", res.data);
      setProducts(res.data);
      setLoading(false);
    } catch (err) {
      console.error("Products error", err);
      setLoading(false);
    }
  };

  const fetchCategories = async () => {
    try {
      const res = await api.get("/products/category/list/");
      setCategories(res.data);
    } catch (err) {
      console.error("Categories error", err);
    }
  };

  const fetchUsers = async () => {
    if (!user?.is_staff) return;
    setLoadingUsers(true);
    try {
      const res = await api.get("/users/");
      setUsers(res.data);
    } catch (err) {
      console.error("Failed to fetch users", err);
    } finally {
      setLoadingUsers(false);
    }
  };

  const handleProductSubmit = async (formData) => {
    if (editingProduct) {
      await api.put(
        `/dashboard/update-product/${editingProduct.id}/`,
        formData,
      );
    } else {
      await api.post("/dashboard/create-product/", formData);
    }
    await fetchProducts();
    setMessage({
      type: "success",
      text: `Product ${editingProduct ? "updated" : "created"} successfully!`,
    });
    setTimeout(() => setMessage({ type: "", text: "" }), 3000);
    setShowProductForm(false);
    setEditingProduct(null);
  };

  const handleDeleteProduct = async (id) => {
    if (!window.confirm("Delete this product permanently?")) return;
    try {
      await api.delete(`/dashboard/product/${id}/delete/`);
      setMessage({ type: "success", text: "Product deleted successfully!" });
      fetchProducts();
      setTimeout(() => setMessage({ type: "", text: "" }), 3000);
    } catch (err) {
      console.error("Delete error", err);
      setMessage({ type: "error", text: "Failed to delete product." });
    }
  };

  const toggleStaff = async (userId, currentStaff) => {
    try {
      await api.patch(`/users/${userId}/update/`, { is_staff: !currentStaff });
      fetchUsers();
      setMessage({ type: "success", text: "User role updated." });
      setTimeout(() => setMessage({ type: "", text: "" }), 3000);
    } catch (err) {
      console.error(err);
      setMessage({ type: "error", text: "Failed to update user." });
    }
  };

  const deleteUser = async (userId, userName) => {
    if (!window.confirm(`Delete user "${userName}" permanently?`)) return;
    try {
      await api.delete(`/users/${userId}/delete/`);
      fetchUsers();
      setMessage({ type: "success", text: "User deleted." });
      setTimeout(() => setMessage({ type: "", text: "" }), 3000);
    } catch (err) {
      console.error(err);
      setMessage({
        type: "error",
        text: err.response?.data?.error || "Failed to delete user.",
      });
    }
  };

  if (!user?.is_staff) {
    return (
      <div className="my-10 text-center">
        <p className="text-red-500">Access denied. Admin only.</p>
      </div>
    );
  }

  return (
    <div className="my-10">
      <Title text1={"ADMIN"} text2={"DASHBOARD"} />

      {/* Stats Cards */}
      <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-4 gap-4 my-8">
        <div className="bg-white p-5 rounded-lg shadow-md">
          <h3 className="text-gray-500 text-sm">Total Users</h3>
          <p className="text-2xl font-bold">{stats.total_users}</p>
        </div>
        <div className="bg-white p-5 rounded-lg shadow-md">
          <h3 className="text-gray-500 text-sm">Total Products</h3>
          <p className="text-2xl font-bold">{stats.total_products}</p>
        </div>
        <div className="bg-white p-5 rounded-lg shadow-md">
          <h3 className="text-gray-500 text-sm">Total Orders</h3>
          <p className="text-2xl font-bold">{stats.total_orders}</p>
        </div>
        <div className="bg-white p-5 rounded-lg shadow-md">
          <h3 className="text-gray-500 text-sm">Revenue (BDT)</h3>
          <p className="text-2xl font-bold">৳{stats.total_revenue}</p>
        </div>
      </div>

      {/* Recent Orders Table */}
      <div className="bg-white p-5 rounded-lg shadow-md mb-8">
        <h2 className="text-xl font-semibold mb-4">Recent Orders</h2>
        <div className="overflow-x-auto">
          <table className="min-w-full text-sm">
            <thead className="bg-gray-100">
              <tr>
                <th className="p-2 text-left">Order ID</th>
                <th>Total (BDT)</th>
                <th>Status</th>
                <th>Date</th>
              </tr>
            </thead>
            <tbody>
              {stats.recent_orders.map((order) => (
                <tr key={order.id} className="border-b">
                  <td className="p-2">#{order.id}</td>
                  <td className="p-2">৳{order.total}</td>
                  <td className="p-2 capitalize">{order.status}</td>
                  <td className="p-2">
                    {new Date(order.created_at).toLocaleDateString()}
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>

      {/* User Management */}
      <div className="bg-white p-5 rounded-lg shadow-md mb-8">
        <h2 className="text-xl font-semibold mb-4">User Management</h2>
        {loadingUsers ? (
          <p>Loading users...</p>
        ) : (
          <div className="overflow-x-auto">
            <table className="min-w-full text-sm">
              <thead className="bg-gray-100">
                <tr>
                  <th className="p-2 text-left">Username</th>
                  <th>Email</th>
                  <th>Staff</th>
                  <th>Actions</th>
                </tr>
              </thead>
              <tbody>
                {users.map((u) => (
                  <tr key={u.id} className="border-b">
                    <td className="p-2">{u.username}</td>
                    <td className="p-2">{u.email}</td>
                    <td className="p-2">{u.is_staff ? "✅ Yes" : "❌ No"}</td>
                    <td className="p-2">
                      <button
                        onClick={() => toggleStaff(u.id, u.is_staff)}
                        className="text-blue-600 cursor-pointer hover:underline mr-3"
                      >
                        {u.is_staff ? "Remove Admin" : "Make Admin"}
                      </button>
                      <button
                        onClick={() => deleteUser(u.id, u.username)}
                        className="text-red-600 cursor-pointer hover:underline"
                      >
                        Delete
                      </button>
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        )}
      </div>

      <div className="bg-white p-5 rounded-lg shadow-md">
        <div className="flex justify-between items-center mb-4">
          <h2 className="text-xl font-semibold">Products</h2>
          <button
            onClick={() => {
              setEditingProduct(null);
              setShowProductForm(true);
            }}
            className="bg-blue-600 cursor-pointer text-white px-4 py-2 rounded-md hover:bg-blue-700"
          >
            + Add Product
          </button>
        </div>
        {message.text && (
          <div
            className={`mb-4 p-3 rounded-md ${message.type === "success" ? "bg-green-100 text-green-700" : "bg-red-100 text-red-700"}`}
          >
            {message.text}
          </div>
        )}
        {loading ? (
          <p>Loading products...</p>
        ) : (
          <div className="overflow-x-auto">
            <table className="min-w-full text-sm">
              <thead className="bg-gray-100">
                <tr>
                  <th className="p-2 text-left">Name</th>
                  <th className="p-2 text-left">Category</th>
                  <th className="p-2 text-left">Price</th>
                  <th className="p-2 text-left">Stock</th>
                  <th className="p-2 text-left">Age (months)</th>
                  <th className="p-2 text-left">Available</th> {/* new */}
                  <th className="p-2 text-left">Actions</th>
                </tr>
              </thead>
              <tbody>
                {products.map((prod) => (
                  <tr key={prod.id} className="border-b">
                    <td className="p-2">{prod.product_name}</td>
                    <td className="p-2">{prod.category?.title || "—"}</td>
                    <td className="p-2">৳{prod.price}</td>
                    <td className="p-2">{prod.stock}</td>
                    <td className="p-2">
                      {prod.min_age} – {prod.max_age}
                    </td>
                    <td className="p-2">
                      {prod.is_available ? (
                        <span className="text-green-600">✅ Yes</span>
                      ) : (
                        <span className="text-red-600">❌ No</span>
                      )}
                    </td>
                    <td className="p-2">
                      <button
                        onClick={() => {
                          setEditingProduct(prod);
                          setShowProductForm(true);
                        }}
                        className="text-blue-600 cursor-pointer hover:underline mr-3"
                      >
                        Edit
                      </button>
                      <button
                        onClick={() => handleDeleteProduct(prod.id)}
                        className="text-red-600 cursor-pointer hover:underline"
                      >
                        Delete
                      </button>
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        )}
      </div>

      {/* Modal for Add/Edit Product */}
      {showProductForm && (
        <div className="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center z-50 p-4">
          <AddProduct
            initialData={editingProduct}
            categories={categories}
            isEditing={!!editingProduct}
            onSubmit={handleProductSubmit}
            onCancel={() => setShowProductForm(false)}
          />
        </div>
      )}
    </div>
  );
};

export default AdminDashboard;
