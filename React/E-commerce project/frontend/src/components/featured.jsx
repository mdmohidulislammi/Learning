
import React from "react";
import { NavLink } from "react-router-dom";

const Featured= ()=>{

    return (
        <div className="border-gray-400 rounded-xl drop-shadow-xl/50 flex flex-col sm:flx-row">
          <div className="w-full lg:w-1/2 flex items-center justify-center py-10 bg-white">
        <div className="text-black px-8">
          <div className="flex items-center gap-2">
            <p className="w-8 md:w-11 h-[2px] bg-gray-500"></p>
            <NavLink to="/featured" className="hover:text-blue-500">
              <p className="font-bold text-sm md:text-base uppercase tracking-widest">
                Featured
              </p>
            </NavLink>
          </div>

          <NavLink to="/latest-product" className="hover:text-blue-500">
            <h1 className="text-3xl sm:text-4xl lg:text-5xl font-serif my-2">
              Latest Products
            </h1>
          </NavLink>

          <div className="mt-4">
            <button className="font-semibold text-white py-3 px-8 shadow-lg hover:bg-blue-600 transition-all rounded-sm bg-blue-500">
              SHOP NOW
            </button>
          </div>
        </div>
      </div>
      {/* right */}
      <div className="w-full lg:w-1/2 flex items-center justify-center py-10 bg-white">
        
      </div>
        </div>
    )
}
export default Featured