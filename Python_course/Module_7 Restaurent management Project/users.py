# Customer
# Employee
# Admin
from orders import Order
from abc import ABC
class User (ABC):
    def __init__(self, name, email, phone, address):
        self.name = name
        self.phone = phone
        self.email = email
        self.address = address


class Customer(User):
    def __init__(self, name, email, phone, address):
        super().__init__(name, email, phone, address)
        self.cart = Order()

    def view_menu(self, restaurent):
        restaurent.menu.show_Menu()

    def add_to_Cart(self, restaurent, item_name, quantity):
        item = restaurent.menu.find_item(item_name)
        if item:
            if int(item.quantity) < int(quantity):
                print("\n\n!! Item quantity exceeded !!")
            else:
                item.quantity = quantity
                self.cart.add_item(item)
                print("\n ! Item added successfully !")
        else:
            print("\nItem not found!!!.")
    def pay_Bill(self):
        print(f"Your Bill {self.cart.total_price()} taka paid successfully.\nThank You!")
        self.cart.clear()

    def view_cart(self):
        print("\n\n*****************  View Cart  ****************\n")
        print("Name \t\t\t Price \t\t\t Quantity")
        for item, quantity in self.cart.items.items():
            print(f"{item.name} \t\t\t {item.price} \t\t\t {quantity}")
        # f string use na koreo kora jabe tar jonno
        #  @property die etake variable e convert kora lagbe .
        print(f"\nTotal Price: {self.cart.total_price()}")
        
class Employee(User):
    def __init__(self, name, email, phone, address, age, designation, salary):
        super().__init__(name, email, phone, address)
        self.age = age
        self.designation = designation
        self.salary = salary

class Admin(User):
    def __init__(self, name, email, phone, address):
        super().__init__(name, email, phone, address)
        self.employees = []  # This is our database

    def add_employee(self, restaurent, employee):
        restaurent.add_employees(employee)

    def view_employee(self, restaurent):
        restaurent.view_employee()

    def add_new_item(self, restaurent, item):
        restaurent.menu.add_menuItem(item)

    def delete_item(self, restaurent, item):
        restaurent.remove_item(item)
    def view_menu(self, restaurent):
        restaurent.menu.show_Menu()










# # ad =Admin("Mohidul", "islamohidul@gmail.com","01518974449" "Dhaka")
# # ad.add_employee("Sagor", "sagor@gmail.com", "01792839838", "Dhaka",32, "Chef", 12000)
# mn = Menu()
# mamar_res = Restaurent("Vai vai vater restaurent.")
# item = food_Item("Pizza", 100, int(20))
# item2 = food_Item("Burger", 50, int(15))
# item3 = food_Item("Chicken", 50, int(15))
# item4 = food_Item("Beef", 50, int(30))
# item5 = food_Item("Fried", 50, int(30))
# admin1 = Admin("Md. Mohidul Islam", "islamohidul856mi@gmail.com",
#                "01518974449", "Dhaka")
# admin1.add_new_item(mamar_res, item)
# admin1.add_new_item(mamar_res, item2)
# admin1.add_new_item(mamar_res, item3)
# admin1.add_new_item(mamar_res, item4)
# admin1.add_new_item(mamar_res, item5)
# # mn.add_menuItem(item)
# # mn.show_Menu()
# customer1 = Customer("Islam", "islamohidul@gmail.com", "10100101", "Dhaka")
# customer1.view_menu(mamar_res)
# item_name = input("Enter item name: ")
# item_quantity = input("Enter item quantity: ")
# customer1.add_to_Cart(mamar_res, item_name, item_quantity)
# customer1.view_cart()
