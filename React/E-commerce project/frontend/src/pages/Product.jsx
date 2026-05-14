import React, { useContext, useEffect, useState } from "react";
import { useParams } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";
import RelatedProduct from "./RelatedProduct";

const PLACEHOLDER_IMG = "data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='200' height='200' viewBox='0 0 200 200'%3E%3Crect width='200' height='200' fill='%23f3f4f6'/%3E%3Ctext x='50%25' y='50%25' dominant-baseline='middle' text-anchor='middle' fill='%239ca3af' font-size='14'%3ENo image%3C/text%3E%3C/svg%3E";

export const Product = () => {
  const { productId } = useParams();
  const { products, currency, addToCart } = useContext(AuthContext);
  const [productData, setProductData] = useState(null);
  const [mainImage, setMainImage] = useState("");

  useEffect(() => {
    const found = products?.find((item) => item.id.toString() === productId);
    if (found) {
      setProductData(found);
      const firstImage = found.images?.[0]?.img_url || PLACEHOLDER_IMG;
      setMainImage(firstImage);
    } else {
      setProductData(null);
    }
  }, [productId, products]);

  if (!productData) {
    return (
      <div className="flex justify-center items-center h-64">
        <p className="text-gray-500">Loading product...</p>
      </div>
    );
  }

  const imageList = productData.images?.length
    ? productData.images.map(img => img.img_url)
    : [PLACEHOLDER_IMG];

  // Format age range
  const ageDisplay = productData.max_age
    ? `${productData.min_age} – ${productData.max_age} months`
    : `${productData.min_age}+ months`;

  return (
    <div className="border-t-2 pt-10 transition-opacity ease-in duration-500 opacity-100">
      <div className="flex gap-12 sm:gap-12 flex-col sm:flex-row">
        {/* Images section */}
        <div className="flex-1 flex flex-col-reverse gap-3 sm:flex-row">
          <div className="flex sm:flex-col overflow-x-auto sm:overflow-y-scroll justify-between sm:justify-normal gap-2 sm:gap-3">
            {imageList.map((imgUrl, idx) => (
              <img
                key={idx}
                onClick={() => setMainImage(imgUrl)}
                src={imgUrl}
                className="w-[24%] sm:w-full sm:mb-3 flex-shrink-0 cursor-pointer border-2 border-transparent hover:border-blue-500 rounded-md object-cover"
                alt={`Thumbnail ${idx + 1}`}
                onError={(e) => (e.target.src = PLACEHOLDER_IMG)}
              />
            ))}
          </div>
          <div className="w-full sm:w-[80%]">
            <img
              className="w-full h-auto rounded-lg"
              src={mainImage}
              alt={productData.product_name}
              onError={(e) => (e.target.src = PLACEHOLDER_IMG)}
            />
          </div>
        </div>

        {/* Product info */}
        <div className="flex-1">
          <h1 className="font-medium text-2xl mt-2">{productData.product_name}</h1>
          
          {/* Category and Age badges */}
          <div className="flex flex-wrap gap-2 mt-3">
            <span className="bg-gray-100 text-gray-700 text-xs px-3 py-1 rounded-full">
               {productData.category_title || "Uncategorized"}
            </span>
            <span className="bg-gray-100 text-gray-700 text-xs px-3 py-1 rounded-full">
               {ageDisplay}
            </span>
          </div>

          <div className="flex items-center gap-1 mt-2">
            <p className="text-green-600 font-medium">
              {productData.stock > 0 ? "In Stock ✅" : "Out of Stock ❌"}
            </p>
          </div>
          <p className="mt-5 text-3xl font-medium">
            {productData.price} {currency}
          </p>
          <p className="mt-5 text-gray-500 md:w-4/5">{productData.description}</p>
          <button
            onClick={() => addToCart(productData, 1)}
            disabled={productData.stock === 0}
            className="bg-black cursor-pointer text-white px-8 py-3 text-sm active:bg-gray-700 mt-4 hover:bg-gray-800 transition disabled:bg-gray-400 disabled:cursor-not-allowed"
          >
            ADD TO CART
          </button>
          <hr className="mt-8 sm:w-4/5" />
          <div className="text-sm text-gray-500 mt-5 flex flex-col gap-1">
            <p>✅ 100% original product.</p>
            <p>✅ Cash on delivery is available on this product.</p>
            <p>✅ Easy return and exchange policy within 7 days.</p>
          </div>
        </div>
      </div>

      <div className="mt-20">
        <div className="flex">
          <b className="border px-5 py-3 text-sm">Description</b>
        </div>
        <div className="flex flex-col gap-4 border px-6 py-6 text-sm text-gray-500">
          <p>{productData.description}</p>
        </div>
      </div>

      {/* Related products */}
      <RelatedProduct category={productData.category_title} currentProductId={productData.id} />
    </div>
  );
};

export default Product;