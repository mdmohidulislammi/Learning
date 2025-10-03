class Book:
    def __init__(self, id, name, quantity):
        self.id = id
        self.name = name
        self.quantity = quantity


class User:
    def __init__(self, id, name, email, password):
        self.id = id
        self.name = name
        self.email = email
        self.password = password
        self.bBooks = []  # borrow books
        self.rBooks = []  # return books


class Library:
    def __init__(self, name):
        self.name = name
        self.books = []
        self.users = []

    def add_Books(self, id, name, quantity):
        for book in self.books:
            if book.id == id:
                print(f"The book {book.name} is already exists in your system")
                return
        book = Book(id, name, quantity)
        self.books.append(book)
        print(f"The book {book.name} added successfully .")

    def add_User(self, id, name, email, password):
        for user in self.users:
            if user.id == id:
                print(f"This user already added in your system")
                return
        user = User(id, name, email, password)
        self.users.append(user)
        print(f"The user {user.name} added successfully")

    def borrow_book(self, user, token):
        for book in self.books:
            if token == book.id:
                if book in user.bBooks:
                    print(f"The {book.name} has already borrowed by {user.name} .")
                    return
                else:
                    user.bBooks.append(book)
                    book.quantity-=1
            elif book.quantity < 1:
                print(f"We have no available copy of The {book.name}")
                return
            else:
                user.bBooks.append(book)
                book.quantity -= 1

    def return_books(self, user, token):
        for book in self.books:
            if token == book.id:
                if book in user.bBooks:
                    book.quantity += 1
                    user.rBooks.append(book)
                    user.bBooks.remove(book)
                    print(f"Returned The {book.name} successfully.")
                else:
                    print("You didn't borrow the book")


Dj_baharul_library = Library("Dj_baharul")
baharul = Dj_baharul_library.add_User(
    121, "Dj Baharul", "baharul@gmail.com", "baharuldj"
)
admin = Dj_baharul_library.add_User(111, "admin", "admin@email.com", "admin")
Dj_baharul_library.add_User(123, "Mohidul", "mohidul@gmail.com", "mohidul_mmi")
Engineer_book = Dj_baharul_library.add_Books(1001, "Physics for Engineers", 50)
current_user = admin
change_User = True
while True:
    if current_user == None:
        print("\nNo logged in.\n")
        option = input("\nLog in \ Register (L/R): ")
        if option == "L":
            id = int(input("Enter your ID : "))
            password = input("Enter your password : ")
            match = False
            for user in Dj_baharul_library.users:
                if user.id == id and user.password == password:
                    current_user = user
                    match = True
                    break
            if not match:
                print("No user found please Register first.")
        elif option == "R":
            id = int(input("Enter a valid unique ID : "))
            name = input("Enter Your Full Name : ")
            email = input("Enter your email: ")
            password = input("Enter a unique and strong password : ")
            new_User = Dj_baharul_library.add_User(id, name, email, password)
            current_user = new_User
            break
        elif option == "exit":
            break
    else:

        if change_User:
            print(f"!! Welcome {current_user.name} !!")
            change_User = False
        if current_user.name == "admin":
            print(
                "\n\n1. Add Books\n2. Show books\n3. Add User\n4. Show Users\n5. Logout"
            )
            option = int(input("Please choose any option: "))
            if option == 1:
                # print("Done")
                id = int(input("Enter book id: "))
                name = input("Enter the book name: ")
                quantity = int(input("Enter the Quantity: "))
                Dj_baharul_library.add_Books(id, name, quantity)
            elif option == 2:
                # print("Don2")
                for book in Dj_baharul_library.books:
                    print(
                        f"Book ID : {book.id} Book Name : {book.name} Book Quantity : {book.quantity}"
                    )
            elif option == 3:
                id = int(input("Enter user ID: "))
                name = input("Enter the Name of User")
                email = input("Enter the email of the User : ")
                password = input("Enter an Unique and strong password : ")
                Dj_baharul_library.add_User(id, name, email, password)
            elif option == 4:
                for user in Dj_baharul_library.users:
                    print(
                        f"Name : {user.name} ID : {user.id} Email : {user.email} Password: {user.password}"
                    )

            elif option == 5:
              break
            else: 
                print("Invalid Input. Please Try again...")
        else:
            print("\nChoose an Option :\n1. Book List\n2. Borrow Book\n3. Return Book\n4. Exit")
            choice=int (input("Enter a Choice : "))
            if choice==1:
                for book in Dj_baharul_library.books:
                    print(f'Book ID: {book.id} Book Name : {book.name} Book quantity : {book.quantity}')
            elif choice ==2:
                book_id=int(input("Enter the book ID : "))
                Dj_baharul_library.borrow_book(current_user, book_id)
            elif choice ==3:
                book_id= int(input("Enter the book ID: "))
                Dj_baharul_library.return_books(current_user, book_id)
            elif choice ==4:
                break
            else:
                print("Invalid input. Please Try Again...")


