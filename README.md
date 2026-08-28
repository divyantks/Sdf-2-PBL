# 📚 Library Management System

A simple **console-based Library Management System developed in C++** using Object-Oriented Programming concepts.

## ✨ Features

* Add a Book
* Add a Reference Book
* View all library items
* Issue a Book
* Return a Book
* Search for an item by ID
* Save and load library data
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
* File Handling
* Dynamic Memory Allocation

## 🏗️ Class Structure

```text
              LibraryItem
               /       \
              /         \
           Book     ReferenceBook

                Library
                   |
                   +-- vector<LibraryItem*>
```

`LibraryItem` is an abstract base class. `Book` and `ReferenceBook` inherit from it and implement their own behavior.

The `Library` class manages all library items using a `vector` of `LibraryItem` pointers.

## 📁 Project File

```text
Library.cpp
```

The program uses `data.txt` for data persistence. **This file is generated automatically by the program when it saves data and does not need to be present in the repository beforehand.**

## ▶️ How to Run

Compile the C++ file using `g++`:

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

## 💾 Data Persistence

The program stores library records in `data.txt`.

When the program starts, it loads previously saved records. Changes made through adding, issuing, or returning items are automatically saved.

## 👨‍💻 Author

**Divyant Kumar Srivastava**
