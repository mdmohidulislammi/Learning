import React, { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import dropdown_icon from "../assets/dropdown.png";
import Title from "../components/Title";
import ProductItem from "../components/ProductItem";
import img4 from "../assets/4.png";

export const Collection = () => {
  const { products } = useContext(AuthContext);
  const [showFilter, setShowFilter] = useState(false);
  const [filterProducts, setFilterProducts] = useState([]);
  const [category, setCategory] = useState([]);
  const [subCategory, setSubCategory] = useState([]);
  const [sortOption, setSortOption] = useState(""); // "low-high" or "high-low"

  const toggleCategory = (e) => {
    if (category.includes(e.target.value)) {
      setCategory(prev => prev.filter(item => item !== e.target.value));
    } else {
      setCategory((prev) => [...prev, e.target.value]);
    }
  };

  const toggleSubCategory = (e) => {
    if (subCategory.includes(e.target.value)) {
      setSubCategory(prev => prev.filter(item => item !== e.target.value));
    } else {
      setSubCategory(prev => [...prev, e.target.value]);
    }
  };

  const applyFilter = () => {
    if (!products) return;
    let productsCopy = products.slice();
    if (category.length > 0) {
      productsCopy = productsCopy.filter(item => category.includes(item.category));
    }

    if (subCategory.length > 0) {
      productsCopy = productsCopy.filter(item => {
        return subCategory.some(range => {
          let min = 0, max = 0;
          if (range === "3-12 months") { min = 3; max = 12; }
          else if (range === "12-36 months") { min = 12; max = 36; }
          else if (range === "4-10 years") { min = 48; max = 120; }
          return item.min_age_months <= max && item.max_age_months >= min;
        });
      });
    }
    if (sortOption === "low-high") {
      productsCopy.sort((a, b) => a.price - b.price);
    } else if (sortOption === "high-low") {
      productsCopy.sort((a, b) => b.price - a.price);
    }

    setFilterProducts(productsCopy);
  };
  useEffect(() => {
    applyFilter();
  }, [category, subCategory, sortOption, products]);

  return (
    <div className="flex flex-col sm:flex-row gap-1 sm:gap-10 pt-10 border-t">
      {/* filter */}
      <div className="min-w-60">
        <p
          onClick={() => setShowFilter(!showFilter)}
          className="my-2 text-xl flex items-center cursor-pointer gap-2"
        >
          FILTERS
          <img
            src={dropdown_icon}
            className={`h-3 sm:hidden ${showFilter ? "rotate-90" : ""}`}
            alt=""
          />
        </p>
        {/* category filters */}
        <div
          className={`border border-gray-300 pl-5 py-3 mt-6 ${showFilter ? "" : "hidden"}`}
        >
          <p className="mb-3 text-sm font-medium">CATEGORIES</p>
          <div className="flex flex-col gap-2 text-sm font-light text-gray-700">
            <p className="flex gap-2">
              <input
                type="checkbox"
                value={"Teethers"}
                className="w-3"
                onChange={toggleCategory}
              />
              Teethers
            </p>
            <p className="flex gap-2">
              <input
                type="checkbox"
                value={"Activity Toys"}
                className="w-3"
                onChange={toggleCategory}
              />
              Activity Toys
            </p>
            <p className="flex gap-2">
              <input
                type="checkbox"
                value={"Stuffed Animals"}
                className="w-3"
                onChange={toggleCategory}
              />
              Stuffed Animals
            </p>
            <p className="flex gap-2">
              <input
                type="checkbox"
                value={"Soft Dolls"}
                className="w-3"
                onChange={toggleCategory}
              />
              Soft Dolls
            </p>
            <p className="flex gap-2">
              <input
                type="checkbox"
                value={"Push & Pull Toys"}
                className="w-3"
                onChange={toggleCategory}
              />
              Push & Pull Toys
            </p>
            <p className="flex gap-2">
              <input
                type="checkbox"
                value={"Musical Toys"}
                className="w-3"
                onChange={toggleCategory}
              />
              Musical Toys
            </p>
          </div>
        </div>
        {/* sub-category */}
        <div
          className={`border border-gray-300 pl-5 py-3 mt-6 ${showFilter ? "" : "hidden"}`}
        >
          <p className="mb-3 text-sm font-medium">Age</p>
          <div className="flex flex-col gap-2 text-sm font-light text-gray-700">
            <p className="flex gap-2">
              <input type="checkbox" value={"3-12 months"} className="w-3" onChange={toggleSubCategory} />
              3-12 months
            </p>
            <p className="flex gap-2">
              <input type="checkbox" value={"12-36 months"} className="w-3" onChange={toggleSubCategory} />
              12-36 months
            </p>
            <p className="flex gap-2">
              <input type="checkbox" value={"4-10 years"} className="w-3" onChange={toggleSubCategory} />
              4-10 years
            </p>
          </div>
        </div>
      </div>
      {/* right side */}
      <div className="flex-1">
        <div className="flex justify-between text-base sm:text-2xl mb-4">
          <Title text1={"ALL"} text2={"COLLECTIONS"} />
          <select
            className="border-2 border-gray-300 text-sm px-2"
            onChange={(e) => setSortOption(e.target.value)}
            value={sortOption}
          >
            <option value="">Sort by: Price</option>
            <option value="low-high">Low to High</option>
            <option value="high-low">High to Low</option>
          </select>
        </div>
        {/* products */}
        <div className="grid grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-4 gap-y-6">
          {filterProducts.map((item, index) => (
            <ProductItem
              key={index}
              name={item.name}
              price={item.price}
              image={img4}
            />
          ))}
        </div>
      </div>
    </div>
  );
};

export default Collection;