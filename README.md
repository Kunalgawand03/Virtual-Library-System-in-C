# Virtual-Library-System-in-C
A simple Virtual Library System written in C that allows users to display, borrow, return, add, and remove books interactively using basic data structures and console I/O.

📘 README.md (Full Description for Repo)
# 📚 Virtual Library System in C

A simple console-based **Virtual Library System** built in C.  
This program lets users manage a small collection of books — including options to display, borrow, return, add, and remove books — using basic data structures like arrays and structures.

---

## 🧠 Features

- 📖 **Display Books** – View all available and borrowed books.
- 📕 **Borrow a Book** – Mark a book as borrowed if available.
- 📗 **Return a Book** – Return a borrowed book to the library.
- ➕ **Add a New Book** – Add a new book (title + borrowed status).
- ➖ **Remove a Book** – Delete a book from the library list.
- 🚪 **Exit Option** – Safely exit the system.

---

## 🧩 How It Works

Each book is stored as a structure with:

typedef struct {
    char title[50];
    int isBorrowed;
} Book;


The system maintains an array of books and lets users perform actions through a simple menu interface.

⚙️ How to Run

Clone this repository:

git clone https://github.com/<your-username>/Virtual-Library-System-in-C.git
cd Virtual-Library-System-in-C


Compile the code:

gcc library.c -o library


Run the program:

./library

🧑‍💻 Example Menu
--- Virtual Library System ---
1. Display Books
2. Borrow a Book
3. Return a Book
4. Add a Book
5. Remove a Book
6. Exit
Choose an option:

🧱 Concepts Used

Structs and arrays in C

Function modularity

Console input/output

Basic memory and index handling
