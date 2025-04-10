from abc import ABC


class Vehicle(ABC):
    speed = {'car': 50, 'bike': 70, 'cng': 40}

    def __init__(self, type, license, rate) -> None:
        self.type = type
        self.license = license
        self.rate = rate


class Car(Vehicle):
    def __init__(self, type, license, rate) -> None:
        super().__init__(type, license, rate)


class Bike(Vehicle):
    def __init__(self, type, license, rate) -> None:
        super().__init__(type, license, rate)


class Cng(Vehicle):
    def __init__(self, type, license, rate) -> None:
        super().__init__(type, license, rate)
