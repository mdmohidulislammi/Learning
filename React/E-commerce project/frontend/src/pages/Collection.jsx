import React, { useContext, useEffect, useState } from "react";
import { useSearchParams } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";
import ProductItem from "../components/ProductItem";
import dropdown_icon from "../assets/dropdown.png";
import img4 from "../assets/4.png";

const Collection = () => {
  const { products, categories, currency } = useContext(AuthContext);
  const [searchParams, setSearchParams] = useSearchParams();
  const searchQuery = searchParams.get("search") || "";
  const categoryParam = searchParams.get("category") || "";

  const [showFilter, setShowFilter] = useState(false);
  const [filteredProducts, setFilteredProducts] = useState([]);
  const [selectedCategories, setSelectedCategories] = useState(categoryParam ? [categoryParam] : []);
  const [selectedAges, setSelectedAges] = useState([]);
  const [sortOption, setSortOption] = useState("");

  const ageRanges = [
    { label: "3-12 months", min: 3, max: 12 },
    { label: "12-36 months", min: 12, max: 36 },
    { label: "4-10 years", min: 48, max: 120 },
  ];

  const toggleCategory = (catTitle) => {
    setSelectedCategories(prev =>
      prev.includes(catTitle) ? prev.filter(c => c !== catTitle) : [...prev, catTitle]
    );
  };

  const toggleAge = (label) => {
    setSelectedAges(prev =>
      prev.includes(label) ? prev.filter(a => a !== label) : [...prev, label]
    );
  };

  useEffect(() => {
    if (!products.length) return;

    let result = [...products];

    // Search filter
    if (searchQuery) {
      result = result.filter(p =>
        p.product_name.toLowerCase().includes(searchQuery.toLowerCase()) ||
        p.description.toLowerCase().includes(searchQuery.toLowerCase())
      );
    }

    // Category filter – using category_title (string) from API
    if (selectedCategories.length) {
      result = result.filter(p => selectedCategories.includes(p.category_title));
    }

    // Age filter
    if (selectedAges.length) {
      result = result.filter(p => {
        return selectedAges.some(rangeLabel => {
          const range = ageRanges.find(r => r.label === rangeLabel);
          return range && p.min_age <= range.max && p.max_age >= range.min;
        });
      });
    }

    // Sort
    if (sortOption === "low-high") result.sort((a, b) => a.price - b.price);
    if (sortOption === "high-low") result.sort((a, b) => b.price - a.price);

    setFilteredProducts(result);
  }, [products, searchQuery, selectedCategories, selectedAges, sortOption]);

  
  useEffect(() => {
    if (selectedCategories.length === 1) {
      setSearchParams({ category: selectedCategories[0] });
    } else if (selectedCategories.length === 0 && categoryParam) {
      setSearchParams({});
    }
  }, [selectedCategories, setSearchParams, categoryParam]);

  const isSearchMode = searchQuery !== "";
  const pageTitle = isSearchMode ? `Search results for "${searchQuery}"` : "ALL COLLECTIONS";

  return (
    <div className="flex flex-col sm:flex-row gap-1 sm:gap-10 pt-10 border-t">
      {/* Filters sidebar */}
      <div className="min-w-60">
        <p onClick={() => setShowFilter(!showFilter)} className="my-2 text-xl flex items-center cursor-pointer gap-2">
          FILTERS
          <img src={dropdown_icon} className={`h-3 sm:hidden ${showFilter ? "rotate-90" : ""}`} alt="" />
        </p>
        <div className={`border border-gray-300 pl-5 py-3 mt-6 ${showFilter ? "" : "hidden"}`}>
          <p className="mb-3 text-sm font-medium">CATEGORIES</p>
          <div className="flex flex-col gap-2 text-sm font-light text-gray-700">
            {categories.map(cat => (
              <label key={cat.id} className="flex gap-2">
                <input type="checkbox" checked={selectedCategories.includes(cat.title)} onChange={() => toggleCategory(cat.title)} className="w-3 cursor-pointer" />
                {cat.title}
              </label>
            ))}
          </div>
        </div>
        <div className={`border border-gray-300 pl-5 py-3 mt-6 ${showFilter ? "" : "hidden"}`}>
          <p className="mb-3 text-sm font-medium">Age</p>
          <div className="flex flex-col gap-2 text-sm font-light text-gray-700">
            {ageRanges.map(range => (
              <label key={range.label} className="flex gap-2">
                <input type="checkbox" checked={selectedAges.includes(range.label)} onChange={() => toggleAge(range.label)} className="w-3 cursor-pointer" />
                {range.label}
              </label>
            ))}
          </div>
        </div>
      </div>

      {/* Product grid */}
      <div className="flex-1">
        <div className="flex justify-between text-base sm:text-2xl mb-4">
          <Title text1={pageTitle.split(" ")[0]} text2={pageTitle.split(" ").slice(1).join(" ")} />
          <select className="border-2 border-gray-300 text-sm px-2" onChange={(e) => setSortOption(e.target.value)} value={sortOption}>
            <option value="">Sort by: Price</option>
            <option value="low-high">Low to High</option>
            <option value="high-low">High to Low</option>
          </select>
        </div>
        <div className="grid grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-4 gap-y-6">
          {filteredProducts.length === 0 ? (
            <p className="col-span-full text-center text-gray-500 py-10">No products found.</p>
          ) : (
            filteredProducts.map((product) => (
              <ProductItem
                key={product.id}
                id={product.id}
                name={product.product_name}
                price={product.price}
                description={product.description}
                image={product.images?.[0]?.img_url || img4}
              />
            ))
          )}
        </div>
      </div>
    </div>
  );
};

export default Collection;