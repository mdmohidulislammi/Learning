import React, { useContext, useEffect, useState } from "react";
import { NavLink } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";

const Featured = () => {
  const { products, currency } = useContext(AuthContext);
  const [featuredProducts, setFeaturedProducts] = useState([]);
  const [current, setCurrent] = useState(0);
  useEffect(() => {
    if (products && products.length) {
      setFeaturedProducts(products.slice(0, 4));
    }
  }, [products]);

  // Auto‑rotate carousel
  useEffect(() => {
    if (featuredProducts.length === 0) return;
    const slider = setInterval(() => {
      setCurrent((prev) => (prev + 1) % featuredProducts.length);
    }, 3000);
    return () => clearInterval(slider);
  }, [featuredProducts]);

  if (featuredProducts.length === 0) {
    return (
      <div className="mt-6 rounded-3xl overflow-hidden bg-white border border-gray-200 shadow-xl p-12 text-center">
        <p className="text-gray-500">Loading featured products...</p>
      </div>
    );
  }

  const currentProduct = featuredProducts[current];
  const imageUrl = currentProduct.images?.[0]?.img_url || "/placeholder.jpg";

  return (
    <div className="mt-6 rounded-3xl overflow-hidden bg-white border border-gray-200 shadow-xl">
      <div className="flex flex-col-reverse sm:flex-row items-center justify-between px-6 sm:px-12 py-12">
        {/* Left side text */}
        <div className="w-full sm:w-1/2 text-center sm:text-left">
          <p className="text-gray-500 text-sm tracking-[6px] uppercase mb-4">
            Premium Toy Collection
          </p>
          <h1 className="text-4xl md:text-5xl lg:text-6xl font-bold text-black leading-tight">
            {currentProduct.product_name}
          </h1>
          <p className="text-gray-600 mt-6 text-sm sm:text-base leading-7 max-w-lg">
            {currentProduct.description?.substring(0, 140)}...
          </p>
          <div className="flex items-center gap-4 mt-4">
            <p className="text-2xl font-semibold">
              {currentProduct.price} {currency}
            </p>
            {currentProduct.stock > 0 && (
              <span className="text-green-600 text-sm">In Stock</span>
            )}
          </div>
          <div className="flex flex-col sm:flex-row items-center gap-4 mt-8">
            <NavLink to={`/product/${currentProduct.id}`}>
              <button className="bg-black hover:bg-gray-800 text-white font-semibold px-8 py-3 rounded-full transition duration-300 shadow-md cursor-pointer">
                Shop Now
              </button>
            </NavLink>
            <NavLink to="/collection">
              <button className="border border-black hover:bg-black hover:text-white text-black px-8 py-3 rounded-full transition duration-300 cursor-pointer">
                Explore More
              </button>
            </NavLink>
          </div>
        </div>

        {/* Right side image carousel */}
        <div className="w-full sm:w-1/2 flex justify-center mb-10 sm:mb-0">
          <div className="relative w-[260px] sm:w-[320px] lg:w-[400px] h-[260px] sm:h-[320px] lg:h-[400px] bg-gray-100 rounded-3xl overflow-hidden shadow-lg">
            <img
              src={imageUrl}
              alt={currentProduct.product_name}
              className="w-full h-full object-cover transition-all duration-700"
            />
            <div className="absolute bottom-5 left-1/2 -translate-x-1/2 flex gap-2">
              {featuredProducts.map((_, index) => (
                <div
                  key={index}
                  className={`h-2 rounded-full transition-all duration-300 ${
                    current === index ? "w-6 bg-black" : "w-2 bg-gray-400"
                  }`}
                ></div>
              ))}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Featured;