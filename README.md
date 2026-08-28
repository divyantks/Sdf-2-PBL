# 📚 Library Management System

A simple **console-based Library Management System written in C++**. The project demonstrates core Object-Oriented Programming concepts along with file handling for storing library data.

## ✨ Features

* Add a Book
* Add a Reference Book
* View all library items
* Issue a Book
* Return a Book
* Search for an item by ID
* Save and load data using `data.txt`
* Reference Books cannot be issued

## 🧠 Concepts Used

* Classes & Objects
* Abstraction
* Inheritance
* Polymorphism
* Encapsulation
* Virtual Functions
* Constructors & Destructors
* STL `vector`
* File Handling (`ifstream`, `ofstream`)
* Dynamic Memory Allocation

## 📁 File

```text
Library.cpp
```

The program automatically creates/updates `data.txt` to store library records.

## ▶️ How to Run

Compile using any C++ compiler:

```bash
g++ Library.cpp -o Library
```

Run:

```bash
./Library
```

On Windows:

```bash
Library.exe
```

## 🖥️ Menu

```text
---Library---
1.Add Book
2.Add Reference
3.View
4.Issue
5.Return
6.Search
7.Exit
```

## 🏗️ Class Structure

```text
          LibraryItem
           /       \
          /         \
       Book     ReferenceBook

             Library
                |
                └── vector<LibraryItem*>
```

`LibraryItem` acts as the abstract base class, while `Book` and `ReferenceBook` provide their own implementations of operations such as displaying, issuing, returning, and saving data.

## 💾 Data Persistence

Library information is stored in:

```text
data.txt
```

The program loads existing records when it starts and saves changes whenever items are added, issued, or returned.

## 👨‍💻 Author

**Divyant Kumar Srivastava**
