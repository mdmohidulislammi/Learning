import React, { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";

const AdminOrders = () => {
  const { user, api } = useContext(AuthContext);
  const [orders, setOrders] = useState([]);
  const [loading, setLoading] = useState(true);
  const [message, setMessage] = useState({ type: "", text: "" });
  const [updatingId, setUpdatingId] = useState(null);

  useEffect(() => {
    if (!user?.is_staff) return;
    fetchOrders();
  }, []);

  const fetchOrders = async () => {
    try {
      const res = await api.get("/admin/orders/");
      setOrders(res.data);
    } catch (err) {
      console.error("Failed to fetch orders", err);
    } finally {
      setLoading(false);
    }
  };

  const updateOrderStatus = async (orderId, newStatus) => {
    setUpdatingId(orderId);
    setMessage({ type: "", text: "" });
    try {
      await api.patch(`/admin/orders/${orderId}/update/`, { status: newStatus });
      setMessage({ type: "success", text: "Order status updated!" });
      fetchOrders(); // refresh list
      setTimeout(() => setMessage({ type: "", text: "" }), 3000);
    } catch (err) {
      console.error(err);
      setMessage({ type: "error", text: "Failed to update status." });
    } finally {
      setUpdatingId(null);
    }
  };

  if (!user?.is_staff) {
    return (
      <div className="my-10 text-center">
        <p className="text-red-500">Access denied. Admin only.</p>
      </div>
    );
  }

  if (loading) return <div className="my-10 text-center">Loading orders...</div>;

  return (
    <div className="my-10">
      <Title text1={"ORDER"} text2={"MANAGEMENT"} />
      {message.text && (
        <div className={`mb-4 p-3 rounded-md ${message.type === "success" ? "bg-green-100 text-green-700" : "bg-red-100 text-red-700"}`}>
          {message.text}
        </div>
      )}
      <div className="overflow-x-auto bg-white rounded-lg shadow-md">
        <table className="min-w-full text-sm">
          <thead className="bg-gray-100">
            <tr>
              <th className="p-3 text-left">Order ID</th>
              <th className="p-3 text-left">User</th>
              <th className="p-3 text-left">Total (BDT)</th>
              <th className="p-3 text-left">Status</th>
              <th className="p-3 text-left">Date</th>
              <th className="p-3 text-left">Address</th>
              <th className="p-3 text-left">Phone</th>
              <th className="p-3 text-left">Action</th>
            </tr>
          </thead>
          <tbody>
            {orders.map((order) => (
              <tr key={order.id} className="border-b hover:bg-gray-50">
                <td className="p-3">#{order.id}</td>
                <td className="p-3">{order.profile?.full_name || order.profile?.user?.username || "N/A"}</td>
                <td className="p-3">৳{order.total}</td>
                <td className="p-3">
                  <span className={`px-2 py-1 rounded text-xs ${
                    order.status === 'delivered' ? 'bg-green-100 text-green-700' :
                    order.status === 'pending' ? 'bg-yellow-100 text-yellow-700' :
                    'bg-blue-100 text-blue-700'
                  }`}>
                    {order.status}
                  </span>
                </td>
                <td className="p-3">{new Date(order.created_at).toLocaleDateString()}</td>
                <td className="p-3 max-w-xs truncate">{order.shipping_address}</td>
                <td className="p-3">{order.phone || "—"}</td>
                <td className="p-3">
                  <select
                    value={order.status}
                    onChange={(e) => updateOrderStatus(order.id, e.target.value)}
                    disabled={updatingId === order.id}
                    className="cursor-pointer border rounded px-2 py-1 text-sm"
                  >
                    <option value="pending">Pending</option>
                    <option value="processing">Processing</option>
                    <option value="shipped">Shipped</option>
                    <option value="delivered">Delivered</option>
                  </select>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  );
};

export default AdminOrders;