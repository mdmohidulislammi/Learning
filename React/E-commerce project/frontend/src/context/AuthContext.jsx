import { createContext,useContext, useState } from "react";

 const AuthContext = createContext();
export {AuthContext};
const AuthContextProvider = (props) => {
  const currency = "BDT";
  const delivery_fee = 50;
  const products = [
    {
      name: "Rainbow Silicone Teether",
      category: "Teether",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description:
        "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toy",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 399.5,
      stock_quantity: 58,
      description:
        "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
    },
    {
      name: "Rainbow Silicone Teether",
      category: "Teether",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description:
        "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toy",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 399.5,
      stock_quantity: 58,
      description:
        "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
    },
    {
      name: "Rainbow Silicone Teether",
      category: "Teether",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description:
        "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toy",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 399.5,
      stock_quantity: 58,
      description:
        "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
    },
    {
      name: "Rainbow Silicone Teether",
      category: "Teether",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description:
        "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toy",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 399.5,
      stock_quantity: 58,
      description:
        "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
    },
    {
      name: "Rainbow Silicone Teether",
      category: "Teether",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description:
        "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toy",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 399.5,
      stock_quantity: 58,
      description:
        "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
    },
    {
      name: "Rainbow Silicone Teether",
      category: "Teether",
      age_range: "3–12 months",
      min_age_months: 3,
      max_age_months: 12,
      price: 999,
      stock_quantity: 145,
      description:
        "Easy-to-grip rainbow-shaped teether with textured surfaces to soothe sore gums. Dishwasher safe.",
    },
    {
      name: "Wooden Activity Cube",
      category: "Activity Toy",
      age_range: "12–36 months",
      min_age_months: 12,
      max_age_months: 36,
      price: 399.5,
      stock_quantity: 58,
      description:
        "5-sided cube with bead maze, shape sorter, spinning gears, and animal sliders. Develops motor skills.",
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
