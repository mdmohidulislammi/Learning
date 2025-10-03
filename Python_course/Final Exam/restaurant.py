class User:
    def __init__(self, name, id, email, password):
        self.name = name
        self.__id = id
        self.email = email
        self.__password = password

    def customer_list(self):
        print(
            f"Name : {self.name}  ID : {self.__id}  Email : {self.email}  Password : {self.__password}"
        )

    # def find_customer(self, id, password):
    #     find = False
    #     if self.__id == id and self.__password==password:
    #         print("-------------------Thanks for choosing us -------------------------")
    #         find = True
    #     if find:
    #         print("--------------Customer Information is not Available --------------")

    def admin_password(self):
        return self.__password

    def customer_id(self):
        return self.__id

    def customer_password(self):
        return self.__password


class Admin(User):
    def __init__(self, name, id, email, password):
        super().__init__(name, id, email, password)
        self.customers = []

    def add_customer(self, name, id, email, password, address):
        customer = Customer(name, id, email, password, address)
        self.customers.append(customer)

    def view_customer(self):
        for customer in self.customers:
            customer.customer_list()

    # def find_customer(self, id, password):
    #     for customer in self.customers:
    #         customer.find_customer(id, password)

    def remove_customers(self, name):
        for customer in self.customers:
            if customer.name.lower() in name.lower():
                self.customers.remove(customer)

    def add_items(self, restaurant, name, price, quantity):
        restaurant.add_items(name, price, quantity)

    def remove_items(self, restaurant, item_name):
        restaurant.remove_items(item_name)

    def decrease_quantity(self, reastaurant, item_name, quantity):
        reastaurant.decrease_quantity(item_name, quantity)

    def increase_quantity(self, restaurant, item_name, quantity):
        restaurant.increase_quantity(item_name, quantity)

    def view_items(self, restaurant):
        return restaurant.view_items()

    def update_price(self, restaurant, item_name, price):
        restaurant.update_price(item_name, price)

    def admin_password(self):
        return super().admin_password()


class Customer(User):
    def __init__(self, name, id, email, password, address):
        super().__init__(name, id, email, password)
        self.address = address
        self.cart = []
        self.__balance = 0
        self.total_price = 0

    def customer_list(self):
        return super().customer_list()

    def add_balance(self, amount):
        self.__balance += amount

    def check_balance(self):
        print(f"Your Balance is :  {self.__balance} Taka ")

    def add_to_cart(self, restaurant, item_name, quantity):
        for item in restaurant.items:
            if item.name.lower() in item_name.lower():
                if item.quantity < quantity:
                    print("Not available this quantity.")
                else:
                    restaurant.decrease_quantity(item_name, quantity)
                    customer_item = Items(item.name, item.price, quantity)
                    self.cart.append(customer_item)

    def view_cart(self):
        for item in self.cart:
            print(
                f"Item Name : {item.name}  Item Price : {item.price}   Item Quantity : {item.quantity}"
            )
            self.total_price += int(item.price * item.quantity)
        print(
            f"----------------Total Price =  {self.total_price} Taka ----------------------"
        )

    def pay(self):
        if self.total_price > self.__balance:
            print(
                f"Insufficient Balance .You need to add {self.total_price-self.__balance} Taka."
            )
        else:
            print("!! Congratulations !!")
            self.cart.clear()
            self.__balance-=self.total_price
            self.total_price=0

    # def find_customer(self, id, password):
    #     super().find_customer(id, password)


class Restaurant:
    def __init__(self):
        self.items = []

    def customer_list(self, admin):
        return admin.view_customer()

    def add_items(self, name, price, quantity):
        item = Items(name, price, quantity)
        self.items.append(item)

    def view_items(self):
        for item in self.items:
            print(
                f"Item Name : {item.name}           Price : {item.price} Taka         Quantity : {item.quantity}"
            )

    def remove_items(self, item_name):
        for item in self.items:
            if item.name.lower() in item_name.lower():
                self.items.remove(item)
                print("Remove successfully.")

    def update_price(self, item_name, price):
        for item in self.items:
            if item.name.lower() in item_name.lower():
                item.price = price

    def decrease_quantity(self, item_name, quantity):
        for item in self.items:
            if item_name.lower() in item.name.lower():
                item.quantity -= quantity

    def increase_quantity(self, item_name, quantity):
        for item in self.items:
            if item_name.lower() in item.name.lower():
                item.quantity += quantity


class Items:
    def __init__(self, name, price, quantity):
        self.name = name
        self.price = price
        self.quantity = quantity


class Menu(Restaurant):
    def __init__(self):
        super().__init__()

    def add_items(self, name, price, quantity):
        super().add_items(name, price, quantity)

    def view_items(self):
        return super().view_items()

    def remove_items(self, item_name):
        return super().remove_items(item_name)


# admin=Admin("Mohidul", "2303131", "islamohidul856mi647360@gmail.com", "mohidul12")

# Chacha_Mama_Res=Restaurant()
# admin.add_items(Chacha_Mama_Res, "Pizza", 50, 50)
# admin.add_items(Chacha_Mama_Res, "Burger", 20, 40)
# admin.add_items(Chacha_Mama_Res, "Chicken", 30, 20)
# admin.add_items(Chacha_Mama_Res, "Role", 10, 30)
# admin.view_customer()
# admin.view_items(Chacha_Mama_Res)
# admin.increase_quantity(Chacha_Mama_Res, "pizza", 20)
# admin.decrease_quantity(Chacha_Mama_Res,"burger", 3)
# admin.view_items(Chacha_Mama_Res)
# admin.remove_customers("Md. Mohidul Islam")
# admin.view_customer()
# admin.remove_items(Chacha_Mama_Res, "Pizza")
# Chacha_Mama_Res.view_items()
admin = Admin("Mohidul", "131", "islamohidul856mi647360@gmail.com", "Mohidul12")
admin.add_customer("Md. Mohidul Islam", "121", "islamohidul", "mohidul87", "Dhaka")
admin.add_customer("Md. Abrar Islam", "122", "zabed", "mohidul88", "Dhaka")
admin.add_customer("Md. Zabed Islam", "123", "zabed", "mohidul89", "Dhaka")
Chacha_Mama_Restaurant = Restaurant()
first_time = True
while True:
    print("Access the System as : \n1. Admin \n2. Customer  \n3. Exit \n")
    choice = int(input("Enter the choice for use the System : "))
    if choice == 1:
        password = input("Enter the admin password : ")
        if password == admin.admin_password():
            if first_time:
                first_time = False
                print(f"---------------Welcome {admin.name}------------------------")
            while True:
                print(
                    "Choose an Option : \n1. View Customer List\n2. Add Customer\n3. Add Item\n4. Remove Item\n5. Update Price\n6. Increase Quantity\n7. Decrease Quantity\n8. View Items.\n9. Exit\n"
                )
                Option = int(input("\nEnter your choice : "))
                if Option == 1:
                    admin.view_customer()
                elif Option == 2:
                    name = input("Enter the Customer Name : ")
                    id = input("Enter an unique ID : ")
                    email = input("Enter an Email : ")
                    password = input("Enter an unique password : ")
                    address = input("Enter Customer Address : ")
                    admin.add_customer(name, id, email, password, address)
                elif Option == 3:
                    name = input("Enter the Item Name : ")
                    price = int(input("Enter the Item Price : "))
                    quantity = int(input("Enter the Quantity : "))
                    admin.add_items(Chacha_Mama_Restaurant, name, price, quantity)
                elif Option == 4:
                    item_name = input("Enter the Item Name : ")
                    admin.remove_items(Chacha_Mama_Restaurant, item_name)
                elif Option == 5:
                    item_name = input("Enter the Item Name : ")
                    price = int(input("Enter the Updated Price : "))
                    admin.update_price(Chacha_Mama_Restaurant, item_name, price)
                elif Option == 6:
                    item_name = input("Enter the Item Name : ")
                    quantity = int(input("Enter the Quantity : "))
                    admin.increase_quantity(Chacha_Mama_Restaurant, item_name, quantity)
                elif Option == 7:
                    item_name = input("Enter the Item Name : ")
                    quantity = int(input("Enter the Quantity : "))
                    admin.decrease_quantity(Chacha_Mama_Restaurant, item_name, quantity)
                elif Option == 8:
                    admin.view_items(Chacha_Mama_Restaurant)
                elif Option == 9:
                    break
                else:
                    print("\nYour Input is wrong .\n")
    elif choice == 2:
        Name = input("Enter your Name : ")
        id = input("Enter your ID : ")
        password = input("Enter your password : ")
        current_customer = None
        for customer in admin.customers:
            if customer.customer_id() == id and customer.customer_password() == password:
                current_customer = customer
                break
        if current_customer:
            while True:
                print(
                    "Choose an Option : \n1. View Menu \n2. Add Item in Cart\n3. Add Balance\n4. Check Balance \n5. View Cart\n6. Pay Bill\n7. Exit\n "
                )
                Option = int(input("Enter your Choice : "))
                if Option == 1:
                    admin.view_items(Chacha_Mama_Restaurant)
                elif Option == 2:
                    item_name = input("Enter the Item Name : ")
                    quantity = int(input("Enter the Quantity : "))
                    current_customer.add_to_cart(
                        Chacha_Mama_Restaurant, item_name, quantity
                    )
                elif Option == 3:
                    amount = int(input("Enter the amount : "))
                    current_customer.add_balance(amount)
                elif Option == 4:
                    print(current_customer.check_balance())
                elif Option == 5:
                    current_customer.view_cart()
                elif Option == 6:
                    current_customer.pay()
                elif Option == 7:
                    break
                else:
                    print("Your choice in wrong.Please try again...")
        else:
            print("Customer Information not matched . Please try again .")

    elif choice == 3:
        break
    else:
        print("!!! OOPs Your input is wrong !!!")
