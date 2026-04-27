import React from "react";
import { NavLink } from "react-router-dom";
import img1 from "../assets/1.png";

const Featured = () => {
  return (
    <div className="flex flex-col sm:flex-row border border-gray-300 rounded-xm shadow-2xl overflow-hidden bg-white">
      {/* Left Section */}
      <div className="w-full lg:w-1/2 flex items-center justify-center py-12 px-8">
        <div className="text-gray-800 max-w-md">
          {/* Title Line */}
          <div className="flex items-center gap-2 mb-3">
            <span className="w-8 md:w-11 h-[2px] bg-gray-500"></span>
            <NavLink to="/featured" className="hover:text-blue-600 transition-colors">
              <p className="font-bold text-sm md:text-base uppercase tracking-widest">
                Featured
              </p>
            </NavLink>
          </div>

          {/* Heading */}
          <NavLink to="/latest-product" className="hover:text-blue-600 transition-colors">
            <h1 className="text-3xl sm:text-4xl lg:text-5xl font-serif font-semibold leading-tight">
              Latest Products
            </h1>
          </NavLink>

          {/* Button */}
          <div className="mt-6">
            <NavLink to='/products' className='cursor-pointer'><button className="cursor-pointer text-xl font-bold text-black  py-3 px-5 rounded-md shadow-amber-600-3xl bg-amber-400 hover:bg-amber-500 transition-all">
              SHOP NOW
            </button></NavLink>
          </div>
        </div>
      </div>

      {/* Right Section */}
      <div className="w-full lg:w-1/2 flex items-center justify-center bg-gray-50">
        <img
          src={img1}
          className="w-3/4 sm:w-2/3 lg:w-1/2 object-contain"
          alt="Featured Product"
        />
      </div>
    </div>
  );
};

export default Featured;
