import React, { useContext, useEffect, useState } from "react";
import { Link } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";

const Order = () => {
  const { api, user } = useContext(AuthContext);
  const [orders, setOrders] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    if (!user) return;
    fetchOrders();
  }, [user]);

  const fetchOrders = async () => {
    try {
      const res = await api.get("/orders/");
      setOrders(res.data);
    } catch (err) {
      console.error("Failed to fetch orders", err);
    } finally {
      setLoading(false);
    }
  };

  if (loading) return <div className="my-10 text-center">Loading orders...</div>;

  if (orders.length === 0) {
    return (
      <div className="my-10 text-center">
        <Title text1={"MY"} text2={"ORDERS"} />
        <p className="mt-8 text-gray-500">You have no orders yet.</p>
        <Link
          to="/collection"
          className="inline-block mt-4 bg-black text-white px-6 py-2 rounded cursor-pointer hover:bg-gray-800"
        >
          Continue Shopping
        </Link>
      </div>
    );
  }

  return (
    <div className="my-10">
      <Title text1={"MY"} text2={"ORDERS"} />
      <div className="mt-6 space-y-6">
        {orders.map((order) => (
          <div key={order.id} className="border rounded-md p-4 shadow-sm">
            <div className="flex justify-between items-center flex-wrap gap-2 border-b pb-2">
              <span className="font-medium">Order #{order.id}</span>
              <span className="text-sm text-gray-500">
                {new Date(order.created_at).toLocaleDateString()}
              </span>
              <span
                className={`px-2 py-0.5 rounded text-xs ${
                  order.status === "delivered"
                    ? "bg-green-100 text-green-700"
                    : order.status === "pending"
                    ? "bg-yellow-100 text-yellow-700"
                    : "bg-blue-100 text-blue-700"
                }`}
              >
                {order.status}
              </span>
            </div>
            <div className="mt-3">
              {order.items && order.items.length > 0 ? (
                order.items.map((item) => (
                  <div key={item.id} className="flex justify-between text-sm py-1">
                    <span>
                      {item.product?.product_name || "Product"} x{item.quantity}
                    </span>
                    <span>{item.unit_price * item.quantity} BDT</span>
                  </div>
                ))
              ) : (
                <p className="text-gray-500 text-sm">No items in this order.</p>
              )}
            </div>
            <div className="flex justify-between font-semibold mt-3 pt-2 border-t">
              <span>Total</span>
              <span>{order.total} BDT</span>
            </div>
            <div className="text-sm text-gray-600 mt-2">
              <p>Delivery to: {order.shipping_address}</p>
              <p>Phone: {order.phone}</p>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default Order;