# Big-Integer-Library
# BigInt: A C++ Big Integer Library

This project is a custom C++ library for handling arbitrarily large integers that exceed the limits of standard data types like `long long`. It's a powerful demonstration of object-oriented design, operator overloading, and the implementation of fundamental arithmetic algorithms.

---

## 🚀 Core Features

* **Arbitrary Precision**: Can represent and operate on integers of virtually any size, limited only by available memory.
* **Full Operator Overloading**: Supports all standard arithmetic and comparison operators for intuitive use:
    * **Arithmetic**: `+` (addition), `-` (subtraction), `*` (multiplication), `/` (division), `%` (modulo).
    * **Comparison**: `==`, `!=`, `<`, `>`, `<=`, `>=`.
* **Object-Oriented Design**: Encapsulates all logic within a clean and reusable `BigInt` class.
* **Algorithm Implementation**: Core arithmetic operations like addition and multiplication are implemented from scratch, showcasing a deep understanding of how these algorithms work.
* **Efficient String-Based Storage**: Uses `std::string` to store the digits of the large numbers, allowing for easy manipulation and dynamic size.

---

## 🛠️ Tech Stack

* **Language**: C++17
* **Core Concepts**: Object-Oriented Programming, Operator Overloading, Data Structures, Algorithm Design.
* **Build System**: `make`

---

## ⚙️ How to Build and Use

### Prerequisites

* A C++ compiler that supports C++17 (like `g++`).
* The `make` build automation tool.

### Build Instructions

1.  **Clone the repository:**
    ```bash
    git clone <your-repo-link>
    cd <your-repo-directory>
    ```

2.  **Build the demonstration:**
    ```bash
    make
    ```
    This will create an executable file named `main`.

### Running the Demo

To run the main demonstration showing various `BigInt` operations:
```bash
./main
