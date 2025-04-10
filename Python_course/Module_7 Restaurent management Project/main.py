from food_items import food_Item
from menu import Menu
from users import Customer, Admin, Employee
from restaurent import Restaurent
from orders import Order

Vai_Vai_restora = Restaurent("Vai vai restaurent.")


def customer_Interface():
    name = input("Enter Your Name: ")
    email = input("Enter Your Email: ")
    phone = input("Enter Your Phone Number: ")
    address = input("Enter Your address: ")
    customer = Customer(name=name, email=email, phone=phone, address=address)

    while True:
        print(f"\n\n-------------Welcome {customer.name}----------------\n")
        print("1. View Menu.")
        print("2. Add item to your cart.")
        print("3. View Cart.")
        print("4. Pay Your Bill. ")
        print("5. Exit from the Menu.")

        choice = int(input("Enter Your choice: "))
        if choice == 1:
            customer.view_menu(Vai_Vai_restora)
        elif choice == 2:
            ItemName = input(
                "Enter Item Name which you want to add your Cart : ")
            ItemQuantity = int(input("Enter Item Quantity: "))
            customer.add_to_Cart(Vai_Vai_restora, ItemName, ItemQuantity)
        elif choice == 3:
            customer.view_cart()
        elif choice == 4:
            customer.pay_Bill()
        elif choice == 5:
            break
        else:
            print("\n\n!! Invalid User Input !!")


def Admin_interface():
    name = input("Enter Your Name: ")
    email = input("Enter Your Email: ")
    phone = input("Enter Your Phone Number: ")
    address = input("Enter Your address: ")
    admin = Admin(name=name, email=email, phone=phone, address=address)

    while True:
        print(f"\n\n-------------Welcome {admin.name}----------------\n")
        print("1. Add new Item.")
        print("2. Add new Employee")
        print("3. View Employee.")
        print("4. View Items. ")
        print("5. Delete Item.")
        print("6. Exit")
        choice = int(input("Enter Your choice: "))
        if choice == 1:
            itemName = input("Enter Item Name: ")
            ItemPrice = int(input("Enter Item Price: "))
            itemQuantity = int(input("Enter Item Quantity: "))
            item = food_Item(itemName, ItemPrice, itemQuantity)
            admin.add_new_item(Vai_Vai_restora, item)

        elif choice == 2:
            name = input("Enter Employee Name: ")
            email = input("Enter Employee Email: ")
            phone = input("Enter Employee Phone Number: ")
            address = input("Enter Employee address: ")
            Designation = input("Enter Designation of the Employee: ")
            Age = input("Enter Empoyee Age:  ")
            Salary = input("Enter Employee Salary: ")
            employee = Employee(name, email, phone, address,
                                Age, Designation, Salary)
            admin.add_employee(Vai_Vai_restora, employee)
        elif choice == 3:
            admin.view_employee(Vai_Vai_restora)
        elif choice == 4:
            admin.view_menu(Vai_Vai_restora)
        elif choice == 5:
            itemName = input("Enter item name which you want to remove : ")
            admin.delete_item(Vai_Vai_restora, itemName)
        elif choice == 6:
            break
        else:
            print("\n\n!! Invalid Your Input !!")


while True:
    print("\n------------------------------- Welcome Our System --------------------------------\n")
    print("1. Customer ")
    print("2. Admin")
    print("3. Exit")
    choice = int(input("Enter Your choice : "))
    if choice == 1:
        customer_Interface()
    elif choice == 2:
        Admin_interface()
    elif choice == 3:
        break
    else:
        print("\n\n----------------------------- ooops ! Wrong User Input ! Please Input Right One -------------------------------")
