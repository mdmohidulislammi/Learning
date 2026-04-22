import React from "react"
import {Routes,Route} from 'react-router-dom'
import Home from "./pages/home.jsx"
import About from "./pages/about.jsx"
import Cart from "./pages/cart.jsx"
import Category from "./pages/category.jsx"
import Contact from "./pages/contact.jsx"
import Login from "./pages/login.jsx"
import Orders from "./pages/Orders.jsx"
import PlaceOrder from "./pages/placeOrder.jsx"
import Product from "./pages/product.jsx"
import Register from "./pages/register.jsx"
import Navbar from "./components/navbar.jsx"
const App=()=>{

  return (
    <div className="px-4 sm:px-[5w] lg:px-[9vw]">
      <Navbar/>
        <Routes>
          <Route path="/" element={<Home/>} />
          <Route path="/" element={<Category/>} />
          <Route path="/" element={<About/>} />
          <Route path="/" element={<Contact/>} />
          <Route path="/" element={<Product/>} />
          <Route path="/" element={<Cart/>} />
          <Route path="/" element={<Login/>} />
          <Route path="/" element={<Register/>} />
          <Route path="/" element={<PlaceOrder/>} />
          <Route path="/" element={<Orders/>} />
        </Routes>
    </div>
  )
}
export default App