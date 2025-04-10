from ride import Ride, RideRequest, RideMatching
from users import Rider, Driver, RideSharing
from vehicle import Car, Bike, Cng

niye_jao = RideSharing("Niye Jao")
rahim = Rider("Rahim Uddin", "rahimuddin@gmail.com", 1234, "Uttara","Mohakhali",  1200)
niye_jao.add_rider(rahim)
kolim = Driver("Kolim Uddin", "kolimuddin@gmail.com", 12345, "Uttara")
niye_jao.add_drivers(kolim)
rahim.request_ride(niye_jao, "Mohakhali", "car")
# rahim.show_current_ride()
kolim.reach_destination(rahim.current_ride)
rahim.show_current_ride()
# print(niye_jao)