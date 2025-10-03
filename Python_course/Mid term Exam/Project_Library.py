class Library:
    book_list = []

    def __init__(self, bookID, title, Author, availability):
        self.__Name = title
        self.__id = bookID
        self.__Author = Author
        self.__availability = availability

    def entry_book(self):
        Library.book_list.append(self)

    def __repr__(self) -> str:
        return f'Book Name: {self.__Name},  Book Id: {self.__id},   Author Name: {self.__Author},   Availability: {self.__availability}'

    def bookId(self):
        return self.__id

    def bookName(self):
        return self.__Name

    def Auth(self):
        return self.__Author

    def available(self):
        return self.__availability

    def do_Availability(self, Availability):
        self.__availability = Availability


class Book(Library):
    def __init__(self, bookID, Title, Author, Availability):
        super().__init__(bookID, Title, Author, Availability)
        self.entry_book()

    def borrow_book(self):
        if self.available():
            self.do_Availability(False)
            print("\nBorrowed successfully.")
        else:
            print("\nThis book is already borrowed.")

    def return_book(self):
        if self.available() == False:
            self.do_Availability(True)
            print("\nReturned Successfully.")
        else:
            print("\nThis book is already returned.")
    def view_bookInfo(self):
        return f"{super().__repr__()}"

a = Book(101, 'Thermodynamics an Engineering Approach',
         'Yunus A. Cengel', True)
b = Book(102, 'Thermodynamics', 'RS Khurmi', True)
c = Book(131, 'Sociology', 'Shaefaer', True)
d = Book(132, 'Physics for Engineers', 'Dr. Giuss Uddin', True)
<<<<<<< HEAD
print(Book.view_bookInfo(a))
=======
>>>>>>> f9ddbb6 (Adding new files after learning)
while True:
    print("\n-------------------------------------------------------------------------------------------------------------\n")
    print('  1. View All Books\n  2. Borrow Book\n  3. Return Book\n  4. Exit')
    n = int(input("Please input your choice: "))
    if n == 1:
        print('\n--------------------------------------------------------------------------------------------------------------\n')
        for i, items in enumerate(Library.book_list):
            print(i+1, items, end='\n')
    elif n == 2:
        BookID = int(input('Enter the book ID which you want to borrow: '))
        found = False
        for book in Library.book_list:
            if book.bookId() == BookID:
                book.borrow_book()
                found = True
                break
        if found == False:
            print("\nWrong Book ID. Please Provide the right one.\n")
    elif n == 3:
        BookID = int(input('Enter the book ID which you want to borrow: '))
        found = False
        for book in Library.book_list:
            if book.bookId() == BookID:
                book.return_book()
                found = True
                break
        if found == False:
            print('\nWrong Book Id. Please Provide Correct one.\n')
    elif n == 4:
        print("\nThank you.")
        break
    else:
        print("\n\nYou have entered the wrong choice. Please enter the right one.\n\n")
