import React,{useContext} from 'react'
import { AuthContext } from '../context/AuthContext'
import { Link } from 'react-router-dom'
import img1 from '../assets/1.png'
import img4 from '../assets/4.png'
import img2 from '../assets/2.png'
import img3 from '../assets/3.png'
export const ProductItem = ({id, name,image, price, description}) => {
    const {currency}=useContext(AuthContext)
  return (
    <Link className='text-gray-700 cursor-pointer' to={`/product/${id}`}>
        <div className='overflow-hidden'>
            <img className='hover:scale-110 transition ease-in-out' src={img1} alt="" />

        </div>
        <p className='pt-3 pb-1 text-sm'>{name}</p>
        <p text-sm font-medium>{price} {currency}</p>
    </Link>
  )
}
export default ProductItem