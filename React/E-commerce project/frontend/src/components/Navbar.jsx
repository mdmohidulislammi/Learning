import React, { useState, useContext } from "react";
import { NavLink, Link, useNavigate } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";
import logo from "../assets/toyee_logo.png";
import user_icon from "../assets/user.png";
import menu_icon from "../assets/menu.png";
import search_icon from "../assets/search.png";
import cart_icon from "../assets/cart.png";

const Navbar = () => {
  const { user, logout, getCartCount } = useContext(AuthContext);
  const [visible, setVisible] = useState(false);
  const [searchTerm, setSearchTerm] = useState("");
  const navigate = useNavigate();
  const cartCount = getCartCount ? getCartCount() : 0;

  const performSearch = () => {
    if (searchTerm.trim() !== "") {
      navigate(`/collection?search=${encodeURIComponent(searchTerm.trim())}`);
      setSearchTerm(""); // clear input after search
    }
  };

  const handleSearchClick = () => {
    performSearch();
  };

  const handleKeyPress = (e) => {
    if (e.key === "Enter") {
      performSearch();
    }
  };

  const handleLogout = () => {
    logout();
    navigate("/");
  };

  return (
    <div className="flex items-center justify-between py-5 border-b">
      <NavLink to="/">
        <img src={logo} alt="Toyee" className="w-18 cursor-pointer" />
      </NavLink>

      <ul className="hidden sm:flex items-center gap-8 text-sm font-medium">
        <NavLink
          to="/"
          className={({ isActive }) =>
            `relative pb-1 transition-all duration-300 ease-out ${isActive ? "text-black after:scale-x-100" : "text-gray-700 hover:text-black after:scale-x-0 hover:after:scale-x-100"} after:absolute after:left-0 after:bottom-0 after:w-full after:h-0.5 after:bg-black after:transition-transform after:duration-300`
          }
        >
          Home
        </NavLink>
        <NavLink
          to="/category"
          className={({ isActive }) =>
            `relative pb-1 transition-all duration-300 ease-out ${isActive ? "text-black after:scale-x-100" : "text-gray-700 hover:text-black after:scale-x-0 hover:after:scale-x-100"} after:absolute after:left-0 after:bottom-0 after:w-full after:h-0.5 after:bg-black after:transition-transform after:duration-300`
          }
        >
          Category
        </NavLink>
        <NavLink
          to="/contact"
          className={({ isActive }) =>
            `relative pb-1 transition-all duration-300 ease-out ${isActive ? "text-black after:scale-x-100" : "text-gray-700 hover:text-black after:scale-x-0 hover:after:scale-x-100"} after:absolute after:left-0 after:bottom-0 after:w-full after:h-0.5 after:bg-black after:transition-transform after:duration-300`
          }
        >
          Contact
        </NavLink>
        <NavLink
          to="/about"
          className={({ isActive }) =>
            `relative pb-1 transition-all duration-300 ease-out ${isActive ? "text-black after:scale-x-100" : "text-gray-700 hover:text-black after:scale-x-0 hover:after:scale-x-100"} after:absolute after:left-0 after:bottom-0 after:w-full after:h-0.5 after:bg-black after:transition-transform after:duration-300`
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
          value={searchTerm}
          onChange={(e) => setSearchTerm(e.target.value)}
          onKeyPress={handleKeyPress}
        />
        <img
          src={search_icon}
          alt="Search"
          className="w-5 cursor-pointer"
          onClick={handleSearchClick}
        />
      </div>

      <div className="flex items-center gap-5">
        <div className="group relative">
          <img src={user_icon} alt="User" className="w-7 cursor-pointer" />
          <div className="hidden group-hover:block absolute right-0 pt-4 z-10">
            <div className="flex flex-col gap-2 bg-white shadow-md rounded-lg py-3 px-5 text-sm text-gray-600 w-36">
              {!user ? (
                <>
                  <NavLink to="/login" className="hover:text-black">
                    Login
                  </NavLink>
                  <NavLink to="/register" className="hover:text-black">
                    Register
                  </NavLink>
                </>
              ) : (
                <>
                  <NavLink to="/profile" className="hover:text-black">
                    My Profile
                  </NavLink>
                  <NavLink to="/orders" className="hover:text-black">
                    Orders
                  </NavLink>
                  {user.is_staff && (
                    <NavLink to="/admin/orders" className="hover:text-black">
                      Order Manage
                    </NavLink>
                  )}
                  {user.is_staff && (
                    <NavLink to="/admin" className="hover:text-black">
                      Admin
                    </NavLink>
                  )}
                  <button
                    onClick={handleLogout}
                    className="text-left hover:text-black w-full"
                  >
                    Logout
                  </button>
                </>
              )}
            </div>
          </div>
        </div>

        <Link to="/cart" className="relative">
          <img src={cart_icon} alt="Cart" className="w-7" />
          {cartCount > 0 && (
            <p className="absolute -right-2 -bottom-2 bg-black text-white text-[10px] w-5 h-5 rounded-full flex items-center justify-center">
              {cartCount}
            </p>
          )}
        </Link>

        <img
          onClick={() => setVisible(true)}
          src={menu_icon}
          alt="Menu"
          className="w-6 cursor-pointer sm:hidden"
        />
      </div>

      {/* Mobile menu (unchanged) */}
      <div
        className={`fixed top-0 right-0 bottom-0 bg-white transition-all duration-300 overflow-hidden z-20 ${visible ? "w-full" : "w-0"}`}
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
          {!user ? (
            <>
              <NavLink
                onClick={() => setVisible(false)}
                to="/login"
                className="py-4 pl-6 border-b hover:bg-gray-100"
              >
                Login
              </NavLink>
              <NavLink
                onClick={() => setVisible(false)}
                to="/register"
                className="py-4 pl-6 border-b hover:bg-gray-100"
              >
                Register
              </NavLink>
            </>
          ) : (
            <>
              <NavLink
                onClick={() => setVisible(false)}
                to="/profile"
                className="py-4 pl-6 border-b hover:bg-gray-100"
              >
                My Profile
              </NavLink>
              <NavLink
                onClick={() => setVisible(false)}
                to="/orders"
                className="py-4 pl-6 border-b hover:bg-gray-100"
              >
                Orders
              </NavLink>
              {user.is_staff && (
                <NavLink to="/admin/orders" className="hover:text-black">
                  Order Manage
                </NavLink>
              )}
              {user.is_staff && (
                <NavLink
                  onClick={() => setVisible(false)}
                  to="/admin"
                  className="py-4 pl-6 border-b hover:bg-gray-100"
                >
                  Admin
                </NavLink>
              )}
              <button
                onClick={() => {
                  handleLogout();
                  setVisible(false);
                }}
                className="py-4 pl-6 cursor-pointer border-b hover:bg-gray-100 text-left w-full"
              >
                Logout
              </button>
            </>
          )}
        </div>
      </div>
    </div>
  );
};

export default Navbar;
