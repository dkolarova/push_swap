# 🔄 push_swap

`push_swap` is a sorting algorithm project written in **C**.
The goal is to sort a list of integers using **two stacks** and a limited set of operations, while performing the **smallest possible number of moves**.

This project is part of the **42 School curriculum** and focuses on algorithms, data structures, and optimization.

---

# 📌 Project Overview

The program receives a list of integers as arguments and outputs a sequence of instructions that sort the numbers in ascending order.

It uses:

* **Stack A** → contains the numbers to sort
* **Stack B** → empty at the start and used as auxiliary storage

The program prints the instructions needed to sort stack A.

---

# ⚙️ Allowed Operations

| Operation | Description                                 |
| --------- | ------------------------------------------- |
| `sa`      | swap the first two elements of stack A      |
| `sb`      | swap the first two elements of stack B      |
| `ss`      | perform `sa` and `sb` simultaneously        |
| `pa`      | push the top element of B to A              |
| `pb`      | push the top element of A to B              |
| `ra`      | rotate stack A (first element becomes last) |
| `rb`      | rotate stack B                              |
| `rr`      | rotate both stacks                          |
| `rra`     | reverse rotate stack A                      |
| `rrb`     | reverse rotate stack B                      |
| `rrr`     | reverse rotate both stacks                  |

These operations manipulate the stacks to gradually sort the numbers. ([GitHub][1])

---

# 📂 Project Structure

```id="6r6n8e"
push_swap
│
├── src            # Source files
├── libft          # Custom C library
│
├── push_swap.c    # Main program
├── push_swap.h    # Header file
│
├── Makefile
└── README.md
```

---

# ⚙️ Compilation

Compile the project using:

```bash id="p7h9kz"
make
```

This will generate the executable:

```id="h6yyyl"
push_swap
```

---

# 🚀 Usage

Run the program with a list of numbers:

```bash id="aq7e0q"
./push_swap 3 2 5 1 4
```

The program will output the sequence of operations required to sort the numbers.

Example output:

```
pb
ra
sa
pa
```

---

# 🧠 Algorithm

Different algorithms can be used to solve this project, such as:

* **Radix Sort**
* **Chunk Sorting**
* **Turk Algorithm**
* **Greedy approach**

The goal is to minimize the number of operations while keeping the program efficient. ([GitHub][2])

---

# 🎯 Learning Goals

This project helps practice:

* sorting algorithms
* stack data structures
* algorithm optimization
* memory management
* parsing and error handling

---

# 🛠️ Technologies

* C
* Makefile
* Custom `libft`

---

Created by ~Diana Kolarova

