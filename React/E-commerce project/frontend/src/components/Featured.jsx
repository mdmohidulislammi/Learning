import React, { useEffect, useState } from "react";
import { NavLink } from "react-router-dom";

import img1 from "../assets/1.png";
import img2 from "../assets/2.png";
import img3 from "../assets/3.png";
import img4 from "../assets/4.png";

const Featured = () => {

  const products = [img1, img2, img3, img4];

  const [current, setCurrent] = useState(0);

  useEffect(() => {
    const slider = setInterval(() => {
      setCurrent((prev) => (prev + 1) % products.length);
    }, 3000);

    return () => clearInterval(slider);
  }, []);

  return (
    <div className="mt-6 rounded-3xl overflow-hidden bg-white border border-gray-200 shadow-xl">

      <div className="flex flex-col-reverse sm:flex-row items-center justify-between px-6 sm:px-12 py-12">

        <div className="w-full sm:w-1/2 text-center sm:text-left">

          <p className="text-gray-500 text-sm tracking-[6px] uppercase mb-4">
            Premium Toy Collection
          </p>

          <h1 className="text-4xl md:text-5xl lg:text-6xl font-bold text-black leading-tight">
            Discover The
            <span className="block text-amber-500 mt-2">
              Magic Of Toys
            </span>
          </h1>

          <p className="text-gray-600 mt-6 text-sm sm:text-base leading-7 max-w-lg">
            Explore a modern collection of fun, creative, and high-quality toys
            designed to bring happiness and creativity to every child.
          </p>

          <div className="flex flex-col sm:flex-row items-center gap-4 mt-8">

            <NavLink to="/collection">
              <button className="bg-black hover:bg-gray-800 text-white font-semibold px-8 py-3 rounded-full transition duration-300 shadow-md cursor-pointer">
                Shop Now
              </button>
            </NavLink>

            <NavLink to="/category">
              <button className="border border-black hover:bg-black hover:text-white text-black px-8 py-3 rounded-full transition duration-300 cursor-pointer">
                Explore More
              </button>
            </NavLink>

          </div>

        </div>

        <div className="w-full sm:w-1/2 flex justify-center mb-10 sm:mb-0">

          <div className="relative w-[260px] sm:w-[320px] lg:w-[400px] h-[260px] sm:h-[320px] lg:h-[400px] bg-gray-100 rounded-3xl overflow-hidden shadow-lg">

            <img
              src={products[current]}
              alt="Featured Product"
              className="w-full h-full object-cover transition-all duration-700"
            />

            <div className="absolute bottom-5 left-1/2 -translate-x-1/2 flex gap-2">
              {products.map((_, index) => (
                <div
                  key={index}
                  className={`h-2 rounded-full transition-all duration-300 ${
                    current === index
                      ? "w-6 bg-black"
                      : "w-2 bg-gray-400"
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