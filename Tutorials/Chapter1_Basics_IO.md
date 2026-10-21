# C++ Tutorial: Chapter 1 – Basics and Input/Output

> **Course:** Programming Fundamentals using C++ (BHCS01) – B.Sc. (Hons) Computer Science
> **Level:** Beginner | **Standard used:** C++17 | **Compiler:** g++

This chapter takes you from your first "Hello, World!" program to formatted input/output, operators, expression evaluation and type conversion. Every concept comes with **code, output and an explanation**, followed by exercises in the exam style (trace the output, debug the code, write a program).

---

## Table of Contents

- [Prerequisites and Setup](#prerequisites-and-setup)
- [1. Introduction](#1-introduction)
- [2. Program Structure](#2-program-structure)
- [3. Header Files](#3-header-files)
- [4. Identifiers and Keywords](#4-identifiers-and-keywords)
- [5. Data Types](#5-data-types)
- [6. Variables and Constants](#6-variables-and-constants)
- [7. Input and Output](#7-input-and-output)
- [8. Manipulators](#8-manipulators)
- [9. Operators](#9-operators)
- [10. Precedence and Associativity](#10-precedence-and-associativity)
- [11. Type Conversion](#11-type-conversion)
- [Common Mistakes](#common-mistakes)
- [Trace-the-Output Exercises](#trace-the-output-exercises)
- [Debug-the-Code Exercises](#debug-the-code-exercises)
- [Practice Programs](#practice-programs)
- [Quick Revision Cheat Sheet](#quick-revision-cheat-sheet)
- [References](#references)

---

## Prerequisites and Setup

You need two things: a **text editor/IDE** and a **C++ compiler**.

| Platform | Compiler option | How to get it |
|----------|----------------|---------------|
| Windows | MinGW-w64 (g++) or MSVC | Install MSYS2/MinGW, or Visual Studio Community |
| macOS | Clang (`g++` is an alias) | Run `xcode-select --install` in Terminal |
| Linux | GCC | `sudo apt install g++` (Debian/Ubuntu) |

**Editors/IDEs:** VS Code (with the C/C++ extension), Code::Blocks, Dev-C++, CLion.

**Check your installation:**

```bash
g++ --version
```

If a version number is printed, you are ready.

---

## 1. Introduction

**C++** is a general-purpose, compiled programming language created by Bjarne Stroustrup (as "C with Classes") and extended from C. It supports **procedural**, **object-oriented** and **generic** programming.

### How a C++ program becomes an executable

```
Source code (.cpp)
      │  Preprocessor   → handles #include, #define
      ▼
Expanded source
      │  Compiler       → translates to object code (.o / .obj)
      ▼
Object code
      │  Linker         → joins with library code
      ▼
Executable (a.out / .exe)
```

### Your first program

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

**Output**

```
Hello, World!
```

### Compile and run

```bash
g++ -std=c++17 hello.cpp -o hello    # compile
./hello                              # run (Linux/macOS)
hello.exe                            # run (Windows)
```

| Part of the command | Meaning |
|---------------------|---------|
| `g++` | The compiler |
| `-std=c++17` | Use the C++17 language standard |
| `hello.cpp` | Your source file |
| `-o hello` | Name the output executable `hello` |

**Key takeaways**
- C++ is compiled: source → preprocess → compile → link → run.
- Source files use the `.cpp` extension.

---

## 2. Program Structure

A typical C++ program has these parts:

```cpp
// 1. Documentation section (comments)
/* Program: Add two numbers
   Author : Ankith */

// 2. Preprocessor directives
#include <iostream>

// 3. Namespace declaration
using namespace std;

// 4. Global declarations (optional)
const int OFFSET = 0;

// 5. main function – program execution starts here
int main() {
    int a = 10, b = 20;          // statements end with ;
    int sum = a + b + OFFSET;
    cout << "Sum = " << sum << endl;
    return 0;                    // 0 means "ended successfully"
}
```

**Output**

```
Sum = 30
```

### Line-by-line explanation

| Element | Explanation |
|---------|-------------|
| `// ...` | Single-line comment, ignored by the compiler |
| `/* ... */` | Multi-line comment |
| `#include <iostream>` | Preprocessor directive; pastes the contents of the `iostream` header (gives `cin`, `cout`) |
| `using namespace std;` | Lets you write `cout` instead of `std::cout` |
| `int main()` | Entry point; every program must have exactly one `main` |
| `{ ... }` | Braces mark the body (block) of the function |
| `;` | Terminates a statement |
| `return 0;` | Returns status to the operating system; `0` = success |

### Without `using namespace std`

```cpp
#include <iostream>

int main() {
    std::cout << "Hello" << std::endl;   // std:: prefix needed
    return 0;
}
```

> `std` is the **standard namespace**. A namespace groups names to avoid clashes. In small programs `using namespace std;` is fine; in large projects many developers prefer the `std::` prefix.

**Key takeaways**
- Execution starts at `main()`.
- Every statement ends with `;`.
- `return 0;` signals success.

---

## 3. Header Files

Header files contain declarations of functions, classes and objects that your program can use. They are included with `#include`.

| Header | Provides | Example use |
|--------|----------|-------------|
| `<iostream>` | `cin`, `cout`, `cerr`, `endl` | Console input/output |
| `<iomanip>` | `setw`, `setprecision`, `setfill` | Formatted output |
| `<cmath>` | `sqrt`, `pow`, `abs`, `sin`, `cos`, `ceil`, `floor` | Mathematics |
| `<string>` | `string` class, `getline` | Text handling |
| `<cstring>` | `strlen`, `strcpy`, `strcmp` | C-style strings |
| `<cstdlib>` | `rand`, `exit`, `atoi` | General utilities |
| `<climits>` | `INT_MAX`, `INT_MIN`, `CHAR_BIT` | Limits of data types |

### Two ways to include

```cpp
#include <iostream>     // angle brackets: standard library headers
#include "myfile.h"     // quotes: your own header files (searched in your folder first)
```

### Example using several headers

```cpp
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    cout << "sqrt(81)   = " << sqrt(81) << endl;
    cout << "pow(2, 10) = " << pow(2, 10) << endl;
    cout << "INT_MAX    = " << INT_MAX << endl;
    cout << "INT_MIN    = " << INT_MIN << endl;
    return 0;
}
```

**Output**

```
sqrt(81)   = 9
pow(2, 10) = 1024
INT_MAX    = 2147483647
INT_MIN    = -2147483648
```

> **Note:** `#include <bits/stdc++.h>` includes everything but works only on GCC. It is **not portable**, so avoid it in submissions that may be compiled elsewhere.

**Key takeaways**
- `<...>` is for library headers, `"..."` is for your own.
- Include only what you need.

---

## 4. Identifiers and Keywords

### Identifiers

An **identifier** is a name given to a variable, function, class, etc.

**Rules**

1. May contain letters (`a–z`, `A–Z`), digits (`0–9`) and underscore `_`.
2. Must **not start with a digit**.
3. No spaces or special characters (`@`, `#`, `-`, `$`, etc.).
4. Cannot be a **keyword**.
5. **Case-sensitive**: `total`, `Total` and `TOTAL` are three different names.

| Identifier | Valid? | Reason |
|-----------|--------|--------|
| `marks` | ✅ | Letters only |
| `_count` | ✅ | May start with underscore |
| `student1` | ✅ | Digits allowed after the first character |
| `total_marks` | ✅ | Underscore allowed |
| `2ndNumber` | ❌ | Starts with a digit |
| `my-name` | ❌ | Hyphen is not allowed |
| `total marks` | ❌ | Space not allowed |
| `float` | ❌ | Keyword |
| `price$` | ❌ | `$` not allowed |

> **Style tip:** use meaningful names (`totalMarks` or `total_marks`, not `tm`). Avoid names starting with an underscore followed by a capital letter or containing double underscores; these are reserved for the compiler.

### Keywords

**Keywords** are reserved words with a fixed meaning in C++. You cannot use them as identifiers.

| Category | Examples |
|----------|----------|
| Data types | `int`, `char`, `float`, `double`, `bool`, `void`, `long`, `short`, `signed`, `unsigned` |
| Control flow | `if`, `else`, `switch`, `case`, `default`, `for`, `while`, `do`, `break`, `continue`, `return`, `goto` |
| Storage/qualifiers | `static`, `extern`, `const`, `register`, `volatile`, `mutable` |
| OOP | `class`, `struct`, `public`, `private`, `protected`, `virtual`, `friend`, `this`, `new`, `delete` |
| Others | `namespace`, `using`, `template`, `typedef`, `try`, `catch`, `throw`, `sizeof`, `enum`, `union` |

C++ has roughly 90+ keywords (the exact count depends on the standard).

**Key takeaways**
- Identifiers: letters, digits, `_`; cannot start with a digit; case-sensitive.
- Keywords cannot be used as identifiers.

---

## 5. Data Types

A **data type** tells the compiler what kind of value a variable holds and how much memory it needs.

### Classification

| Category | Types |
|----------|-------|
| **Built-in (fundamental)** | `int`, `char`, `float`, `double`, `bool`, `void`, `wchar_t` |
| **Derived** | Array, pointer, reference, function |
| **User-defined** | `struct`, `union`, `enum`, `class`, `typedef`/`using` |

### Built-in types (typical sizes on a 64-bit system)

| Type | Size | Typical range / use |
|------|------|---------------------|
| `char` | 1 byte | −128 to 127 (a single character) |
| `bool` | 1 byte | `true` (1) or `false` (0) |
| `short` | 2 bytes | −32,768 to 32,767 |
| `int` | 4 bytes | −2,147,483,648 to 2,147,483,647 |
| `long` | 4 or 8 bytes | Depends on the system (8 on 64-bit Linux/macOS, 4 on Windows) |
| `long long` | 8 bytes | About ±9.2 × 10¹⁸ |
| `float` | 4 bytes | About 6–7 decimal digits of precision |
| `double` | 8 bytes | About 15–16 decimal digits of precision |
| `long double` | 8–16 bytes | Extended precision (system dependent) |

### Type modifiers

`signed`, `unsigned`, `short` and `long` modify the size or range of a type.

| Declaration | Meaning | Range (4-byte int) |
|-------------|---------|--------------------|
| `int` / `signed int` | Positive and negative | −2,147,483,648 to 2,147,483,647 |
| `unsigned int` | Only non-negative | 0 to 4,294,967,295 |
| `unsigned char` | Only non-negative | 0 to 255 |

### The `sizeof` operator

`sizeof` returns the size (in bytes) of a type or variable.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    cout << "char        : " << sizeof(char) << endl;
    cout << "bool        : " << sizeof(bool) << endl;
    cout << "short       : " << sizeof(short) << endl;
    cout << "int         : " << sizeof(int) << endl;
    cout << "long long   : " << sizeof(long long) << endl;
    cout << "float       : " << sizeof(float) << endl;
    cout << "double      : " << sizeof(double) << endl;
    cout << "variable n  : " << sizeof(n) << endl;
    return 0;
}
```

**Output (typical)**

```
char        : 1
bool        : 1
short       : 2
int         : 4
long long   : 8
float       : 4
double      : 8
variable n  : 4
```

> Sizes can vary between compilers and systems, so always use `sizeof` rather than assuming.

### `float` vs `double`

```cpp
#include <iostream>
using namespace std;

int main() {
    float  f = 3.14159265358979f;
    double d = 3.14159265358979;
    cout.precision(15);
    cout << "float : " << f << endl;
    cout << "double: " << d << endl;
    return 0;
}
```

**Output (typical)**

```
float : 3.14159274101257
double: 3.14159265358979
```

The `float` loses accuracy after about 7 digits; `double` keeps about 15.

### The `bool` type

```cpp
bool isPassed = true;
cout << isPassed << endl;       // prints 1
cout << boolalpha << isPassed;  // prints true
```

Any non-zero value converts to `true`; zero converts to `false`.

### The `char` type and ASCII

A `char` stores a character as its **ASCII code**.

```cpp
char ch = 'A';
cout << ch << endl;        // A
cout << (int)ch << endl;   // 65
cout << (char)(ch + 1);    // B
```

### User-defined types (preview)

```cpp
struct Student {        // struct groups related data
    int rollNo;
    float marks;
};

enum Color { RED, GREEN, BLUE };   // RED=0, GREEN=1, BLUE=2
```

These are covered in detail in later chapters.

**Key takeaways**
- Choose the smallest type that safely holds your data; use `double` for decimals by default.
- Use `sizeof` to check sizes.
- `char` is really a small integer holding an ASCII code.

---

## 6. Variables and Constants

### Variables

A **variable** is a named memory location whose value can change.

```cpp
int age;              // declaration
age = 20;             // assignment
int marks = 85;       // declaration + initialization
int a = 1, b = 2, c;  // multiple variables in one line
```

> **Always initialize variables.** A local variable that is not initialized contains an unpredictable ("garbage") value.

### Constants

A **constant** is a value that cannot change after it is set.

```cpp
#include <iostream>
using namespace std;

#define MAX 100                 // preprocessor constant (no type, no semicolon)

int main() {
    const double PI = 3.14159;  // typed constant (preferred)
    // PI = 3.14;               // ERROR: cannot modify a const

    cout << "PI  = " << PI << endl;
    cout << "MAX = " << MAX << endl;
    return 0;
}
```

**Output**

```
PI  = 3.14159
MAX = 100
```

| Feature | `const` | `#define` |
|---------|---------|-----------|
| Has a type | Yes | No (text substitution) |
| Handled by | Compiler | Preprocessor |
| Respects scope | Yes | No |
| Ends with `;` | Yes | No |
| Preferred in C++ | ✅ | Use sparingly |

### Literals

| Literal | Type | Example |
|---------|------|---------|
| Integer | `int` | `10`, `-5`, `0` |
| Long / unsigned | `long`, `unsigned` | `10L`, `10U` |
| Floating point | `double` | `3.14`, `2.5e3` (= 2500) |
| Float | `float` | `3.14f` |
| Character | `char` | `'A'`, `'7'` |
| String | `const char[]` | `"Hello"` |
| Boolean | `bool` | `true`, `false` |

### Scope of variables

**Scope** is the region of the program where a variable can be used.

| Scope | Where declared | Lifetime |
|-------|---------------|----------|
| **Local** | Inside a function or block | Until the block ends |
| **Global** | Outside all functions | Entire program |

### The scope resolution operator `::`

If a local variable has the same name as a global one, the local variable hides the global. Use `::` to reach the global one.

```cpp
#include <iostream>
using namespace std;

int x = 100;                // global

int main() {
    int x = 10;             // local, hides the global x
    cout << "Local x   = " << x << endl;
    cout << "Global x  = " << ::x << endl;

    {                       // inner block
        int x = 5;          // hides the outer local x
        cout << "Inner x   = " << x << endl;
    }
    cout << "Back to x = " << x << endl;
    return 0;
}
```

**Output**

```
Local x   = 10
Global x  = 100
Inner x   = 5
Back to x = 10
```

**Key takeaways**
- Initialize variables when you declare them.
- Prefer `const` over `#define` for constants.
- Inner scopes can hide outer variables; `::x` accesses the global one.

---

## 7. Input and Output

C++ performs I/O through **streams**. A stream is a flow of data between your program and a device.

| Object | Meaning | Operator |
|--------|---------|----------|
| `cout` | Standard output (screen) | `<<` insertion |
| `cin` | Standard input (keyboard) | `>>` extraction |
| `cerr` | Standard error (unbuffered) | `<<` |
| `clog` | Standard log (buffered) | `<<` |

### Output with `cout`

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    cout << "Hello" << endl;               // text + newline
    cout << "n = " << n << endl;           // chaining text and variable
    cout << "Sum: " << 2 + 3 << endl;      // expressions are evaluated
    cout << "Line1\nLine2" << endl;        // \n inside the string
    return 0;
}
```

**Output**

```
Hello
n = 5
Sum: 5
Line1
Line2
```

### Escape sequences

| Sequence | Meaning |
|----------|---------|
| `\n` | New line |
| `\t` | Horizontal tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\'` | Single quote |
| `\0` | Null character |
| `\a` | Alert (beep) |

```cpp
cout << "Name:\tAnkith\n";
cout << "She said \"Hi\"\n";
cout << "Path: C:\\Users\n";
```

**Output**

```
Name:	Ankith
She said "Hi"
Path: C:\Users
```

### `endl` vs `\n`

| | `endl` | `'\n'` |
|---|--------|--------|
| Moves to a new line | Yes | Yes |
| Flushes the output buffer | Yes | No |
| Speed | Slower | Faster |

Use `'\n'` for ordinary output and `endl` when you need the output flushed immediately.

### Input with `cin`

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old." << endl;
    return 0;
}
```

**Sample run** (user types `20`)

```
Enter your age: 20
You are 20 years old.
```

### Reading multiple values (chaining `>>`)

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;                       // separated by space or Enter
    cout << "Sum = " << a + b << endl;
    return 0;
}
```

**Sample run**

```
Enter two numbers: 12 8
Sum = 20
```

### Reading text: `cin` vs `getline`

`cin >> name` stops reading at the **first whitespace**, so it cannot read a full name with spaces. Use `getline` for whole lines.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, full;

    cout << "Enter your first name: ";
    cin >> first;                        // reads one word only
    cout << "Hello, " << first << endl;

    cin.ignore(1000, '\n');              // discard leftover newline (see below)

    cout << "Enter your full name: ";
    getline(cin, full);                  // reads the entire line
    cout << "Full name: " << full << endl;
    return 0;
}
```

**Sample run**

```
Enter your first name: Ankith Kumar
Hello, Ankith
Enter your full name: Ankith Kumar Sharma
Full name: Ankith Kumar Sharma
```

> **Why `cin.ignore()`?** After `cin >> first`, the Enter key (and any extra text such as " Kumar" in the run above) remains in the input buffer. `getline` would immediately read that leftover and return. `cin.ignore(1000, '\n')` throws away everything up to and including the newline. In the sample run above, the leftover " Kumar" is discarded, and the user is then prompted for the full name.

### Reading single characters

```cpp
char c;
cin >> c;        // skips whitespace, reads one non-space character
c = cin.get();   // reads the very next character, including space/newline
```

**Key takeaways**
- `cout <<` writes, `cin >>` reads; both can be chained.
- `cin >>` stops at whitespace; use `getline` for full lines.
- Clear leftover input with `cin.ignore()` before `getline` that follows `cin >>`.

---

## 8. Manipulators

**Manipulators** change how data is formatted in a stream. Those with arguments need `<iomanip>`.

| Manipulator | Header | Effect |
|-------------|--------|--------|
| `endl` | `<iostream>` | New line and flush |
| `setw(n)` | `<iomanip>` | Sets the field width to `n` for the **next** output only |
| `setfill(c)` | `<iomanip>` | Fills unused width with character `c` |
| `setprecision(n)` | `<iomanip>` | Number of significant digits (or decimals with `fixed`) |
| `fixed` | `<iostream>` | Fixed-point notation |
| `scientific` | `<iostream>` | Scientific notation |
| `left` / `right` | `<iostream>` | Alignment inside the field |
| `boolalpha` | `<iostream>` | Prints `true`/`false` instead of `1`/`0` |
| `showpoint` | `<iostream>` | Always shows the decimal point |

### `setw` – field width

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << "Name" << setw(8) << "Marks" << endl;
    cout << setw(10) << "Asha"  << setw(8) << 92 << endl;
    cout << setw(10) << "Ravi"  << setw(8) << 85 << endl;
    return 0;
}
```

**Output** (right-aligned by default)

```
      Name   Marks
      Asha      92
      Ravi      85
```

### `setfill` and `left`

```cpp
cout << setfill('*') << setw(10) << 42 << endl;
cout << left << setfill('-') << setw(10) << 42 << endl;
```

**Output**

```
********42
42--------
```

### `setprecision`, `fixed`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265;

    cout << pi << endl;                                // default: 6 significant digits
    cout << setprecision(4) << pi << endl;             // 4 significant digits
    cout << fixed << setprecision(2) << pi << endl;    // 2 digits AFTER the point
    cout << fixed << setprecision(0) << 2.5 << endl;   // 0 digits after the point
    return 0;
}
```

**Output**

```
3.14159
3.142
3.14
2
```

> Without `fixed`, `setprecision(n)` counts **significant digits**. With `fixed`, it counts **digits after the decimal point**. Note that `fixed` and `setprecision` stay in effect for later output until changed.

### A formatted report

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left  << setw(10) << "Item"
         << right << setw(8)  << "Qty"
         << right << setw(10) << "Price" << endl;
    cout << setfill('=') << setw(28) << "" << setfill(' ') << endl;

    cout << fixed << setprecision(2);
    cout << left  << setw(10) << "Pen"
         << right << setw(8)  << 10
         << right << setw(10) << 5.5 << endl;
    cout << left  << setw(10) << "Notebook"
         << right << setw(8)  << 3
         << right << setw(10) << 42.75 << endl;
    return 0;
}
```

**Output**

```
Item           Qty     Price
============================
Pen             10      5.50
Notebook         3     42.75
```

**Key takeaways**
- `setw` applies to the next item only; `setfill`, `fixed`, `setprecision`, `left`/`right` persist.
- `fixed` + `setprecision(n)` is the standard way to print `n` decimal places.

---

## 9. Operators

An **operator** performs an operation on one or more **operands**.

| By number of operands | Examples |
|-----------------------|----------|
| Unary | `++`, `--`, `!`, `-` (negation), `sizeof` |
| Binary | `+`, `-`, `*`, `/`, `%`, `==`, `&&` |
| Ternary | `?:` |

### 9.1 Arithmetic operators

| Operator | Meaning | Example (`a=17`, `b=5`) | Result |
|----------|---------|------------------------|--------|
| `+` | Addition | `a + b` | 22 |
| `-` | Subtraction | `a - b` | 12 |
| `*` | Multiplication | `a * b` | 85 |
| `/` | Division | `a / b` | 3 |
| `%` | Modulus (remainder) | `a % b` | 2 |

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 17, b = 5;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;          // integer division
    cout << "a % b = " << a % b << endl;
    cout << "a / 5.0 = " << a / 5.0 << endl;      // floating-point division
    return 0;
}
```

**Output**

```
a + b = 22
a - b = 12
a * b = 85
a / b = 3
a % b = 2
a / 5.0 = 3.4
```

> **Important:** dividing two integers gives an integer (the fractional part is dropped). `%` works only with integers. The sign of `a % b` follows `a` (so `-17 % 5` is `-2`).

### 9.2 Increment and decrement

| Form | Name | Behaviour |
|------|------|-----------|
| `++x` | Pre-increment | Increase `x` first, then use it |
| `x++` | Post-increment | Use `x` first, then increase it |
| `--x` | Pre-decrement | Decrease first, then use |
| `x--` | Post-decrement | Use first, then decrease |

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int a = x++;     // a gets 5, then x becomes 6
    cout << "a = " << a << ", x = " << x << endl;

    int y = 5;
    int b = ++y;     // y becomes 6, then b gets 6
    cout << "b = " << b << ", y = " << y << endl;
    return 0;
}
```

**Output**

```
a = 5, x = 6
b = 6, y = 6
```

> Do not modify and use the same variable more than once in one expression (for example `x++ + ++x`). The result is undefined behaviour.

### 9.3 Assignment and compound assignment

| Operator | Equivalent to |
|----------|---------------|
| `x = 5` | Assign 5 to `x` |
| `x += 3` | `x = x + 3` |
| `x -= 3` | `x = x - 3` |
| `x *= 3` | `x = x * 3` |
| `x /= 3` | `x = x / 3` |
| `x %= 3` | `x = x % 3` |

```cpp
int x = 10;
x += 5;   // 15
x *= 2;   // 30
x -= 10;  // 20
x /= 4;   // 5
x %= 3;   // 2
cout << x;   // 2
```

### 9.4 Relational operators

They compare two values and give `true` (1) or `false` (0).

| Operator | Meaning | Example (`a=7`, `b=3`) | Result |
|----------|---------|-----------------------|--------|
| `==` | Equal to | `a == b` | 0 |
| `!=` | Not equal to | `a != b` | 1 |
| `>` | Greater than | `a > b` | 1 |
| `<` | Less than | `a < b` | 0 |
| `>=` | Greater than or equal | `a >= 7` | 1 |
| `<=` | Less than or equal | `a <= b` | 0 |

```cpp
int a = 7, b = 3;
cout << (a > b) << endl;     // 1
cout << (a == b) << endl;    // 0
cout << (a != b) << endl;    // 1
```

> Use parentheses around relational expressions inside `cout`, because `<<` has higher precedence than `>`.

### 9.5 Logical operators

| Operator | Name | Result |
|----------|------|--------|
| `&&` | AND | True only if **both** are true |
| `\|\|` | OR | True if **at least one** is true |
| `!` | NOT | Reverses true/false |

**Truth table**

| A | B | `A && B` | `A \|\| B` | `!A` |
|---|---|----------|-----------|------|
| 1 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 0 | 0 | 0 | 0 | 1 |

```cpp
int a = 5, b = 10, c = 15;
cout << (a < b && b < c) << endl;    // 1  (both true)
cout << (a > b || c > b) << endl;    // 1  (second is true)
cout << !(a > b) << endl;            // 1  (a > b is false, NOT makes it true)
```

**Short-circuit evaluation:** `&&` stops at the first false operand; `||` stops at the first true operand. The remaining operands are not evaluated.

```cpp
int x = 0, y = 5;
if (x != 0 && (y / x) > 1) { }   // safe: y / x is never evaluated because x != 0 is false
```

### 9.6 Bitwise operators

They work on the individual **bits** of integers.

| Operator | Name | Rule |
|----------|------|------|
| `&` | AND | 1 if both bits are 1 |
| `\|` | OR | 1 if at least one bit is 1 |
| `^` | XOR | 1 if bits are different |
| `~` | NOT | Flips every bit |
| `<<` | Left shift | Shifts bits left (multiplies by 2 per shift) |
| `>>` | Right shift | Shifts bits right (divides by 2 per shift) |

With `a = 12` (`1100`) and `b = 10` (`1010`):

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 12, b = 10;       //  a = 1100, b = 1010
    cout << (a & b)  << endl; // 1000 = 8
    cout << (a | b)  << endl; // 1110 = 14
    cout << (a ^ b)  << endl; // 0110 = 6
    cout << (~a)     << endl; // -13  (two's complement: ~n = -(n+1))
    cout << (a << 1) << endl; // 11000 = 24
    cout << (a >> 1) << endl; // 0110  = 6
    return 0;
}
```

**Output**

```
8
14
6
-13
24
6
```

### 9.7 Ternary (conditional) operator

**Syntax:** `condition ? value_if_true : value_if_false;`

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 15, b = 22;
    int larger = (a > b) ? a : b;
    cout << "Larger = " << larger << endl;

    int n = 7;
    cout << n << " is " << ((n % 2 == 0) ? "Even" : "Odd") << endl;
    return 0;
}
```

**Output**

```
Larger = 22
7 is Odd
```

### 9.8 Other useful operators

| Operator | Purpose | Example |
|----------|---------|---------|
| `sizeof` | Size in bytes | `sizeof(int)` |
| `,` (comma) | Evaluates left to right, value is the last | `x = (1, 2, 3);` gives `x = 3` |
| `::` | Scope resolution | `::x` |
| `&` (unary) | Address of | `&x` (see Pointers chapter) |
| `*` (unary) | Dereference | `*p` (see Pointers chapter) |

**Key takeaways**
- Integer `/` truncates; `%` gives the remainder.
- Pre-increment uses the new value; post-increment uses the old value.
- Don't confuse `=` (assignment) with `==` (comparison), or `&&` with `&`.

---

## 10. Precedence and Associativity

When an expression has several operators, **precedence** decides which is applied first and **associativity** decides the order among operators of equal precedence.

### Precedence table (highest to lowest)

| Level | Operators | Associativity |
|-------|-----------|---------------|
| 1 | `()` `[]` `.` `->` `x++` `x--` | Left to right |
| 2 | `++x` `--x` `!` `~` unary `+` `-` `sizeof` `(type)` | Right to left |
| 3 | `*` `/` `%` | Left to right |
| 4 | `+` `-` | Left to right |
| 5 | `<<` `>>` | Left to right |
| 6 | `<` `<=` `>` `>=` | Left to right |
| 7 | `==` `!=` | Left to right |
| 8 | `&` | Left to right |
| 9 | `^` | Left to right |
| 10 | `\|` | Left to right |
| 11 | `&&` | Left to right |
| 12 | `\|\|` | Left to right |
| 13 | `?:` | Right to left |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` | Right to left |
| 15 | `,` | Left to right |

### Worked trace 1

```cpp
int r = 10 + 5 * 2 - 8 / 4;
```

| Step | Expression | Reason |
|------|-----------|--------|
| 1 | `5 * 2` → 10 | `*` before `+`/`-` |
| 2 | `8 / 4` → 2 | `/` same level as `*`, left to right |
| 3 | `10 + 10 - 2` | Now only `+` and `-` remain |
| 4 | `20 - 2` → **18** | Left to right |

### Worked trace 2

```cpp
int r = 2 + 3 * 4 % 5;
```

| Step | Expression | Reason |
|------|-----------|--------|
| 1 | `3 * 4` → 12 | `*` and `%` are equal, left to right |
| 2 | `12 % 5` → 2 | Next operator at the same level |
| 3 | `2 + 2` → **4** | `+` is lower |

### Worked trace 3 (logical and relational)

```cpp
int a = 5, b = 10, c = 15;
int r = a < b || b > c && c == 15;
```

| Step | Expression | Reason |
|------|-----------|--------|
| 1 | `a < b` → 1; `b > c` → 0; `c == 15` → 1 | Relational/equality first |
| 2 | `0 && 1` → 0 | `&&` has higher precedence than `\|\|` |
| 3 | `1 \|\| 0` → **1** | Finally `\|\|` |

### Worked trace 4 (associativity of assignment)

```cpp
int a, b, c;
a = b = c = 5;   // right to left: c = 5, then b = c, then a = b
cout << a << b << c;   // 555
```

> **Tip:** when in doubt, use **parentheses**. They make the order explicit and your code easier to read: `(a < b) || ((b > c) && (c == 15))`.

**Key takeaways**
- Remember the order: unary → `* / %` → `+ -` → shifts → relational → equality → `&` → `^` → `|` → `&&` → `||` → `?:` → assignment.
- Use parentheses to avoid mistakes.

---

## 11. Type Conversion

Converting a value from one data type to another is called **type conversion**.

### 11.1 Implicit conversion (automatic)

The compiler converts types automatically, usually towards the "wider" type.

**Promotion order:** `char` / `short` → `int` → `unsigned int` → `long` → `long long` → `float` → `double` → `long double`

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 5;
    double d = 2.5;
    cout << i + d << endl;        // int promoted to double: 7.5

    cout << 'a' + 1 << endl;      // char promoted to int: 98

    int x = 3.99;                 // double -> int: fractional part is dropped
    cout << x << endl;            // 3
    return 0;
}
```

**Output**

```
7.5
98
3
```

> Converting from a wider type to a narrower one (`double` → `int`) **loses data**. It truncates (does not round).

### 11.2 Explicit conversion (casting)

You tell the compiler to convert.

```cpp
(type) expression          // C-style cast
type(expression)           // functional cast
static_cast<type>(expression)   // C++ style cast (preferred)
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;

    cout << a / b << endl;                       // 3   (integer division)
    cout << (double)a / b << endl;               // 3.5 (a converted first)
    cout << static_cast<double>(a) / b << endl;  // 3.5 (C++ style)
    cout << (double)(a / b) << endl;             // 3   (division happens BEFORE the cast)

    char c = 'A';
    cout << (int)c << endl;                      // 65
    cout << (char)(c + 2) << endl;               // C
    return 0;
}
```

**Output**

```
3
3.5
3.5
3
65
C
```

### Common use: average of integers

```cpp
int sum = 17, count = 4;
double wrong = sum / count;                      // 4    (integer division first)
double right = static_cast<double>(sum) / count; // 4.25
cout << wrong << " " << right;
```

**Output**

```
4 4.25
```

### Summary

| Type | Who does it | Example |
|------|-------------|---------|
| Implicit | Compiler | `double d = 5;` (5 becomes 5.0) |
| Explicit | Programmer | `(double)a / b` |

**Key takeaways**
- Narrowing conversions lose data (truncation, not rounding).
- In `(double)a / b`, the cast applies to `a` only, not to the whole expression.
- To get a decimal result from two integers, cast at least one operand.

---

## Common Mistakes

| # | Mistake | Wrong | Correct |
|---|---------|-------|---------|
| 1 | Missing semicolon | `int x = 5` | `int x = 5;` |
| 2 | `=` instead of `==` in a condition | `if (x = 5)` | `if (x == 5)` |
| 3 | Uninitialized variable | `int sum; sum += 10;` | `int sum = 0; sum += 10;` |
| 4 | Wrong stream operator | `cin << n;` / `cout >> n;` | `cin >> n;` / `cout << n;` |
| 5 | Forgetting `std::` or `using namespace std;` | `cout << "Hi";` with no namespace | Add `using namespace std;` or write `std::cout` |
| 6 | Integer division surprise | `double avg = 7 / 2;` → `3` | `double avg = 7 / 2.0;` → `3.5` |
| 7 | `getline` after `cin >>` skips input | No `cin.ignore()` | Add `cin.ignore(1000, '\n');` |
| 8 | Invalid identifier | `int 2nd;`, `int class;` | `int second;`, `int cls;` |
| 9 | `&` instead of `&&` (or `\|` vs `\|\|`) | `if (a > 0 & b > 0)` | `if (a > 0 && b > 0)` |
| 10 | Semicolon after `#define` | `#define MAX 100;` | `#define MAX 100` |
| 11 | Modifying a `const` | `const int n = 5; n = 6;` | Do not modify constants |
| 12 | Using `%` with floating-point | `5.5 % 2` | Use `fmod(5.5, 2)` from `<cmath>` |

---

## Trace-the-Output Exercises

Work out the output by hand first, then open the answer.

**Q1.**

```cpp
int a = 10, b = 3;
cout << a / b << " " << a % b << " " << a / (double)b;
```

<details>
<summary>Answer</summary>

```
3 1 3.33333
```

`10/3` = 3 (integer division), `10%3` = 1, and `10/3.0` = 3.33333 (6 significant digits by default).
</details>

**Q2.**

```cpp
int x = 5;
cout << x++ << endl;
cout << ++x << endl;
```

<details>
<summary>Answer</summary>

```
5
7
```

`x++` prints 5 and then `x` becomes 6. `++x` makes `x` 7 and then prints 7.
</details>

**Q3.**

```cpp
cout << (5 > 3) << (3 > 5) << (5 == 5);
```

<details>
<summary>Answer</summary>

```
101
```

True → 1, false → 0, true → 1, printed without spaces.
</details>

**Q4.**

```cpp
int a = 6, b = 3;
cout << (a & b) << " " << (a | b) << " " << (a ^ b);
```

<details>
<summary>Answer</summary>

```
2 7 5
```

`6 = 110`, `3 = 011`. AND = `010` = 2, OR = `111` = 7, XOR = `101` = 5.
</details>

**Q5.**

```cpp
cout << 10 + 5 * 2 << " " << (10 + 5) * 2 << " " << 20 / 3 * 3;
```

<details>
<summary>Answer</summary>

```
20 30 18
```

`10 + 10` = 20. `15 * 2` = 30. `20 / 3` = 6, then `6 * 3` = 18 (left to right).
</details>

**Q6.**

```cpp
char c = 'A';
c += 2;
cout << c << " " << (int)c;
```

<details>
<summary>Answer</summary>

```
C 67
```

`'A'` is 65, adding 2 gives 67, which is `'C'`.
</details>

**Q7.**

```cpp
cout << setw(5) << 42 << setw(5) << 7;
```

<details>
<summary>Answer</summary>

```
   42    7
```

Each number is right-aligned in a field of width 5: three spaces + `42`, then four spaces + `7`.
</details>

**Q8.**

```cpp
cout << 1 / 2 << " " << 1.0 / 2 << " " << 1 / 2.0;
```

<details>
<summary>Answer</summary>

```
0 0.5 0.5
```

`1/2` is integer division (0). If either operand is a double, the result is a double.
</details>

**Q9.**

```cpp
int a = 5, b = 10;
int r = (a > b) ? a : b;
cout << r << " " << (a < b && b != 10);
```

<details>
<summary>Answer</summary>

```
10 0
```

`a > b` is false, so `r = b = 10`. For the second expression, `a < b` is true but `b != 10` is false, so `true && false` = 0.
</details>

**Q10.**

```cpp
int x = 7;
x += 3;
x *= 2;
x %= 6;
cout << x;
```

<details>
<summary>Answer</summary>

```
2
```

`7+3` = 10, `10*2` = 20, `20%6` = 2.
</details>

---

## Debug-the-Code Exercises

Each program has one or more errors. Find and fix them.

**D1.**

```cpp
#include <iostream>
int main() {
    int age = 20
    cout << "Age: " << age;
    return 0;
}
```

<details>
<summary>Answer</summary>

**Errors:** (1) missing semicolon after `20`; (2) `cout` is not declared because there is no `using namespace std;` (or `std::`).

```cpp
#include <iostream>
using namespace std;
int main() {
    int age = 20;
    cout << "Age: " << age;
    return 0;
}
```
</details>

**D2.**

```cpp
#include <iostream>
using namespace std;
int main() {
    int x = 3;
    if (x = 5)
        cout << "x is five";
    else
        cout << "x is not five";
    return 0;
}
```

<details>
<summary>Answer</summary>

**Error:** `x = 5` is an assignment (it sets `x` to 5, which is non-zero, so the condition is always true). Use `==`:

```cpp
if (x == 5)
```

Correct output for `x = 3` is `x is not five`.
</details>

**D3.**

```cpp
#include <iostream>
using namespace std;
int main() {
    int sum;
    sum += 5;
    cout << sum;
    return 0;
}
```

<details>
<summary>Answer</summary>

**Error:** `sum` is uninitialized, so it holds garbage and `sum += 5` gives an unpredictable result. Fix: `int sum = 0;`
</details>

**D4.**

```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    cout >> "Enter n: ";
    cin << n;
    cout << "n = " << n;
    return 0;
}
```

<details>
<summary>Answer</summary>

**Errors:** operators are reversed. `cout` uses `<<` and `cin` uses `>>`.

```cpp
cout << "Enter n: ";
cin >> n;
```
</details>

**D5.**

```cpp
#include <iostream>
using namespace std;
int main() {
    int 2ndNumber = 5;
    int class = 3;
    cout << 2ndNumber + class;
    return 0;
}
```

<details>
<summary>Answer</summary>

**Errors:** `2ndNumber` starts with a digit; `class` is a keyword. Rename them:

```cpp
int secondNumber = 5;
int cls = 3;
cout << secondNumber + cls;   // 8
```
</details>

**D6.**

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    int age;
    string name;
    cout << "Age: ";
    cin >> age;
    cout << "Name: ";
    getline(cin, name);
    cout << name << " is " << age;
    return 0;
}
```

<details>
<summary>Answer</summary>

**Problem (logic error):** after `cin >> age`, the newline stays in the buffer, so `getline` reads an empty line and the program never waits for the name. Fix by clearing the buffer:

```cpp
cin >> age;
cin.ignore(1000, '\n');
cout << "Name: ";
getline(cin, name);
```
</details>

**D7.**

```cpp
#include <iostream>
using namespace std;
int main() {
    int a = 7, b = 2;
    double avg = (a + b) / 2;
    cout << "Average = " << avg;
    return 0;
}
```

<details>
<summary>Answer</summary>

**Problem (logic error):** `(a + b) / 2` is integer division, so it gives `4` instead of `4.5`. Fix:

```cpp
double avg = (a + b) / 2.0;
```
</details>

---

## Practice Programs

Write each program yourself first. Sample input/output is given; solutions are hidden below each task.

### P1. Swap two numbers

Read two integers and swap them (a) using a third variable, (b) without a third variable.

```
Input : 4 9
Output: After swap: 9 4
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // (a) using a temporary variable
    int temp = a;
    a = b;
    b = temp;
    cout << "After swap: " << a << " " << b << endl;

    // (b) without a third variable (arithmetic)
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Swapped back: " << a << " " << b << endl;
    return 0;
}
```
</details>

### P2. Simple interest

Read principal, rate (% per year) and time (years). Print the simple interest to 2 decimal places. Formula: `SI = (P × R × T) / 100`.

```
Input : 5000 7.5 2
Output: Simple Interest = 750.00
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double p, r, t;
    cout << "Enter principal, rate, time: ";
    cin >> p >> r >> t;
    double si = (p * r * t) / 100;
    cout << fixed << setprecision(2);
    cout << "Simple Interest = " << si << endl;
    return 0;
}
```
</details>

### P3. Celsius to Fahrenheit

Read a temperature in °C and convert it. Formula: `F = C × 9/5 + 32`.

```
Input : 37
Output: 98.60 F
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;
    double f = c * 9.0 / 5 + 32;    // 9.0 avoids integer division
    cout << fixed << setprecision(2) << f << " F" << endl;
    return 0;
}
```
</details>

### P4. Area and circumference of a circle

Read the radius. Print area (`πr²`) and circumference (`2πr`) up to 2 decimals. Use `const double PI = 3.14159;`.

```
Input : 5
Output: Area = 78.54
        Circumference = 31.42
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double PI = 3.14159;
    double r;
    cout << "Enter radius: ";
    cin >> r;
    cout << fixed << setprecision(2);
    cout << "Area = " << PI * r * r << endl;
    cout << "Circumference = " << 2 * PI * r << endl;
    return 0;
}
```
</details>

### P5. Largest of three numbers (ternary operator)

Read three integers and print the largest using only the ternary operator.

```
Input : 12 45 31
Output: Largest = 45
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    int largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    cout << "Largest = " << largest << endl;
    return 0;
}
```
</details>

### P6. ASCII value of a character

Read a character and print its ASCII code, and the next character in the alphabet order.

```
Input : G
Output: ASCII = 71, Next = H
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "ASCII = " << (int)ch << ", Next = " << (char)(ch + 1) << endl;
    return 0;
}
```
</details>

### P7. Convert seconds to hours, minutes, seconds

Read a number of seconds and print it as `h:m:s`.

```
Input : 3725
Output: 1 hour(s) 2 minute(s) 5 second(s)
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int total;
    cout << "Enter seconds: ";
    cin >> total;
    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = total % 60;
    cout << h << " hour(s) " << m << " minute(s) " << s << " second(s)" << endl;
    return 0;
}
```
</details>

### P8. Rectangle: area, perimeter and a formatted table

Read length and width. Print a neat two-column table with area and perimeter using `setw`.

```
Input : 8 5
Output: Area          40
        Perimeter     26
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int l, w;
    cout << "Enter length and width: ";
    cin >> l >> w;
    cout << left  << setw(12) << "Area"      << right << setw(6) << l * w << endl;
    cout << left  << setw(12) << "Perimeter" << right << setw(6) << 2 * (l + w) << endl;
    return 0;
}
```
</details>

---

## Quick Revision Cheat Sheet

### Program skeleton

```cpp
#include <iostream>
using namespace std;

int main() {
    // statements
    return 0;
}
```

### Data types at a glance

| Type | Size (typical) | Stores |
|------|---------------|--------|
| `char` | 1 | Character / small integer |
| `bool` | 1 | true / false |
| `short` | 2 | Small integer |
| `int` | 4 | Integer |
| `long long` | 8 | Large integer |
| `float` | 4 | Decimal (~7 digits) |
| `double` | 8 | Decimal (~15 digits) |

### I/O at a glance

| Task | Code |
|------|------|
| Print | `cout << x << endl;` |
| Read a value | `cin >> x;` |
| Read a full line | `getline(cin, s);` |
| Clear leftover input | `cin.ignore(1000, '\n');` |
| 2 decimal places | `cout << fixed << setprecision(2) << x;` |
| Field width | `cout << setw(8) << x;` |

### Operators at a glance

| Group | Operators |
|-------|-----------|
| Arithmetic | `+ - * / %` |
| Increment / decrement | `++ --` |
| Relational | `== != > < >= <=` |
| Logical | `&& \|\| !` |
| Bitwise | `& \| ^ ~ << >>` |
| Assignment | `= += -= *= /= %=` |
| Ternary | `cond ? a : b` |

### Precedence (high → low)

`()` → unary (`++ -- ! ~`) → `* / %` → `+ -` → `<< >>` → `< <= > >=` → `== !=` → `&` → `^` → `|` → `&&` → `||` → `?:` → `=` → `,`

### Rules to remember

- Identifiers: letters, digits, `_`; no leading digit; not a keyword; case-sensitive.
- Integer `/` integer = integer. Cast one operand to get a decimal result.
- `=` assigns, `==` compares.
- Initialize every variable.
- `setw` affects only the next output; `fixed`/`setprecision` persist.
- Wider → narrower conversion truncates.

---

## References

1. E. Balagurusamy, *Object Oriented Programming with C++*, 7th ed., McGraw Hill, 2017.
2. Yashavant Kanetkar, *Let Us C++*, 2nd ed., BPB Publications, 2015.
3. Course syllabus: *Programming Fundamentals using C++* (BHCS01), B.Sc. (Hons) Computer Science.

---

*Next chapter: **Chapter 2 – Control Flow** (if/else, switch, loops, pattern printing).*
