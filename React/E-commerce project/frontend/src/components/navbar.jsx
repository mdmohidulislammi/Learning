
import React, {useState} from "react";
import logo from '../assets/logo.png'
import searchIcon from '../assets/search-icons.png'
import profileIcon from '../assets/person.png'
import menu from '../assets/main-menu.png'
import { NavLink } from "react-router-dom";

const Navbar= ()=>{
    const [visible, setVisible]=useState(false)
    return (
        <div className="flex items-center justify-between  font-sans rounded-2xl">
          <NavLink to='/'><img src={logo} alt="Toyee" className="w-30"/></NavLink>
          
          <ul className="hidden sm:flex gap-8 text-sm text-black font-semibold">
            <NavLink to='/' className='flex flex-col items-center gap-2'>HOME
            <hr className="w-2/4 border-none h-[1.5px] bg-blue-400 hidden" />
            </NavLink>
            <NavLink to='/categories' className='flex flex-col items-center gap-2'>CATEGORIES
            <hr className="w-2/4 border-none h-[1.5px] bg-blue-400 hidden" />
            </NavLink>
            <NavLink to='/about' className='flex flex-col items-center gap-2'>ABOUT
            <hr className="w-2/4 border-none h-[1.5px] bg-blue-400 hidden" />
            </NavLink>
            <NavLink to='/contact' className='flex flex-col items-center gap-2'>CONTACT
            <hr className="w-2/4 border-none h-[1.5px] bg-blue-400 hidden" />
            </NavLink>
          </ul>
          <div className="flex items-center gap-6">
             <img className="w-10 cursor-pointer" src={searchIcon} alt="search" />
             <div className="group relative">
              <img src={profileIcon} className="w-10 cursor-pointer" alt="profile" />
              <div className="group-hover:block hidden absolute dropdown-menu right-0 pt-4">
                <div className="flex flex-col gap-2 2-36 py-2 px-4 rounded-xl bg-slate-100 text-black">
                  <NavLink to='/profile'><p className="cursor-pointer hover:text-gray-500 font-semibold">Profile</p></NavLink>               
                  <NavLink to='/orders'><p className="cursor-pointer hover:text-gray-500 font-semibold">Orders</p></NavLink>               
                  <NavLink to='/cart'><p className="cursor-pointer hover:text-gray-500 font-semibold">Cart</p></NavLink>               
                  <NavLink to='/'><p className="cursor-pointer hover:text-gray-500 font-semibold">Logout</p></NavLink>               
                </div>               
              </div>
             </div>
              <img onClick={()=>setVisible(true)}  src={menu} className="w-10 cursor-pointer sm:hidden" alt="Menu" />
              {/* sidebar menu for mobile/small screen */}
              <div
                className={`fixed top-0 right-0 bottom-0 w-64 bg-white shadow-lg transform transition-transform duration-300 ${
                  visible ? "translate-x-0" : "translate-x-full"
                }`}>
                {/* Close Button */}
                <div className="flex justify-end p-4">
                  <button onClick={() => setVisible(false)} className="text-xl font-bold cursor-pointer"> ✕ </button>
                </div>

                {/* Menu Links */}
                <ul className="flex flex-col gap-6 px-6 text-black font-semibold">
                  <NavLink to='/' onClick={() => setVisible(false)} className="hover:text-blue-500">HOME</NavLink>
                  <NavLink to='/categories' onClick={() => setVisible(false)} className="hover:text-blue-500">CATEGORIES</NavLink>
                  <NavLink to='/about' onClick={() => setVisible(false)} className="hover:text-blue-500">ABOUT</NavLink>
                  <NavLink to='/contact' onClick={() => setVisible(false)} className="hover:text-blue-500">CONTACT</NavLink>
                
                </ul>
              </div>
          </div>
        </div>
    )
}
export default Navbar 