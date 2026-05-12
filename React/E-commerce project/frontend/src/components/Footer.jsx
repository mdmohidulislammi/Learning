import React from "react";
import logo from "../assets/toyee_logo.png";
import { NavLink, Link } from "react-router-dom";
export const Footer = () => {
  return (
    <div className="flex flex-col sm:grid grid-cols-[3fr_1fr_1fr] gap-14 my-10 mt-20 text-sm">
      <div>
        <img src={logo} className="mb-2 w-32" alt="Logo" />
        <p className="w-full md:w-2/3 text-gray-600">
          From BPA-free teethers to wooden activity cubes, we handpick
          non-toxic, age-appropriate products for little ones aged 0–3 years.
          Give your child the gift of happy, healthy playtime, and give yourself
          peace of mind.
        </p>
      </div>
      <div>
        <p className="text-xl font-medium mb-5">Cypher</p>
        <ul className="flex flex-col gap-1 text-gray-600">
          <NavLink to="/">
            <li>Home</li>
          </NavLink>
          <Link to="https://www.linkedin.com/company/cypherbangladesh/">
            <li>About us</li>
          </Link>
          <NavLink to="/delivery">
            <li>Delivery</li>
          </NavLink>
          <NavLink to="/policy">
            <li>Privacy Policy</li>
          </NavLink>
        </ul>
      </div>
      <div>
        <p className="text-xl font-medium mb-5">GET IN TOUCH</p>
        <ul className="flex flex-col gap-2 text-gray-600">
          <li>+88-02-346-388</li>
          <li>contact@toyee.com</li>
          <li>IT Incubator,CUET</li>
        </ul>
      </div>
      <div>
        <hr />
        <p className="py-5 text-sm text-center">
          Cypyright 2026@ toyee.com - All Right Reserved
        </p>
      </div>
    </div>
  );
};
export default Footer;
