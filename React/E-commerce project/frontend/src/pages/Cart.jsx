// pages/Cart.js
import React, { useContext } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";
import { Link } from "react-router-dom";

const Cart = () => {
  const {
    cartItems,
    removeFromCart,
    updateQuantity,
    getCartTotal,
    currency,
    delivery_fee,
  } = useContext(AuthContext);

  const subtotal = getCartTotal();
  const total = subtotal + delivery_fee;

  if (cartItems.length === 0) {
    return (
      <div className="my-10 text-center">
        <Title text1={"YOUR"} text2={"CART"} />
        <p className="mt-8 text-gray-500">Your cart is empty.</p>
        <Link
          to="/collection"
          className="inline-block mt-4 bg-black text-white px-6 py-2 rounded hover:bg-gray-800"
        >
          Continue Shopping
        </Link>
      </div>
    );
  }

  return (
    <div className="my-10">
      <Title text1={"YOUR"} text2={"CART"} />
      <div className="flex flex-col lg:flex-row gap-8 mt-6">
        <div className="flex-1">
          {cartItems.map((item) => (
            <div
              key={item.id}
              className="flex flex-col sm:flex-row items-center gap-4 border-b py-4"
            >
              <div className="w-24 h-24 flex-shrink-0">
                <img
                  src={item.images?.[0]?.img_url || "https://via.placeholder.com/100"}
                  alt={item.product_name}
                  className="w-full h-full object-cover rounded"
                />
              </div>
              <div className="flex-1">
                <h3 className="font-medium">{item.product_name}</h3>
                <p className="text-gray-500 text-sm">
                  {item.category_title} | {item.min_age}–{item.max_age} months
                </p>
                <p className="font-semibold mt-1">
                  {item.price} {currency}
                </p>
              </div>
              <div className="flex items-center gap-3">
                <button
                  onClick={() => updateQuantity(item.id, item.quantity - 1)}
                  className="border cursor-pointer px-3 py-1 rounded hover:bg-gray-100"
                >
                  -
                </button>
                <span className="w-8 text-center">{item.quantity}</span>
                <button
                  onClick={() => updateQuantity(item.id, item.quantity + 1)}
                  className="border cursor-pointer px-3 py-1 rounded hover:bg-gray-100"
                >
                  +
                </button>
                <button
                  onClick={() => removeFromCart(item.id)}
                  className="text-red-500 cursor-pointer ml-4 hover:text-red-700"
                >
                  Remove
                </button>
              </div>
            </div>
          ))}
        </div>
        <div className="lg:w-80 bg-gray-50 p-5 rounded-md h-fit">
          <h2 className="text-xl font-semibold">Cart Summary</h2>
          <div className="flex justify-between mt-4">
            <span>Subtotal</span>
            <span>{subtotal} {currency}</span>
          </div>
          <div className="flex justify-between mt-2">
            <span>Delivery Fee</span>
            <span>{delivery_fee} {currency}</span>
          </div>
          <hr className="my-3" />
          <div className="flex justify-between font-bold">
            <span>Total</span>
            <span>{total} {currency}</span>
          </div>
          <Link to="/place-order">
            <button className="w-full cursor-pointer mt-5 bg-black text-white py-2 rounded hover:bg-gray-800">
              Proceed to Checkout
            </button>
          </Link>
        </div>
      </div>
    </div>
  );
};

export default Cart;