// pages/CategoryProducts.jsx
import React, { useContext, useEffect, useState } from "react";
import { useParams, Link } from "react-router-dom";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";
import ProductItem from "../components/ProductItem";

const CategoryProducts = () => {
  const { slug } = useParams();
  const { api, categories } = useContext(AuthContext);
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState("");
  const [categoryTitle, setCategoryTitle] = useState("");

  // Find category title from context (for nice heading)
  useEffect(() => {
    if (categories.length && slug) {
      const found = categories.find(cat => cat.slug === slug);
      if (found) setCategoryTitle(found.title);
      else setCategoryTitle(slug);
    }
  }, [categories, slug]);

  useEffect(() => {
    const fetchProducts = async () => {
      if (!slug) return;
      setLoading(true);
      try {
        const res = await api.get(`/products/category/product/${slug}/`);
        setProducts(res.data);
        if (res.data.length === 0) setError("No products in this category.");
      } catch (err) {
        console.error(err);
        setError("Failed to load products.");
      } finally {
        setLoading(false);
      }
    };
    fetchProducts();
  }, [slug, api]);

  if (loading) return <div className="my-10 text-center">Loading products...</div>;
  if (error) return <div className="my-10 text-center text-red-500">{error}</div>;
  if (products.length === 0) return <div className="my-10 text-center">No products found.</div>;

  return (
    <div className="my-10">
      <div className="text-center py-8">
        <Title text1={categoryTitle} text2="Products" />
      </div>
      <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-4 lg:grid-cols-5 gap-4 gap-y-6">
        {products.map((product) => (
          <ProductItem
            key={product.id}
            id={product.id}
            name={product.product_name}
            price={product.price}
            image={product.images?.[0]?.img_url}
          />
        ))}
      </div>
      <div className="text-center mt-8">
        <Link to="/category" className="text-blue-600 hover:underline">
          ← Back to all categories
        </Link>
      </div>
    </div>
  );
};

export default CategoryProducts;