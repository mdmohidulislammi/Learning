from abc import ABC, abstractmethod
from ride import RideRequest, RideMatching


class RideSharing:
    def __init__(self, company_name) -> None:
        self.company_name = company_name
        self.riders = []
        self.rides = []
        self.drivers = []

    def add_rider(self, rider):
        self.riders.append(rider)

    def add_drivers(self, driver):
        self.drivers.append(driver)

    def __str__(self):
        return f"Company Name: {self.company_name} with Riders: {len(self.riders)} and Drivers: {len(self.drivers)}"


class User(ABC):
    def __init__(self, name, email, nid) -> None:
        self.name = name
        self.email = email
        self.nid = nid
        self.wallet = 0

    @abstractmethod
    def dislplay_profile(self):
        raise NotImplementedError


class Rider(User):
    def __init__(self, name, email, nid, current_location,destination, initial_amount)-> None:
        super().__init__(name, email, nid)
        self.current_ride = None
        self.wallet = initial_amount
        self.current_location = current_location
        self.destination=destination

    def dislplay_profile(self):
        print(f"Rider : {self.name} and  Email: {self.email}")

    def load_cash(self, amount):
        if amount > 0:
            self.wallet += amount
        else:
            print("Amount less than 0.")

    def update_location(self, current_location):
        self.current_location = current_location

    def request_ride(self, ride_sharing, destination, vehicle):
        ride_request = RideRequest(self, destination)
        ride_matching = RideMatching(ride_sharing.drivers)
        ride = ride_matching.find_driver(ride_request, vehicle)
        ride.rider=self
        self.current_ride=ride
        print("\n------------------------------------ YAY !! You got a Ride -------------------------------------")

    def show_current_ride(self):
        print("--------------------Ride Details-------------------------")
        print(f"Rider: {self.name}")
        print(f"Driver: {self.current_ride.driver.name}")
        print(f"Selected Vehicle: {self.current_ride.vehicle.type}")
        print(f" Start Location: {self.current_ride.start_location}")
        print(f"End Location: {self.current_ride.end_location}")
        print(f"Total Cost: {self.current_ride.estimated_fare}")

class Driver(User):
    def __init__(self, name, email, nid, driver_location):
        super().__init__(name, email, nid)
        self.driver_location = driver_location
        self.wallet = 0

    def dislplay_profile(self):
        print(
            f"Driver Name: {self.name} and Driver location: {self.driver_location}")

    def accept_ride(self, ride):
        ride.start_ride()
        # driver object . ei self keyword ta driver class er object jeta name, email, nid, drive_location pass kore
        ride.set_driver(self)
    def reach_destination(self, ride):
        ride.end_ride()