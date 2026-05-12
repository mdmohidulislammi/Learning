import React, { useContext } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "./Title";
import ProductItem from "./ProductItem";

export const LatestCollection = () => {
  const { products } = useContext(AuthContext);
  const latestProducts = products?.slice(0, 10) || [];

  return (
    <div className="my-10">
      <div className="text-center py-8 text-3xl">
        <Title text1="LATEST" text2="COLLECTIONS" />
        <p className="w-3/4 m-auto text-xs sm:text-sm md:text-base text-gray-600">
          Sustainably crafted wooden toys and BPA-free products for parents who
          value safety and the environment. Bring joy to your little one with
          our thoughtfully curated baby toy collections – designed to inspire
          play, learning, and endless smiles.
        </p>
      </div>

      <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-4 lg:grid-cols-5 gap-4 gap-y-6">
        {latestProducts.map((item, index) => (
          <ProductItem
            key={item.name || index}
            id={index}
            name={item.name}
            price={item.price}
            description={item.description}
          />
        ))}
      </div>
    </div>
  );
};

export default LatestCollection;