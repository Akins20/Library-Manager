
# **Library Management System**

## **Project Description**

The Library Management System is a simple command-line application built using C++. This project allows users to manage library records, including books and users. It supports functionalities like adding, removing, updating, and searching for books and users. The data is persistently stored in text files, enabling basic file management operations for library systems.

---

## **Features**

### **User Management:**
1. **Add User**: Add a new user to the library system by providing their first and last names.
2. **Remove User**: Remove a user from the system based on their details.
3. **Search for a User**: Search for users by name.
4. **Display All Users**: List all users currently in the library system.
5. **Update User Information**: Modify existing user details.

### **Book Management:**
1. **Add Book**: Add a new book to the library system by providing details such as title, author, year, and genre.
2. **Remove Book**: Remove a book from the system by title.
3. **Search for a Book**: Search for books by title or other details.
4. **Display All Books**: List all books currently stored in the system.
5. **Update Book Information**: Modify details of an existing book.

---

## **Files and Directory Structure**

The project is broken into modular components to ensure scalability and maintainability.

```
├── Books.h                # Header file defining the Book class and its methods
├── LibraryFileUtils.h     # Header file containing file utility functions (save, delete, update)
├── LibrarySystem.cpp      # Main source file handling the CLI interface and system logic
├── LibraryUtils.h         # Header file for general utility functions (e.g., searching, displaying)
├── User.h                 # Header file defining the User class and its methods
└── README.md              # Project documentation
```

---

## **Installation**

### **Prerequisites:**
- A C++ compiler (e.g., g++ or clang)
- Basic knowledge of C++ programming and file handling
- Optional: IDE like Qt Creator or Visual Studio Code for development

### **Steps to Install and Run:**
1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   ```

2. **Navigate to the Project Directory**:
   ```bash
   cd Library-Management-System
   ```

3. **Compile the Project**:
   Using `g++`, you can compile the project as follows:
   ```bash
   g++ -o library_app LibrarySystem.cpp
   ```

4. **Run the Application**:
   Once compiled, you can run the executable:
   ```bash
   ./library_app
   ```

---

## **Usage**

When you run the program, the main menu will appear in the terminal, prompting you to choose an action:

```
Library Management System
1. Add a user
2. Remove a user
3. Add a book
4. Remove a book
5. Search for a user
6. Search for a book
7. Display all users
8. Display all books
9. Update a book
10. Update a user
11. Exit
Enter your choice:
```

Simply enter the corresponding number for the action you wish to perform.

---

## **How It Works**

### **User Management**:
- **Adding a User**: The user will be prompted to input the first name and last name. This data is stored in a file (`users.txt`).
  
- **Removing a User**: The system searches for the user based on their details and removes them from the file.
  
- **Updating a User**: You can update a user's name, which will overwrite the current data in the file.

### **Book Management**:
- **Adding a Book**: The user provides details like title, author, year, and genre, which are then stored in a file (`books.txt`).
  
- **Removing a Book**: The system searches for a book by title and removes its details from the file.
  
- **Updating a Book**: The user can update the book’s details such as title, author, year, and genre.

---

## **Future Improvements**

- **Improved Search Functionality**: Implementing partial search or case-insensitive search for users and books.
  
- **File Optimization**: Moving to a more efficient file handling mechanism (e.g., indexed file structures or databases like SQLite) for larger-scale systems.
  
- **User Role Management**: Implement different user roles (like librarian and member) to introduce different permission levels for adding or removing books and users.
  
- **Graphical User Interface (GUI)**: Transitioning the CLI application into a GUI-based application using a framework like Qt.

---

## **Contributing**

Feel free to fork the repository and submit pull requests for any improvements or bug fixes. All contributions are welcome!

---

## **Contact Information**

For any questions or suggestions, feel free to contact:

- **Developer**: Elijah Ogunbiyi (Akins)
- **Email**: [ogunbiye@gmail.com](mailto:ogunbiye@gmail.com)

---
