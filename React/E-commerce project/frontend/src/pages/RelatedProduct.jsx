// RelatedProduct.jsx
import React, { useContext, useEffect, useState } from 'react';
import { AuthContext } from '../context/AuthContext';
import Title from '../components/Title';
import ProductItem from '../components/ProductItem';

const RelatedProduct = ({ category, currentProductId }) => {
  const { products } = useContext(AuthContext);
  const [related, setRelated] = useState([]);

  useEffect(() => {
    if (!products || products.length === 0 || !category) {
      setRelated([]);
      return;
    }

  
    const categoryTitle = typeof category === 'string' ? category : category?.title;
    if (!categoryTitle) {
      setRelated([]);
      return;
    }
    let filtered = products.filter(item => item.category_title === categoryTitle);
    if (currentProductId) {
      filtered = filtered.filter(item => item.id !== currentProductId);
    }
    setRelated(filtered.slice(0, 5));
  }, [category, products, currentProductId]);

  if (related.length === 0) return null;

  return (
    <div className='my-24'>
      <div className='text-center text-3xl py-2'>
        <Title text1={'RELATED'} text2={'PRODUCTS'} />
      </div>
      <div className='grid grid-cols-2 sm:grid-cols-3 md:grid-cols-4 gap-4 gap-y-6'>
        {related.map((item) => (
          <ProductItem
            key={item.id}
            id={item.id}
            name={item.product_name}
            price={item.price}
            image={item.images?.[0]?.img_url}
          />
        ))}
      </div>
    </div>
  );
};

export default RelatedProduct;