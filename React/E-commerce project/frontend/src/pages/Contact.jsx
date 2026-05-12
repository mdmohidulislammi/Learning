import React from "react";
import Title from "../components/Title";

const Contact = () => {
  return (
    <div className="my-10 max-w-4xl mx-auto px-4">
      <div className="text-center py-8">
        <Title text1={"CONTACT"} text2={"US"} />
        <p className="w-3/4 m-auto text-xs sm:text-sm md:text-base text-gray-600 mt-2">
          Have a question? We'd love to hear from you.
        </p>
      </div>

      <form className="space-y-5 bg-white p-6 rounded-lg shadow-md">
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">
            Your Name <span className="text-red-500">*</span>
          </label>
          <input 
            type="text" 
            required
            className="w-full border border-gray-300 rounded-md px-4 py-2" 
          />
        </div>

        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">
            Email Address <span className="text-red-500">*</span>
          </label>
          <input 
            type="email" 
            required
            className="w-full border border-gray-300 rounded-md px-4 py-2" 
          />
        </div>

        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">
            Your Message / Information <span className="text-red-500">*</span>
          </label>
          <textarea 
            rows="5" 
            required
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          ></textarea>
        </div>

        <button 
          type="submit"
          className="w-full cursor-pointer bg-blue-600 text-white py-2 rounded-md hover:bg-blue-700 transition"
        >
          Send Message
        </button>
      </form>
    </div>
  );
};

export default Contact;