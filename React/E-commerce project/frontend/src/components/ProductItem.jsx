import React, { useContext } from "react";
import { Link } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";

const PLACEHOLDER_IMG = "data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='200' height='200' viewBox='0 0 200 200'%3E%3Crect width='200' height='200' fill='%23f3f4f6'/%3E%3Ctext x='50%25' y='50%25' dominant-baseline='middle' text-anchor='middle' fill='%239ca3af' font-size='14'%3ENo image%3C/text%3E%3C/svg%3E";

const ProductItem = ({ id, name, price, image }) => {
  const { currency } = useContext(AuthContext);
  let imgSrc = image && image.trim() !== "" ? image : PLACEHOLDER_IMG;
  if (imgSrc.startsWith('/')) {
    imgSrc = `http://localhost:8000${imgSrc}`;
  }

  return (
    <Link to={`/product/${id}`} className="text-gray-700 cursor-pointer group">
      <div className="overflow-hidden rounded-lg bg-gray-100">
        <img
          className="w-full h-48 object-cover transition duration-300 group-hover:scale-110"
          src={imgSrc}
          alt={name || "Product"}
          loading="lazy"
          onError={(e) => (e.target.src = PLACEHOLDER_IMG)}
        />
      </div>
      <p className="pt-3 pb-1 text-sm font-medium text-gray-800">{name || "Unnamed Product"}</p>
      <p className="text-sm font-semibold text-gray-900">
        {typeof price === "number" ? price.toFixed(2) : price} {currency}
      </p>
    </Link>
  );
};

export default ProductItem;