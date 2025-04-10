class Shop:
    class_cart=[]
    def __init__(self, buyer):
        self.buyer=buyer
        self.instance_cart=[]

    def add_cart(self, item):
        self.class_cart.append(item)
        self.instance_cart.append(item)

man1=Shop('Mohidul')
man1.add_cart('Shoes')
man1.add_cart('Pant')
man1.add_cart('Shirt')
man2=Shop('Nahidul')
man2.add_cart('Ghori')
man2.add_cart('Sunglass')

print(man1.instance_cart)
print(man2.instance_cart)

print(man1.class_cart)
print(man2.class_cart)        