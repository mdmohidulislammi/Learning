import React, { useState } from "react";
import { NavLink, Link } from "react-router-dom";

import logo from "../assets/toyee_logo.png";
import user_icon from "../assets/user.png";
import menu_icon from "../assets/menu.png";
import search_icon from "../assets/search.png";
import cart_icon from "../assets/cart.png";

const Navbar = () => {
  const [visible, setVisible] = useState(false);

  return (
    <div className="flex items-center justify-between py-5 border-b">
      <NavLink to="/">
        <img src={logo} alt="Toyee" className="w-18 cursor-pointer" />
      </NavLink>

      <ul className="hidden sm:flex items-center gap-8 text-sm text-gray-700 font-medium">
        <NavLink
          to="/"
          className={({ isActive }) =>
            isActive
              ? "text-black border-b-2 border-black pb-1"
              : "hover:text-black"
          }
        >
          Home
        </NavLink>

        <NavLink
          to="/category"
          className={({ isActive }) =>
            isActive
              ? "text-black border-b-2 border-black pb-1"
              : "hover:text-black"
          }
        >
          Category
        </NavLink>

        <NavLink
          to="/contact"
          className={({ isActive }) =>
            isActive
              ? "text-black border-b-2 border-black pb-1"
              : "hover:text-black"
          }
        >
          Contact
        </NavLink>

        <NavLink
          to="/about"
          className={({ isActive }) =>
            isActive
              ? "text-black border-b-2 border-black pb-1"
              : "hover:text-black"
          }
        >
          About
        </NavLink>
      </ul>

     <div className="flex items-center border rounded-full px-3 py-2 w-[160px] sm:w-[220px] md:w-[300px]">
  <input
    type="text"
    placeholder="Search toys..."
    className="w-full outline-none text-sm"
  />

  <img
    src={search_icon}
    alt="Search"
    className="w-5 cursor-pointer"
  />
</div>

      <div className="flex items-center gap-5">
        <div className="group relative">
          <img src={user_icon} alt="User" className="w-7 cursor-pointer" />

          <div className="hidden group-hover:block absolute right-0 pt-4 z-10">
            <div className="flex flex-col gap-2 bg-white shadow-md rounded-lg py-3 px-5 text-sm text-gray-600 w-36">
              <NavLink to="/user-profile" className="hover:text-black">
                My Profile
              </NavLink>

              <NavLink to="/orders" className="hover:text-black">
                Orders
              </NavLink>

              <NavLink to="/" className="hover:text-black">
                Logout
              </NavLink>
            </div>
          </div>
        </div>

        <Link to="/cart" className="relative">
          <img src={cart_icon} alt="Cart" className="w-7" />

          <p className="absolute -right-2 -bottom-2 bg-black text-white text-[10px] w-5 h-5 rounded-full flex items-center justify-center">
            10
          </p>
        </Link>

        <img
          onClick={() => setVisible(true)}
          src={menu_icon}
          alt="Menu"
          className="w-6 cursor-pointer sm:hidden"
        />
      </div>

      <div
        className={`fixed top-0 right-0 bottom-0 bg-white transition-all duration-300 overflow-hidden z-20 ${
          visible ? "w-full" : "w-0"
        }`}
      >
        <div className="flex flex-col text-gray-700">
          <div
            onClick={() => setVisible(false)}
            className="flex items-center gap-3 p-5 border-b cursor-pointer text-lg"
          >
            ✖ Close
          </div>

          <NavLink
            onClick={() => setVisible(false)}
            to="/"
            className="py-4 pl-6 border-b hover:bg-gray-100"
          >
            Home
          </NavLink>

          <NavLink
            onClick={() => setVisible(false)}
            to="/category"
            className="py-4 pl-6 border-b hover:bg-gray-100"
          >
            Category
          </NavLink>

          <NavLink
            onClick={() => setVisible(false)}
            to="/contact"
            className="py-4 pl-6 border-b hover:bg-gray-100"
          >
            Contact
          </NavLink>

          <NavLink
            onClick={() => setVisible(false)}
            to="/about"
            className="py-4 pl-6 border-b hover:bg-gray-100"
          >
            About
          </NavLink>
        </div>
      </div>
    </div>
  );
};

export default Navbar;
