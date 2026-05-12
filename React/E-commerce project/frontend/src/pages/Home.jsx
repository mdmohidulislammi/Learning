import React from 'react'
import Featured from '../components/Featured'
import LatestCollection from '../components/LatestCollection'
import OurPolicy from '../components/OurPolicy'
import LittleBaby from '../components/LittleBaby'
export const Home = () => {
  return (
    <div>
      <Featured/>
      <LatestCollection/>
      <LittleBaby/>
      <OurPolicy/>
    </div>
  )
}
export default Home