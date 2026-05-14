// pages/Category.jsx
import React, { useContext } from "react";
import { Link } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";
import ProductItem from "../components/ProductItem";

const Category = () => {
  const { categories, products } = useContext(AuthContext);

  if (!categories || categories.length === 0) return null;

  // Build a map: category title -> array of products
  const productsByCategoryTitle = {};
  products.forEach((product) => {
    const catTitle = product.category_title;
    if (catTitle) {
      if (!productsByCategoryTitle[catTitle]) productsByCategoryTitle[catTitle] = [];
      productsByCategoryTitle[catTitle].push(product);
    }
  });

  // Filter categories that have at least one product
  const categoriesWithProducts = categories.filter(
    (cat) => productsByCategoryTitle[cat.title]?.length > 0
  );

  if (categoriesWithProducts.length === 0) return null;

  return (
    <div className="my-16">
      <div className="text-center mb-10">
        <Title text1="SHOP BY" text2="CATEGORY" />
        <p className="w-3/4 m-auto text-xs sm:text-sm md:text-base text-gray-600">
          Explore our collection by category – each with up to 10 featured products.
        </p>
      </div>

      {categoriesWithProducts.map((category) => {
        const catProducts = productsByCategoryTitle[category.title].slice(0, 10);
        return (
          <div key={category.id} className="mb-12">
            <div className="flex justify-between items-center mb-4 border-b pb-2">
              <h2 className="text-2xl font-semibold text-gray-800">
                {category.title}
              </h2>
              <Link
                to={`/category/${category.slug}`}
                className="text-sm text-blue-600 hover:underline"
              >
                See More →
              </Link>
            </div>
            <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-4 lg:grid-cols-5 gap-4 gap-y-6">
              {catProducts.map((product) => (
                <ProductItem
                  key={product.id}
                  id={product.id}
                  name={product.product_name}
                  price={product.price}
                  image={product.images?.[0]?.img_url}
                />
              ))}
            </div>
          </div>
        );
      })}
    </div>
  );
};

export default Category;