import React from "react";
import Title from '../components/Title'

const About = () => {
  return (
    <div className="my-10 max-w-4xl mx-auto px-4">
      <div className="text-center py-8">
        <Title text1={"ABOUT"} text2={"TOYEE"} />
        <p className="w-3/4 m-auto text-xs sm:text-sm md:text-base text-gray-600 mt-2">
          Safe, sustainable toys for little ones.
        </p>
      </div>

      <div className="bg-white p-6 rounded-lg shadow-md space-y-4 text-gray-700">
        <p>
          Toyee was started by parents who wanted safe, eco‑friendly toys for their own children.
          We carefully select every product – no toxic plastics, just BPA‑free materials and natural wood.
        </p>
        <p>
          All our toys are age‑appropriate for newborns up to 3 years old, helping develop motor skills,
          creativity, and curiosity.
        </p>
        
        {/* Developer Information */}
        <div className="border-t pt-4 mt-4">
          <h3 className="font-semibold text-lg text-blue-600">Developer Info</h3>
          <p className="text-sm mt-1">
            <strong>Name:</strong> MD. MOHIDUL ISLAM
          </p>
          <p className="text-sm">
            <strong>Role:</strong> Full‑Stack Developer
          </p>
          <p className="text-sm">
            <strong>Email:</strong> islamohidul856mi647360@gmail.com
          </p>
          <p className="text-sm">
            <strong>GitHub:</strong> https://github.com/mdmohidulislammi/
          </p>
        </div>

        <p className="font-semibold">Happy playing, happy parenting.</p>
      </div>
    </div>
  );
};

export default About;