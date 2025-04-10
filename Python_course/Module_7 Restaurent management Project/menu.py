class Menu:
    def __init__(self):
        self.items_cart = []

    def add_menuItem(self, item):
        self.items_cart.append(item)

    def find_item(self, item_name):
        for item in self.items_cart:
            if item.name.lower() == item_name.lower():
                return item
        return None

    def remove_item(self, item_name):
        item = self.find_item(item_name)
        if item:
            # remove from items cart using remove function
            self.items_cart.remove(item)
            print(f"Removed {item.name} successfully.!!")
        else:
            print("{item_name} not found !!!")

    def show_Menu(self):
        print("\n\n***********************  MENU  ***************************\n")
        print("Name\t\t\t Price \t\t\t Quantity\n")
        for item in self.items_cart:
            print(f"{item.name}\t\t\t {item.price} \t\t\t {item.quantity}")
