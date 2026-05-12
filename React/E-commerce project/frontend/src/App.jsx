import { BrowserRouter, Routes, Route } from 'react-router-dom';

import AuthContextProvider from './context/AuthContext';
import Navbar from './components/Navbar';

import Home from './pages/Home';
import About from './pages/About';
import Collection from './pages/Collection';
import Contact from './pages/Contact';
import Login from './pages/Login';
import Register from './pages/Register';
import Cart from './pages/Cart';
import Product from './pages/Product';
import PlaceOrder from './pages/PlaceOrder';
import Order from './pages/Order';
import Footer from './components/Footer';

function App() {
  return (
    <BrowserRouter>     
          <div className='px-4 sm:px-[5vw] md:px-[7vw] lg:px-[9vw]'>
            <Navbar />
            <Routes>
              <Route path='/' element={<Home />} />
              <Route path='/collection' element={<Collection />} />
              <Route path='/about' element={<About />} />
              <Route path='/contact' element={<Contact />} />
              <Route path='/product/:productId' element={<Product />} />
              <Route path='/cart' element={<Cart />} />
              <Route path='/login' element={<Login />} />
              <Route path='/register' element={<Register />} />
              <Route path='/place-order' element={<PlaceOrder />} />  
              <Route path='/orders' element={<Order />} />
            </Routes>
            <Footer/>
          </div>
     
    </BrowserRouter>
  );
}

export default App;