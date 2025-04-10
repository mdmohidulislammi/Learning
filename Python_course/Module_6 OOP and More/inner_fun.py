# function is a first class object
def double_decker():
    print("Starting the double decker")
    def inner_fun():
        print("Inside the inner")
        return 30000
    return inner_fun

print(double_decker()())