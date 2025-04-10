from menu import Menu

class Restaurent:
    def __init__(self, name):
        self.name = name
        self.employees = []
        self.menu = Menu()

    def add_employees(self, employee):
        self.employees.append(employee)

    def view_employee(self):
        print("\n\n----------------------------- !! Employee List !! ----------------------------------")
        for emp in self.employees:
            print(
                f"Employee Name: {emp.name}, Phone: {emp.phone},  Email: {emp.email},  Address: {emp.address}")