from datetime import datetime
from vehicle import Car, Bike, Cng


class Ride:
    def __init__(self, start_location, end_location, vehicle):
        self.start_location = start_location
        self.end_location = end_location
        self.driver = None
        self.rider = None
        self.start_time = None
        self.end_time = None
        self.estimated_fare = self.calculate_fare(vehicle.type)
        self.vehicle = vehicle

    def set_driver(self, driver):
        self.driver = driver

    def start_ride(self):
        self.start_time = datetime.now()

    def end_ride(self):
        self.end_ride = datetime.now()
        self.rider.wallet -= self.estimated_fare
        self.driver.wallet += self.estimated_fare
    def calculate_fare(self, vehicle):
        distance=10
        fare_per_km={'car': 30, 'bike': 40, 'cng': 30}
        return int(distance) * int(fare_per_km.get(vehicle))

    def __repr__(self):
        return f"Ride details : Started - {self.start_location} to {self.end_location} ."


class RideRequest:
    def __init__(self, rider, end_location) -> None:
        self.rider = rider
        self.end_location = end_location


class RideMatching:
    def __init__(self, drivers) -> None:
        self.avaiable_drivers = drivers

    def find_driver(self, ride_request, vehicle):
        if len(self.avaiable_drivers) > 0:
            print("Looking for drivers....")
            driver = self.avaiable_drivers[0]
            if vehicle == 'car':
                vehic = Car('car', "ABC123", 50)
            elif vehicle == 'bike':
                vehic = Bike('bike', "ABC3345", 30)
            elif vehicle == 'cng':
                vehic = Cng('cng', "dkjfdl3947", 40)
            ride = Ride(ride_request.rider.current_location,
                        ride_request.rider.destination, vehic)
            driver.accept_ride(ride)
            return ride
