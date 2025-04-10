class Phone:
    manufactured='China'
    def __init__(self, owner, price, brand):
        self.owner=owner
        self.price=price
        self.brand=brand
    def call(self):
        print(f"This is {self.owner} phone and Price: {self.price} which is {self.brand} Phone.")
        return 'Done'

my_phone=Phone('Mohidul',12000, 'Samsung')
print(my_phone.owner, my_phone.price, my_phone.brand)
        
my_phone.call()