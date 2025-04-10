class Library:
    __book_list = []
    
    @classmethod
    def entry_book(cls, book):
        cls.__book_list.append(book)
    
    @classmethod
    def view_books(cls):
        if not cls.__book_list:
            print("No books available.")
            return
        for book in cls.__book_list:
            book.view_book_info()
    
    @classmethod
    def find_book(cls, book_id):
        for book in cls.__book_list:
            if book.get_book_id() == book_id:
                return book
        return None

class Book:
    def __init__(self, book_id, title, author):
        self.__book_id = book_id
        self.__title = title
        self.__author = author
        self.__availability = True
        Library.entry_book(self)

    def get_book_id(self):
        return self.__book_id
    
    def borrow_book(self):
        if self.__availability:
            self.__availability = False
            print(f"Book '{self.__title}' borrowed successfully.")
        else:
            print("Sorry, this book is already borrowed.")
    
    def return_book(self):
        if not self.__availability:
            self.__availability = True
            print(f"Book '{self.__title}' returned successfully.")
        else:
            print("This book was not borrowed.")
    
    def view_book_info(self):
        print(f"Book ID: {self.__book_id}, Title: {self.__title}, Author: {self.__author}, Available: {self.__availability}")

# Creating book objects
Book(101, "The Great Gatsby", "F. Scott Fitzgerald")
Book(102, "To Kill a Mockingbird", "Harper Lee")
Book(103, "1984", "George Orwell")

# Menu-driven system
def menu():
    while True:
        print("\nLibrary Menu:")
        print("1. View All Books")
        print("2. Borrow Book")
        print("3. Return Book")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            Library.view_books()
        elif choice == "2":
            book_id = int(input("Enter Book ID to borrow: "))
            book = Library.find_book(book_id)
            if book:
                book.borrow_book()
            else:
                print("Invalid Book ID.")
        elif choice == "3":
            book_id = int(input("Enter Book ID to return: "))
            book = Library.find_book(book_id)
            if book:
                book.return_book()
            else:
                print("Invalid Book ID.")
        elif choice == "4":
            print("Exiting Library System.")
            break
        else:
            print("Invalid choice. Please try again.")

menu()
