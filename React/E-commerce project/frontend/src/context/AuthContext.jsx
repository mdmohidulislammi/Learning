import { createContext, useContext, useState } from "react";

const AuthContext = createContext();
export { AuthContext };

const AuthContextProvider = (props) => {
  const currency = "BDT";
  const delivery_fee = 50;
  const products = [
    {
      name: "Rainbow Silicone Teether",
      category: "Teethers",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description: "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toys",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 3995,
      stock_quantity: 58,
      description: "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
    },
    {
      name: "Fluffy Bunny Stuffed Animal",
      category: "Stuffed Animals",
      age_range: "0–24 months",
      min_age_months: 0,
      max_age_months: 24,
      price: 1299,
      stock_quantity: 89,
      description: "Super soft hypoallergenic plush bunny, machine washable, perfect cuddle companion for newborns.",
    },
    {
      name: "Musical Xylophone",
      category: "Musical Toys",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 2499,
      stock_quantity: 34,
      description: "Colorful 8-note xylophone with mallet. Encourages rhythm and hand-eye coordination.",
    },
    {
      name: "Pull Along Duck",
      category: "Push & Pull Toys",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 1599,
      stock_quantity: 42,
      description: "Waddling wooden duck on wheels, makes gentle clicking sounds when pulled. Develops walking skills.",
    },
    {
      name: "Soft Doll – Lila",
      category: "Soft Dolls",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 1899,
      stock_quantity: 27,
      description: "Baby-safe cloth doll with embroidered face, removable onesie, and soft huggable body.",
    },
    {
      name: "Stacking Rings",
      category: "Activity Toys",
      age_range: "6–18 months",
      min_age_months: 6,
      max_age_months: 18,
      price: 799,
      stock_quantity: 112,
      description: "Classic rocking base stacking rings with different textures and colors. Teaches size sequencing.",
    },
    {
      name: "Teething Keys",
      category: "Teethers",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 599,
      stock_quantity: 203,
      description: "BPA-free silicone keys, easy to grasp, relieves gum pain, comes with storage case.",
    },
    {
      name: "Activity Walker",
      category: "Push & Pull Toys",
      age_range: "9–24 months",
      min_age_months: 9,
      max_age_months: 24,
      price: 4599,
      stock_quantity: 15,
      description: "Convertible walker with removable activity panel, lights, and sounds. Supports first steps.",
    },
    {
      name: "Panda Plush",
      category: "Stuffed Animals",
      age_range: "0–36 months",
      min_age_months: 0,
      max_age_months: 36,
      price: 1099,
      stock_quantity: 76,
      description: "Adorable 12-inch panda bear, made from recycled materials. Safe for all ages.",
    },
    {
      name: "Drum Set for Toddlers",
      category: "Musical Toys",
      age_range: "18–48 months",
      min_age_months: 18,
      max_age_months: 48,
      price: 3499,
      stock_quantity: 22,
      description: "Mini drum set with two drumsticks, tambourine, and maracas. Great for sensory play.",
    },
    {
      name: "Soft Doll – Ethan",
      category: "Soft Dolls",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 1899,
      stock_quantity: 31,
      description: "Machine-washable cloth doll, neutral outfit, perfect for nurturing play.",
    },
    {
      name: "Shape Sorter Truck",
      category: "Activity Toys",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 2199,
      stock_quantity: 46,
      description: "Wooden truck with shape sorting blocks. Helps with problem-solving and fine motor skills.",
    },
    {
      name: "Hedgehog Teether",
      category: "Teethers",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 699,
      stock_quantity: 178,
      description: "Soft silicone hedgehog teether with multiple textured surfaces for sore gums.",
    },
    {
      name: "Push Car",
      category: "Push & Pull Toys",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 1299,
      stock_quantity: 64,
      description: "Wooden push car with silent wheels, helps build gross motor skills.",
    },
    {
      name: "Elephant Musical Toy",
      category: "Musical Toys",
      age_range: "6–24 months",
      min_age_months: 6,
      max_age_months: 24,
      price: 1899,
      stock_quantity: 39,
      description: "Plush elephant that plays lullabies and glows softly. Batteries included.",
    },
  ];

  const value = {
    products,
    currency,
    delivery_fee,
  };

  return (
    <AuthContext.Provider value={value}>
      {props.children}
    </AuthContext.Provider>
  );
};

export default AuthContextProvider;