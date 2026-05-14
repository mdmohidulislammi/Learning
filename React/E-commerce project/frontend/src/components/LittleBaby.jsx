import React, { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "./Title";
import ProductItem from "./ProductItem";

export const LittleBaby = () => {
  const { products } = useContext(AuthContext);
  const [newBorn, setNewBorn] = useState([]);

  useEffect(() => {
    if (!products || products.length === 0) return;
    // Filter products suitable for babies up to 24 months
    const filtered = products.filter(
      (item) => item.max_age <= 24
    );
    setNewBorn(filtered.slice(0, 5));
  }, [products]);

  return (
    <div className="my-10">
      <div className="text-center text-3xl py-8">
        <Title text1={"New"} text2={"Baby?"} />
        <p className="w-3/4 m-auto text-xs sm:text-sm md:text-base text-gray-600">
          Choose toys made of non-toxic, BPA-free materials.
        </p>
      </div>
      <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-4 lg:grid-cols-5 gap-4 gap-y-6">
        {newBorn.map((item) => (
          <ProductItem
            key={item.id}
            id={item.id}
            name={item.product_name}
            price={item.price}
            description={item.description}
            image={item.images?.[0]?.img_url}
          />
        ))}
      </div>
    </div>
  );
};

export default LittleBaby;