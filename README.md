## 📄 README.md

## Overview
# Core-Logic-Calculator

This project implements the **core logic of a calculator in C++**, supporting both **standard arithmetic operations** and **scientific functions**.  
It demonstrates **algorithm design, expression parsing, and use of STL containers (stack, vector, string)** along with `<cmath>` for scientific calculations.


## 📂 Folder Structure
Core-Logic-Calcualator/
- A_CALCULATOR_PROJECT/   # Source files (headers and implementation)
   - Evalute.cpp
   - Evaluate.h
   - main.cpp # driver file
- A_CALCULATOR_PROJECT.sln # Visual Studio solution file
- README.md
- .gitignore
- .gitattributes

## ⚙️ Build & Run Instructions

### 🔹 On Windows (Visual Studio)
1. Open `A_CALCULATOR_PROJECT.sln` in Visual Studio.
2. Add headers
3. Create main.cpp
4. Build the solution (`Ctrl+Shift+B`).
5. Run with **Ctrl+F5**.

### 🔹 On Linux/Mac (g++)
If you want to compile manually:
g++ *main.cpp -o calculator_app
./calculator_app

## 🧩 Example Usage

 string expr1 = "3+5*2";
 cout << expr1 << " = " << evaluate(expr1) << endl;

 string expr2 = "sin(0.5)+log(10)";
 cout << expr2 << " = " << evaluate(expr2) << endl;

**Expected Output:**

3+5*2 = 13
sin(0.5)+log(10) = 2.30259


## 🚀 Features Implemented
- Standard arithmetic operations: `+`, `-`, `*`, `/`, `^`
- Scientific functions: `sin`, `cos`, `tan`, `sqrt`, `log`, `ln`, `exp`
- Expression parsing using **stack** and **vector**
- Error handling for invalid expressions
- Modular design for easy extension


## 📌 Future Improvements
- Add support for parentheses nesting and precedence validation.
- Implement memory functions (M+, M-, MR).
- Provide a GUI frontend (WinUI 3, Qt, or HTML/CSS/JS).
- Add unit tests for robustness.


## 👤 Author
Developed by **Shanzay Malik**  
  

Would you like me to also prepare a **diagram of the expression evaluation flow (tokenization → stack → result)** for the README? That would make the parsing logic instantly clear to recruiters.
