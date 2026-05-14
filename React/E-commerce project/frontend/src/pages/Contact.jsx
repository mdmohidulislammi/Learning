import React, { useState } from "react";
import Title from "../components/Title";
import axios from "axios";

const Contact = () => {
  const [formData, setFormData] = useState({
    name: "",
    email: "",
    message: "",
  });
  const [isSending, setIsSending] = useState(false);
  const [status, setStatus] = useState(null);
  const [errorMessage, setErrorMessage] = useState("");

  const handleChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setIsSending(true);
    setStatus(null);
    setErrorMessage("");

    try {
  const response = await axios.post("http://localhost:8000/api/contact/", formData, {
    headers: { "Content-Type": "application/json" },
  });
  console.log("Response:", response); 
  if (response.status === 200) {
    setStatus("success");
    setFormData({ name: "", email: "", message: "" });
  } else {
    setStatus("error");
    setErrorMessage(`Unexpected status: ${response.status}`);
  }
} 
catch (error) {
  console.error("Full error object:", error);
  if (error.response) {
    console.error("Error response data:", error.response.data);
    setErrorMessage(error.response.data?.error || `Server error: ${error.response.status}`);
  } else if (error.request) {
    setErrorMessage("No response from server – check CORS or backend running.");
  } else {
    setErrorMessage(error.message);
  }
  setStatus("error");
} 
  };

  return (
    <div className="my-10 max-w-4xl mx-auto px-4">
      <div className="text-center py-8">
        <Title text1={"CONTACT"} text2={"US"} />
        <p className="w-3/4 m-auto text-xs sm:text-sm md:text-base text-gray-600 mt-2">
          Have a question? We'd love to hear from you.
        </p>
      </div>

      <form onSubmit={handleSubmit} className="space-y-5 bg-white p-6 rounded-lg shadow-md">
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">
            Your Name <span className="text-red-500">*</span>
          </label>
          <input
            type="text"
            name="name"
            required
            value={formData.name}
            onChange={handleChange}
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
        </div>

        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">
            Email Address <span className="text-red-500">*</span>
          </label>
          <input
            type="email"
            name="email"
            required
            value={formData.email}
            onChange={handleChange}
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
        </div>

        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">
            Your Message / Information <span className="text-red-500">*</span>
          </label>
          <textarea
            name="message"
            rows="5"
            required
            value={formData.message}
            onChange={handleChange}
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
        </div>

        <button
          type="submit"
          disabled={isSending}
          className="w-full cursor-pointer bg-blue-600 text-white py-2 rounded-md hover:bg-blue-700 transition disabled:bg-gray-400"
        >
          {isSending ? "Sending..." : "Send Message"}
        </button>

        {status === "success" && (
          <p className="text-green-600 text-sm text-center mt-2">
            ✅ Your message has been sent. We'll get back to you soon!
          </p>
        )}
        {status === "error" && (
          <p className="text-red-600 text-sm text-center mt-2">
            ❌ {errorMessage}
          </p>
        )}
      </form>
    </div>
  );
};

export default Contact;