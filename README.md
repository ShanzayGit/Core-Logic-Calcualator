# 🧮 Core-Logic-Calculator

This project implements a **standard and scientific calculator in C++** with a **Qt-based graphical user interface (GUI)**. It combines a robust **expression evaluator** (using STL containers and `<cmath>`) with an interactive **UI built in Qt Creator and integrated into Visual Studio**.


## 📂 Folder Structure

```
Core-Logic-Calcualator/
│
├── A_CALCULATOR_PROJECT/        # Core logic (headers + implementation)
│   ├── Evaluate.cpp
│   ├── Evaluate.h
│   └── main.cpp                 # Console driver
│
├── Calculator/                  # Qt UI project
│   ├── mainwindow.ui            # UI layout (Qt Designer)
│   ├── mainwindow.h             # UI header
│   ├── mainwindow.cpp           # UI controller logic
│   ├── main.cpp     # Qt project file
│
├── A_CALCULATOR_PROJECT.sln     # Visual Studio solution
├── README.md
├── .gitignore
└── .gitattributes
```


## ⚙️ Build & Run Instructions

### 🔹 Console Version
1. Open `A_CALCULATOR_PROJECT.sln` in **Visual Studio**.
2. Build (`Ctrl+Shift+B`) and run (`Ctrl+F5`).
3. Input expressions directly in the console.

### 🔹 Qt GUI Version
1. Install Qt with the same compiler toolchain as Visual Studio.
2. Add the Qt VS Tools extension in Visual Studio.
3. Configure Qt version path in Qt VS Tools → Options.
4. Open the solution and build the project.
5. Run the calculator with the interactive UI.


## 🚀 Features

- **Standard arithmetic**: `+`, `-`, `*`, `/`, `^`,`%`,`mod`
- **Scientific functions**: `sin`, `cos`, `tan`, `sqrt`, `log`, `ln`, `exp`,`acaos`,`atan`,`asin`,`exp`,`abs`
- **UI Enhancements**:
  - Toggle between **Standard** and **Scientific** panels
  - **Decimal point** support
  - **Percentage operator** distinct from modulus
  - **Error handling** (e.g., division by zero → “Error” message)
  - Buttons can span multiple rows/columns in grid layout


## 🖥️ Example Usage

### Console
```cpp
string expr1 = "3+5*2";
cout << expr1 << " = " << evaluate(expr1) << endl;

string expr2 = "50% * 20";
cout << expr2 << " = " << evaluate(expr2) << endl;
```

**Output:**
```
3+5*2 = 13
50% * 20 = 10
```

### GUI
- Enter `2+3*log(10)` in the display → Result:`5`
- For now `%` is used as binary operator like 50%20 (50 percent of 20).


## 📌 Future Improvements
- Add **memory functions** (M+, M-, MR).
- Implement **unit tests** for evaluator and UI.
- Extend UI with **history panel** and **themes**.
- Package as a **cross-platform installer**.


## 👩‍💻 Author
Developed by **Shanzay Malik**
