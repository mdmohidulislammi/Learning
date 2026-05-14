import React, { useContext, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";
import { useNavigate } from "react-router-dom";

const PlaceOrder = () => {
  const { cartItems, getCartTotal, currency, delivery_fee, clearCart, api, user } = useContext(AuthContext);
  const navigate = useNavigate();

  const [formData, setFormData] = useState({
    fullName: "",
    address: "",
    city: "",
    phone: "",
  });
  const [isSubmitting, setIsSubmitting] = useState(false);
  const [error, setError] = useState("");

  const handleChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    if (cartItems.length === 0) {
      setError("Your cart is empty");
      return;
    }
    if (!formData.fullName || !formData.address || !formData.city || !formData.phone) {
      setError("Please fill all fields");
      return;
    }

    setIsSubmitting(true);
    setError("");

    // Prepare items array for backend
    const items = cartItems.map(item => ({
      id: item.id,
      quantity: item.quantity,
    }));

    const shipping_address = `${formData.address}, ${formData.city}`;
    const phone = formData.phone;

    try {
      await api.post("/orders/create/", {
        items,
        shipping_address,
        phone,
      });

      clearCart();
      navigate("/orders");
    } catch (err) {
      console.error("Order creation error", err);
      setError(err.response?.data?.error || "Failed to place order. Please try again.");
    } finally {
      setIsSubmitting(false);
    }
  };

  const subtotal = getCartTotal();
  const total = subtotal + delivery_fee;

  if (cartItems.length === 0) {
    return (
      <div className="my-10 text-center">
        <Title text1={"CHECKOUT"} text2={""} />
        <p className="mt-8">Your cart is empty. Add products first.</p>
        <button
          onClick={() => navigate("/collection")}
          className="mt-4 bg-black text-white px-6 py-2 rounded cursor-pointer hover:bg-gray-800"
        >
          Go to Shop
        </button>
      </div>
    );
  }

  return (
    <div className="my-10">
      <Title text1={"CHECKOUT"} text2={""} />
      <div className="flex flex-col lg:flex-row gap-8 mt-6">
        <form onSubmit={handleSubmit} className="flex-1 space-y-4">
          <input
            type="text"
            name="fullName"
            placeholder="Full Name"
            value={formData.fullName}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2"
            required
          />
          <input
            type="text"
            name="address"
            placeholder="Street Address"
            value={formData.address}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2"
            required
          />
          <input
            type="text"
            name="city"
            placeholder="City"
            value={formData.city}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2"
            required
          />
          <input
            type="tel"
            name="phone"
            placeholder="Phone Number"
            value={formData.phone}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2"
            required
          />
          {error && <p className="text-red-500 text-sm">{error}</p>}
          <button
            type="submit"
            disabled={isSubmitting}
            className="bg-black text-white px-6 py-2 rounded cursor-pointer hover:bg-gray-800 disabled:bg-gray-400 disabled:cursor-not-allowed"
          >
            {isSubmitting ? "Placing Order..." : "Place Order"}
          </button>
        </form>
        <div className="lg:w-80 bg-gray-50 p-5 rounded-md h-fit">
          <h2 className="text-xl font-semibold">Order Summary</h2>
          {cartItems.map((item) => (
            <div key={item.id} className="flex justify-between text-sm mt-2">
              <span>{item.product_name} x{item.quantity}</span>
              <span>{item.price * item.quantity} {currency}</span>
            </div>
          ))}
          <hr className="my-2" />
          <div className="flex justify-between">
            <span>Subtotal</span>
            <span>{subtotal} {currency}</span>
          </div>
          <div className="flex justify-between">
            <span>Delivery Fee</span>
            <span>{delivery_fee} {currency}</span>
          </div>
          <div className="flex justify-between font-bold mt-2">
            <span>Total</span>
            <span>{total} {currency}</span>
          </div>
        </div>
      </div>
    </div>
  );
};

export default PlaceOrder;