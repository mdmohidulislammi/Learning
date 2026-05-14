// components/AddProduct.jsx
import React, { useState } from "react";

const AddProduct = ({ initialData, categories, onSubmit, onCancel, isEditing }) => {
  const [formData, setFormData] = useState({
    product_name: initialData?.product_name || "",
    category: initialData?.category?.id?.toString() || "",
    description: initialData?.description || "",
    price: initialData?.price || "",
    stock: initialData?.stock || "",
    min_age: initialData?.min_age || "",
    max_age: initialData?.max_age || "",
  });
  const [isAvailable, setIsAvailable] = useState(initialData?.is_available ?? true);
  const [imageFiles, setImageFiles] = useState([]);
  const [imagePreviews, setImagePreviews] = useState(initialData?.images?.map(img => img.img_url) || []);
  const [message, setMessage] = useState({ type: "", text: "" });

  const handleInputChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
    setMessage({ type: "", text: "" });
  };

  const handleImageChange = (e) => {
    const files = Array.from(e.target.files);
    setImageFiles(files);
    setImagePreviews(files.map(f => URL.createObjectURL(f)));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setMessage({ type: "", text: "" });

    if (!formData.category) {
      setMessage({ type: "error", text: "Please select a category." });
      return;
    }

    const data = new FormData();
    data.append("product_name", formData.product_name);
    data.append("category", parseInt(formData.category, 10));
    data.append("description", formData.description);
    data.append("price", parseFloat(formData.price));
    data.append("stock", parseInt(formData.stock, 10));
    data.append("min_age", parseInt(formData.min_age, 10));
    if (formData.max_age) data.append("max_age", parseInt(formData.max_age, 10));
    data.append("is_available", isAvailable ? "true" : "false");
    imageFiles.forEach(file => data.append("images", file));

    try {
      await onSubmit(data);
    } catch (err) {
      let errorMsg = "Failed to save product.";
      if (err.response?.data) {
        const first = Object.values(err.response.data)[0];
        errorMsg = Array.isArray(first) ? first[0] : first;
      }
      setMessage({ type: "error", text: errorMsg });
    }
  };

  return (
    <div className="bg-white rounded-lg max-w-2xl w-full max-h-[90vh] overflow-y-auto p-6">
      <h2 className="text-xl font-bold mb-4">{isEditing ? "Edit Product" : "Add New Product"}</h2>
      {message.text && <div className={`mb-4 p-3 rounded-md ${message.type === "error" ? "bg-red-100 text-red-700" : "bg-green-100 text-green-700"}`}>{message.text}</div>}
      <form onSubmit={handleSubmit}>
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          {/* ... same fields as before ... */}
          <div>
            <label className="block text-sm font-medium">Product Name *</label>
            <input type="text" name="product_name" value={formData.product_name} onChange={handleInputChange} required className="w-full border rounded-md px-3 py-2 mt-1" />
          </div>
          <div>
            <label className="block text-sm font-medium">Category *</label>
            <select name="category" value={formData.category} onChange={handleInputChange} required className="w-full border rounded-md px-3 py-2 mt-1">
              <option value="">Select</option>
              {categories.map(cat => <option key={cat.id} value={cat.id}>{cat.title}</option>)}
            </select>
          </div>
          <div>
            <label className="block text-sm font-medium">Price (BDT) *</label>
            <input type="number" step="0.01" name="price" value={formData.price} onChange={handleInputChange} required className="w-full border rounded-md px-3 py-2 mt-1" />
          </div>
          <div>
            <label className="block text-sm font-medium">Stock *</label>
            <input type="number" step="1" name="stock" value={formData.stock} onChange={handleInputChange} required className="w-full border rounded-md px-3 py-2 mt-1" />
          </div>
          <div>
            <label className="block text-sm font-medium">Min Age (months) *</label>
            <input type="number" step="1" name="min_age" value={formData.min_age} onChange={handleInputChange} required className="w-full border rounded-md px-3 py-2 mt-1" />
          </div>
          <div>
            <label className="block text-sm font-medium">Max Age (months)</label>
            <input type="number" step="1" name="max_age" value={formData.max_age} onChange={handleInputChange} className="w-full border rounded-md px-3 py-2 mt-1" />
          </div>
          <div className="md:col-span-2">
            <label className="block text-sm font-medium">Description *</label>
            <textarea name="description" value={formData.description} onChange={handleInputChange} rows="3" required className="w-full border rounded-md px-3 py-2 mt-1" />
          </div>
          <div className="md:col-span-2">
            <label className="block text-sm font-medium">Available?</label>
            <input type="checkbox" checked={isAvailable} onChange={(e) => setIsAvailable(e.target.checked)} className="mt-2 w-5 h-5" />
          </div>
          <div className="md:col-span-2">
            <label className="block text-sm font-medium">Product Images</label>
            <input type="file" multiple accept="image/*" onChange={handleImageChange} className="w-full border rounded-md px-3 py-2 mt-1" />
            {imagePreviews.length > 0 && (
              <div className="flex gap-2 mt-2 flex-wrap">
                {imagePreviews.map((src, idx) => <img key={idx} src={src} alt="preview" className="w-16 h-16 object-cover rounded border" />)}
              </div>
            )}
          </div>
        </div>
        <div className="flex justify-end gap-3 mt-6">
          <button type="button" onClick={onCancel} className="px-4 py-2 border rounded-md hover:bg-gray-100">Cancel</button>
          <button type="submit" className="px-4 py-2 bg-blue-600 text-white rounded-md hover:bg-blue-700">{isEditing ? "Update" : "Create"} Product</button>
        </div>
      </form>
    </div>
  );
};

export default AddProduct;