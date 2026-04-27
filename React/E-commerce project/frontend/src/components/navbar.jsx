import React, { useState, useRef, useEffect } from "react";
import logo from "../assets/logo.png";
import searchIcon from "../assets/search-icons.png";
import profileIcon from "../assets/person.png";
import menuIcon from "../assets/main-menu.png";
import { NavLink } from "react-router-dom";

const Navbar = () => {
  const [visible, setVisible] = useState(false);      // mobile sidebar
  const [searchOpen, setSearchOpen] = useState(false); // search bar toggle
  const searchInputRef = useRef(null);

  const closeSidebar = () => setVisible(false);

  // Auto-focus search input when opened
  useEffect(() => {
    if (searchOpen && searchInputRef.current) {
      searchInputRef.current.focus();
    }
  }, [searchOpen]);

  // Close search on Escape key
  useEffect(() => {
    const handleEsc = (e) => {
      if (e.key === "Escape") setSearchOpen(false);
    };
    window.addEventListener("keydown", handleEsc);
    return () => window.removeEventListener("keydown", handleEsc);
  }, []);

  // Handle search form submit
  const handleSearch = (e) => {
    e.preventDefault();
    const query = e.target.search.value.trim();
    if (query) {
      console.log("Searching for:", query);
      // You can navigate or call an API here
      // e.g., navigate(`/search?q=${encodeURIComponent(query)}`);
      setSearchOpen(false);
    }
  };

  return (
    <nav className="flex items-center justify-between font-sans rounded-2xl px-4 py-2">
      {/* Logo */}
      <NavLink to="/" className="flex-shrink-0">
        <img src={logo} alt="Toyee" className="w-28 h-auto" />
      </NavLink>

      {/* Desktop Menu */}
      <ul className="hidden sm:flex items-center gap-8 text-sm font-semibold">
        {[
          { to: "/", label: "HOME" },
          { to: "/categories", label: "CATEGORIES" },
          { to: "/about", label: "ABOUT" },
          { to: "/contact", label: "CONTACT" },
        ].map((link) => (
          <li key={link.label}>
            <NavLink
              to={link.to}
              className={({ isActive }) =>
                `relative flex flex-col items-center gap-1 transition-colors duration-200 ${
                  isActive ? "text-blue-500" : "text-black hover:text-blue-500"
                }`
              }
            >
              {({ isActive }) => (
                <>
                  {link.label}
                  <span
                    className={`block h-0.5 w-2/3 rounded-full transition-all duration-300 ${
                      isActive ? "bg-blue-500 scale-100" : "bg-transparent scale-0"
                    }`}
                  />
                </>
              )}
            </NavLink>
          </li>
        ))}
      </ul>

      {/* Right Section */}
      <div className="flex items-center gap-4 sm:gap-6">
        {/* Search Section */}
        <div className="relative">
          {/* Search Icon (hidden when search is open) */}
          {!searchOpen && (
            <button
              onClick={() => setSearchOpen(true)}
              className="cursor-pointer p-1"
              aria-label="Search"
            >
              <img src={searchIcon} alt="search" className="w-8 h-auto" />
            </button>
          )}

          {/* Search Input Panel */}
          <div
            className={`absolute right-0 top-1/2 -translate-y-1/2 flex items-center bg-white shadow-lg rounded-lg ring-1 ring-gray-200 overflow-hidden transition-all duration-300 ${
              searchOpen
                ? "w-56 sm:w-72 opacity-100"
                : "w-0 opacity-0 pointer-events-none"
            }`}
          >
            <form onSubmit={handleSearch} className="flex items-center w-full">
              <input
                ref={searchInputRef}
                type="text"
                name="search"
                placeholder="Search toys..."
                className="w-full px-4 py-2 text-sm outline-none bg-transparent"
                autoComplete="off"
              />
              <button
                type="submit"
                className="p-2 text-gray-500 hover:text-blue-500 transition-colors"
                aria-label="Submit search"
              >
                <svg
                  xmlns="http://www.w3.org/2000/svg"
                  className="h-5 w-5"
                  fill="none"
                  viewBox="0 0 24 24"
                  stroke="currentColor"
                >
                  <path
                    strokeLinecap="round"
                    strokeLinejoin="round"
                    strokeWidth={2}
                    d="M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z"
                  />
                </svg>
              </button>
            </form>
            {/* Close button */}
            <button
              onClick={() => setSearchOpen(false)}
              className="p-2 text-gray-400 hover:text-gray-600 transition-colors"
              aria-label="Close search"
            >
              <svg
                xmlns="http://www.w3.org/2000/svg"
                className="h-5 w-5"
                viewBox="0 0 20 20"
                fill="currentColor"
              >
                <path
                  fillRule="evenodd"
                  d="M4.293 4.293a1 1 0 011.414 0L10 8.586l4.293-4.293a1 1 0 111.414 1.414L11.414 10l4.293 4.293a1 1 0 01-1.414 1.414L10 11.414l-4.293 4.293a1 1 0 01-1.414-1.414L8.586 10 4.293 5.707a1 1 0 010-1.414z"
                  clipRule="evenodd"
                />
              </svg>
            </button>
          </div>
        </div>

        {/* Profile Dropdown (unchanged) */}
        <div className="relative group">
          <button className="cursor-pointer p-1" aria-label="Profile menu">
            <img src={profileIcon} alt="profile" className="w-8 h-auto" />
          </button>
          <div className="absolute right-0 pt-3 opacity-0 invisible group-hover:opacity-100 group-hover:visible transition-all duration-200">
            <div className="flex flex-col gap-2 w-40 py-3 px-4 bg-white rounded-xl shadow-lg text-black ring-1 ring-gray-200">
              <NavLink to="/profile" className="text-sm font-medium hover:text-blue-500 transition-colors">Profile</NavLink>
              <NavLink to="/orders" className="text-sm font-medium hover:text-blue-500 transition-colors">Orders</NavLink>
              <NavLink to="/cart" className="text-sm font-medium hover:text-blue-500 transition-colors">Cart</NavLink>
              <NavLink to="/" className="text-sm font-medium hover:text-red-500 transition-colors">Logout</NavLink>
            </div>
          </div>
        </div>

        {/* Hamburger (mobile) */}
        <button
          onClick={() => setVisible(true)}
          className="sm:hidden cursor-pointer p-1"
          aria-label="Open menu"
          aria-expanded={visible}
          aria-controls="mobile-menu"
        >
          <img src={menuIcon} alt="Menu" className="w-8 h-auto" />
        </button>
      </div>

      {/* Sidebar overlay & panel (unchanged) */}
      {visible && (
        <div
          className="fixed inset-0 bg-black/40 backdrop-blur-sm z-40"
          onClick={closeSidebar}
        />
      )}
      <div
        id="mobile-menu"
        className={`fixed top-0 right-0 h-full w-72 bg-white z-50 shadow-2xl transform transition-transform duration-300 ease-in-out ${
          visible ? "translate-x-0" : "translate-x-full"
        }`}
      >
        <div className="flex justify-end p-4">
          <button
            onClick={closeSidebar}
            className="text-2xl font-light hover:text-blue-500 transition-colors"
            aria-label="Close menu"
          >
            ✕
          </button>
        </div>
        <ul className="flex flex-col gap-4 px-6 text-lg font-semibold">
          {[
            { to: "/", label: "HOME" },
            { to: "/categories", label: "CATEGORIES" },
            { to: "/about", label: "ABOUT" },
            { to: "/contact", label: "CONTACT" },
          ].map((link) => (
            <li key={link.label}>
              <NavLink
                to={link.to}
                onClick={closeSidebar}
                className={({ isActive }) =>
                  `block transition-colors duration-200 ${
                    isActive ? "text-blue-500" : "text-black hover:text-blue-500"
                  }`
                }
              >
                {link.label}
              </NavLink>
            </li>
          ))}
          <hr className="border-gray-200 my-2" />
          <NavLink to="/profile" onClick={closeSidebar} className="text-base font-medium hover:text-blue-500">Profile</NavLink>
          <NavLink to="/orders" onClick={closeSidebar} className="text-base font-medium hover:text-blue-500">Orders</NavLink>
          <NavLink to="/cart" onClick={closeSidebar} className="text-base font-medium hover:text-blue-500">Cart</NavLink>
        </ul>
      </div>
    </nav>
  );
};

export default Navbar;