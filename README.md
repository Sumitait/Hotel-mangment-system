# Hotel Management System (C Language)

A simple **Hotel Management System** project written in C language. This project allows you to manage hotel room bookings, customer records, search, edit, and delete functionalities through a console-based interface.

## Features

- **Login System** (Username & Password)
- **Book a Room** (Add Customer Details)
- **View Customer Records**
- **Search Customer by Room Number**
- **Edit Customer Records**
- **Delete Customer Records**
- **Colorful Console UI** (may not work on macOS terminal as on Windows)
- **Date and Time Display**

## Getting Started (macOS)

### Prerequisites

- **macOS** (any modern version)
- **Command Line Tools for Xcode** (required for GCC/Clang)
- **Homebrew** (recommended for easy installation of GCC)
- **Terminal** (built-in app)

### Installation Steps

1. **Open Terminal**
   - Press `Command + Space`, type `Terminal`, and hit Enter[6][7][5].

2. **Install Command Line Tools for Xcode**
   - Run:
     ```
     xcode-select --install
     ```
   - Follow the on-screen instructions[5][7][6].

3. **(Optional) Install Homebrew**
   - If you don't have Homebrew, install it:
     ```
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```
   - Follow the instructions to add Homebrew to your PATH[5][7][10].

4. **Install GCC (or use Clang)**
   - **With Homebrew:**
     ```
     brew install gcc
     ```
     - This will install GCC (e.g., `gcc-13` on Apple Silicon)[5][7][11].
   - **Without Homebrew:**
     - macOS comes with `clang`, which is compatible with most C code. You can use `clang` instead of `gcc` for compilation[2][7][5].

5. **Compile the Project**
   - **If you used Homebrew:**
     ```
     gcc-13 hotel.c -o hotel
     ```
     (Replace `gcc-13` with the installed version, e.g., `gcc-12` or `gcc-14` if different)[4][2][11].
   - **If you used Clang:**
     ```
     clang hotel.c -o hotel
     ```

6. **Run the Program**
