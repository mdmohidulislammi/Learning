class Order:
    def __init__(self):
        self.items = {}  # dictionary for using key

    def add_item(self, item):
        if item in self.items:
            self.items[item] += item.quantity  # If item exist in the cart
        else:
            # else keep same value as before have in the cart
            self.items[item] = item.quantity

    def remove(self, item):
        if item in self.items:
            del self.items[item]

    def total_price(self):
        return sum(float(item.price) * float(quantity) for item, quantity in self.items.items())

    def clear(self):
        self.items = {}