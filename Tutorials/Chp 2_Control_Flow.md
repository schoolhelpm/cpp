# C++ Tutorial: Chapter 2 – Control Flow

> **Course:** Programming Fundamentals using C++ (BHCS01) – B.Sc. (Hons) Computer Science
> **Level:** Beginner | **Standard used:** C++17 | **Compiler:** g++
> **Previous chapter:** [Chapter 1 – Basics and Input/Output](Chapter1_Basics_IO.md)

By default a program runs statement by statement, top to bottom. **Control flow statements** let you make decisions, choose between alternatives and repeat work. This chapter covers `if`, `switch`, the three loops, jump statements, tracing, patterns and classic programs. Every concept has **code, output and an explanation**, followed by exam-style exercises.

---

## Table of Contents

- [Prerequisites](#prerequisites)
- [1. Introduction](#1-introduction)
- [2. Conditional Statements](#2-conditional-statements)
- [3. The switch Statement](#3-the-switch-statement)
- [4. The for Loop](#4-the-for-loop)
- [5. The while and do-while Loops](#5-the-while-and-do-while-loops)
- [6. Input Validation Loops](#6-input-validation-loops)
- [7. Jump Statements](#7-jump-statements)
- [8. Loop Tracing and Bugs](#8-loop-tracing-and-bugs)
- [9. Pattern Printing](#9-pattern-printing)
- [10. Classic Programs](#10-classic-programs)
- [11. Choosing the Right Loop](#11-choosing-the-right-loop)
- [12. Number-Theory Mini Programs](#12-number-theory-mini-programs)
- [Common Mistakes](#common-mistakes)
- [Trace-the-Output Exercises](#trace-the-output-exercises)
- [Debug-the-Code Exercises](#debug-the-code-exercises)
- [Practice Programs](#practice-programs)
- [Quick Revision Cheat Sheet](#quick-revision-cheat-sheet)
- [References](#references)

---

## Prerequisites

You should be comfortable with these Chapter 1 ideas:

| Concept | Quick reminder |
|---------|----------------|
| Program skeleton | `#include <iostream>`, `using namespace std;`, `int main() { ... return 0; }` |
| Input/output | `cout << x;` prints, `cin >> x;` reads |
| Relational operators | `==  !=  >  <  >=  <=` give `true` (1) or `false` (0) |
| Logical operators | `&&` (AND), `\|\|` (OR), `!` (NOT) |
| Arithmetic | `/` truncates for integers, `%` gives the remainder |
| `=` vs `==` | `=` assigns, `==` compares |

---

## 1. Introduction

Every program, however large, is built from three basic structures:

| Structure | Meaning | C++ statements |
|-----------|---------|----------------|
| **Sequence** | Run statements one after another | Ordinary statements |
| **Selection** (decision) | Choose one path out of several | `if`, `if-else`, `else-if`, `switch`, `?:` |
| **Iteration** (loop) | Repeat a block of statements | `for`, `while`, `do-while` |

### Flowchart symbols

A **flowchart** is a diagram of a program's logic. Drawing one before coding helps you plan.

| Symbol | Shape | Meaning |
|--------|-------|---------|
| Start / Stop | Oval | Beginning or end of the program |
| Process | Rectangle | Calculation or assignment |
| Input / Output | Parallelogram | Reading or printing |
| Decision | Diamond | A yes/no question with two exits |
| Flow line | Arrow | Direction of execution |

A text version of a decision flowchart (is a number positive?):

```
        [ Start ]
            │
     ▱ Read number n ▱
            │
        < n > 0 ? >
        │Yes      │No
 ▱ Print "Positive" ▱   ▱ Print "Not positive" ▱
        │               │
        └───[ Stop ]────┘
```

### A purely sequential program

```cpp
#include <iostream>
using namespace std;

int main() {
    int length = 8, width = 5;
    int area = length * width;
    int perimeter = 2 * (length + width);
    cout << "Area = " << area << endl;
    cout << "Perimeter = " << perimeter << endl;
    return 0;
}
```

**Output**

```
Area = 40
Perimeter = 26
```

Each statement runs exactly once, in order. There are no decisions or repetition. The rest of the chapter adds those two abilities.

**Key takeaways**
- Programs combine sequence, selection and iteration.
- Plan the logic (flowchart or pseudocode) before writing code.

---

## 2. Conditional Statements

### 2.1 The `if` statement

**Syntax**

```cpp
if (condition) {
    // runs only when the condition is true
}
```

A condition is any expression: `0` means false and **any non-zero value** means true.

```cpp
#include <iostream>
using namespace std;

int main() {
    int marks = 72;
    if (marks >= 40) {
        cout << "You passed." << endl;
    }
    cout << "Program ends." << endl;    // always runs
    return 0;
}
```

**Output**

```
You passed.
Program ends.
```

> If the body has only **one statement**, braces are optional. Always use braces anyway; it prevents bugs when you add a second statement later.

### 2.2 The `if-else` statement

**Syntax**

```cpp
if (condition) {
    // true branch
} else {
    // false branch
}
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 17;
    if (n % 2 == 0)
        cout << n << " is even" << endl;
    else
        cout << n << " is odd" << endl;
    return 0;
}
```

**Output**

```
17 is odd
```

### 2.3 Nested `if`

An `if` placed inside another `if` or `else`. The inner condition is checked only when the outer one allows it.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 15, b = 42, c = 27;
    int largest;

    if (a >= b) {
        if (a >= c) largest = a;
        else        largest = c;
    } else {
        if (b >= c) largest = b;
        else        largest = c;
    }
    cout << "Largest = " << largest << endl;
    return 0;
}
```

**Output**

```
Largest = 42
```

**Trace:** `a >= b` → `15 >= 42` is false → go to `else`; `b >= c` → `42 >= 27` is true → `largest = b = 42`.

### 2.4 The `else-if` ladder

Use it when there are **many mutually exclusive** choices. Conditions are tested from top to bottom, and the **first true one wins**; the rest are skipped.

**Syntax**

```cpp
if (cond1) {
    ...
} else if (cond2) {
    ...
} else if (cond3) {
    ...
} else {
    // none of the above
}
```

```cpp
#include <iostream>
using namespace std;

int main() {
    int marks = 76;
    char grade;

    if (marks >= 90)      grade = 'A';
    else if (marks >= 75) grade = 'B';
    else if (marks >= 60) grade = 'C';
    else if (marks >= 40) grade = 'D';
    else                  grade = 'F';

    cout << "Grade: " << grade << endl;
    return 0;
}
```

**Output**

```
Grade: B
```

`76 >= 90` is false; `76 >= 75` is true, so grade is `'B'` and the remaining tests are skipped. Note that the order matters: you do not need to write `marks >= 75 && marks < 90` because earlier conditions already excluded the higher marks.

### 2.5 Combining conditions: leap year

A year is a leap year if it is divisible by 4 **and not** by 100, **or** it is divisible by 400.

```cpp
#include <iostream>
using namespace std;

int main() {
    int year = 2024;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        cout << year << " is a leap year" << endl;
    else
        cout << year << " is not a leap year" << endl;
    return 0;
}
```

**Output**

```
2024 is a leap year
```

| Year | `%4==0` | `%100!=0` | `%400==0` | Leap? |
|------|---------|-----------|-----------|-------|
| 2024 | true | true | false | ✅ Yes |
| 1900 | true | false | false | ❌ No |
| 2000 | true | false | true | ✅ Yes |
| 2023 | false | true | false | ❌ No |

### 2.6 The dangling else

An `else` always belongs to the **nearest unmatched `if`**, regardless of indentation.

```cpp
int x = 5, y = 10;
if (x > 3)
    if (y > 20)
        cout << "A";
else
    cout << "B";
```

**Output**

```
B
```

The `else` pairs with `if (y > 20)`, not `if (x > 3)`. Here `x > 3` is true, `y > 20` is false, so the `else` runs. If `x` were 1, nothing would print. To pair an `else` with the outer `if`, use braces:

```cpp
if (x > 3) {
    if (y > 20)
        cout << "A";
} else {
    cout << "B";
}
```

### 2.7 Ternary operator as a short `if-else`

```cpp
int a = 8, b = 3;
int max = (a > b) ? a : b;     // same as if-else
cout << max;                   // 8
```

**Key takeaways**
- `if` runs a block conditionally; `if-else` picks one of two; `else-if` picks one of many.
- Any non-zero value is true.
- An `else` binds to the nearest `if`. Use braces to be explicit.
- Never write `=` when you mean `==`.

---

## 3. The switch Statement

`switch` selects one of many blocks by comparing a single expression with fixed values (`case` labels).

**Syntax**

```cpp
switch (expression) {
    case value1:
        // statements
        break;
    case value2:
        // statements
        break;
    default:
        // runs if no case matches
}
```

**Rules**

1. The expression must be an **integer type** (`int`, `char`, `short`, `long`, `enum`, `bool`). Not `float`, `double` or `string`.
2. Each `case` value must be a **constant** and **unique**.
3. `default` is optional and may appear anywhere (usually last).
4. `break` leaves the `switch`. Without it, execution **falls through** to the next case.

### Example: day of the week

```cpp
#include <iostream>
using namespace std;

int main() {
    int day = 3;
    switch (day) {
        case 1: cout << "Monday" << endl;    break;
        case 2: cout << "Tuesday" << endl;   break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl;  break;
        case 5: cout << "Friday" << endl;    break;
        case 6: cout << "Saturday" << endl;  break;
        case 7: cout << "Sunday" << endl;    break;
        default: cout << "Invalid day" << endl;
    }
    return 0;
}
```

**Output**

```
Wednesday
```

### Fall-through (what happens without `break`)

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 2;
    switch (n) {
        case 1: cout << "One\n";
        case 2: cout << "Two\n";       // match: starts here
        case 3: cout << "Three\n";     // keeps running (no break above)
                break;                 // stops here
        case 4: cout << "Four\n";
    }
    return 0;
}
```

**Output**

```
Two
Three
```

Once a case matches, the program runs **every statement below it** until it meets `break` or the end of the `switch`.

### Useful fall-through: grouping cases

Deliberate fall-through lets several values share one block.

```cpp
#include <iostream>
using namespace std;

int main() {
    char ch = 'e';
    switch (ch) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            cout << ch << " is a vowel" << endl;
            break;
        default:
            cout << ch << " is not a vowel" << endl;
    }
    return 0;
}
```

**Output**

```
e is a vowel
```

### Menu-driven calculator

```cpp
#include <iostream>
using namespace std;

int main() {
    double a = 12, b = 4;
    char op = '/';

    switch (op) {
        case '+': cout << "Result = " << a + b << endl; break;
        case '-': cout << "Result = " << a - b << endl; break;
        case '*': cout << "Result = " << a * b << endl; break;
        case '/':
            if (b != 0)
                cout << "Result = " << a / b << endl;
            else
                cout << "Cannot divide by zero" << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
    }
    return 0;
}
```

**Output**

```
Result = 3
```

> **Declaring variables in a case:** wrap the case body in braces if you declare a variable there, e.g. `case 1: { int t = 5; ... break; }`. Otherwise the compiler may complain that a jump crosses the initialization.

### `switch` vs `if-else`

| Feature | `switch` | `if-else` ladder |
|---------|---------|------------------|
| Compares | One expression with constants | Any conditions |
| Ranges (`marks >= 60`) | Not directly | Yes |
| Types allowed | Integer/char/enum | Any (including `float`, strings) |
| Readability for many fixed options | Better | Longer |
| Fall-through | Yes | No |

**Key takeaways**
- Always add `break` unless you want fall-through.
- `switch` works on integer-type expressions and constant, unique case labels.
- Use `if-else` for ranges and complex conditions.

---

## 4. The for Loop

A loop repeats a block while a condition is true. `for` is ideal when you **know how many times** to repeat.

**Syntax**

```cpp
for (initialization; condition; update) {
    // body
}
```

### Order of execution

```
1. initialization   (runs once, at the start)
2. condition        (true → go to 3, false → exit the loop)
3. body
4. update           (then back to step 2)
```

### Example: print 1 to 5

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

**Output**

```
1 2 3 4 5 
```

| Step | `i` | `i <= 5` | Action |
|------|-----|----------|--------|
| Start | 1 | true | print 1 |
| After update | 2 | true | print 2 |
| After update | 3 | true | print 3 |
| After update | 4 | true | print 4 |
| After update | 5 | true | print 5 |
| After update | 6 | false | loop ends |

### Example: sum of 1 to n

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 10, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << "Sum of 1 to " << n << " = " << sum << endl;
    return 0;
}
```

**Output**

```
Sum of 1 to 10 = 55
```

### Example: multiplication table

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 7;
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
    return 0;
}
```

**Output**

```
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
```

### Example: factorial

`n! = 1 × 2 × 3 × ... × n` (and `0! = 1`).

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    long long fact = 1;                 // long long: factorials grow fast
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    cout << n << "! = " << fact << endl;
    return 0;
}
```

**Output**

```
5! = 120
```

### Variations of `for`

| Variation | Code | Effect |
|-----------|------|--------|
| Count down | `for (int i = 5; i >= 1; i--)` | 5 4 3 2 1 |
| Step of 2 | `for (int i = 0; i <= 10; i += 2)` | 0 2 4 6 8 10 |
| Multiple variables | `for (int i = 0, j = 10; i < j; i++, j--)` | `i` and `j` move towards each other |
| Omitted initialization | `int i = 1; for (; i <= 5; i++)` | Variable declared earlier |
| Infinite loop | `for (;;) { ... }` | Runs until a `break` or `return` |

```cpp
for (int i = 0, j = 10; i < j; i++, j--) {
    cout << i << " " << j << endl;
}
```

**Output**

```
0 10
1 9
2 8
3 7
4 6
```

The loop stops when `i` becomes 5 and `j` becomes 5 (`5 < 5` is false).

> **Scope:** a variable declared in the `for` header (`int i`) exists only inside the loop. Using `i` after the loop gives a compile error unless it was declared before.

### Nested `for` loops

A loop inside a loop. The **inner loop runs completely for each iteration of the outer loop.**

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {          // rows
        for (int j = 1; j <= 3; j++) {      // columns
            cout << i * j << "\t";
        }
        cout << endl;
    }
    return 0;
}
```

**Output**

```
1	2	3
2	4	6
3	6	9
```

If the outer loop runs `m` times and the inner `n` times, the body runs `m × n` times.

**Key takeaways**
- `for` = initialization + condition + update in one line.
- The initialization runs once; the condition is tested before every iteration.
- Use `long long` when the result can grow large (factorials, sums).

---

## 5. The while and do-while Loops

### 5.1 The `while` loop (entry-controlled)

The condition is tested **before** each iteration. If it is false at the start, the body never runs.

**Syntax**

```cpp
while (condition) {
    // body (must change something that affects the condition)
}
```

**Example: count the digits of a number**

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 12345, count = 0;
    while (n > 0) {
        n = n / 10;      // remove the last digit
        count++;
    }
    cout << "Digits = " << count << endl;
    return 0;
}
```

**Output**

```
Digits = 5
```

| Pass | `n` before | `n` after `n/10` | `count` |
|------|-----------|------------------|---------|
| 1 | 12345 | 1234 | 1 |
| 2 | 1234 | 123 | 2 |
| 3 | 123 | 12 | 3 |
| 4 | 12 | 1 | 4 |
| 5 | 1 | 0 | 5 |
| Check | 0 | `0 > 0` false → stop | |

### 5.2 The `do-while` loop (exit-controlled)

The condition is tested **after** the body, so the body runs **at least once**.

**Syntax**

```cpp
do {
    // body
} while (condition);      // note the semicolon!
```

**Example: runs once even when the condition is false**

```cpp
int i = 10;
do {
    cout << i << endl;
    i++;
} while (i < 5);
```

**Output**

```
10
```

**Example: repeat until the user says stop**

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    char again;
    do {
        cout << "Enter a number: ";
        cin >> n;
        cout << "Square = " << n * n << endl;
        cout << "Continue (y/n)? ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    cout << "Goodbye!" << endl;
    return 0;
}
```

**Sample run**

```
Enter a number: 4
Square = 16
Continue (y/n)? y
Enter a number: 9
Square = 81
Continue (y/n)? n
Goodbye!
```

### Comparison

| Feature | `for` | `while` | `do-while` |
|---------|-------|---------|------------|
| Condition checked | Before body | Before body | **After** body |
| Minimum runs | 0 | 0 | **1** |
| Typical use | Known count | Unknown count | Menus, validation |
| Semicolon after condition | No | No | **Yes** |

**Key takeaways**
- `while` may run zero times; `do-while` runs at least once.
- Always make sure something inside the loop eventually makes the condition false.
- Do not forget the `;` after `while (...)` in a `do-while`.

---

## 6. Input Validation Loops

Never trust user input. A **validation loop** keeps asking until the value is acceptable.

### Pattern 1: `while` with a priming read

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    while (n <= 0) {
        cout << "Invalid! Enter a positive number: ";
        cin >> n;
    }
    cout << "You entered " << n << endl;
    return 0;
}
```

**Sample run**

```
Enter a positive number: -3
Invalid! Enter a positive number: 0
Invalid! Enter a positive number: 8
You entered 8
```

### Pattern 2: `do-while` (cleaner, no repeated code)

```cpp
#include <iostream>
using namespace std;

int main() {
    int marks;
    do {
        cout << "Enter marks (0-100): ";
        cin >> marks;
        if (marks < 0 || marks > 100)
            cout << "Out of range. Try again." << endl;
    } while (marks < 0 || marks > 100);

    cout << "Accepted: " << marks << endl;
    return 0;
}
```

**Sample run**

```
Enter marks (0-100): 150
Out of range. Try again.
Enter marks (0-100): -5
Out of range. Try again.
Enter marks (0-100): 87
Accepted: 87
```

### Pattern 3: handling non-numeric input

If the user types letters when a number is expected, `cin` enters a **fail state** and stops reading. You must **clear** the error and **discard** the bad input.

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age (1-120): ";
    while (!(cin >> age) || age < 1 || age > 120) {
        cout << "Invalid input. Enter age (1-120): ";
        cin.clear();                  // reset the error flags
        cin.ignore(1000, '\n');       // throw away the bad characters
    }
    cout << "Age = " << age << endl;
    return 0;
}
```

**Sample run**

```
Enter age (1-120): abc
Invalid input. Enter age (1-120): 150
Invalid input. Enter age (1-120): 25
Age = 25
```

| Step | Purpose |
|------|---------|
| `cin >> age` | Returns false in a condition if the read failed |
| `cin.clear()` | Clears the fail state so `cin` works again |
| `cin.ignore(1000, '\n')` | Removes up to 1000 characters up to and including the newline |

> Without `clear()` and `ignore()` the loop above would repeat forever, because the bad text would never be removed from the input buffer.

**Key takeaways**
- Use `do-while` for "ask at least once, repeat if invalid".
- Check **range** (`< 0 || > 100`) and **type** (`cin.fail()` / `!(cin >> x)`).
- After a failed read, call `cin.clear()` and `cin.ignore()`.

---

## 7. Jump Statements

Jump statements transfer control to another place in the program.

| Statement | Effect |
|-----------|--------|
| `break` | Immediately leaves the **innermost** loop or `switch` |
| `continue` | Skips the rest of the current iteration and goes to the next |
| `return` | Leaves the current function (in `main`, ends the program) |
| `goto label;` | Jumps to a label (legal, but avoid it) |

### `break`: leave the loop early

Find the first number between 1 and 100 divisible by both 5 and 7:

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            cout << "First number = " << i << endl;
            break;                       // no need to check the rest
        }
    }
    return 0;
}
```

**Output**

```
First number = 35
```

### `continue`: skip one iteration

Print the odd numbers from 1 to 10:

```cpp
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0)
        continue;           // skip even numbers
    cout << i << " ";
}
```

**Output**

```
1 3 5 7 9 
```

> **Careful with `continue` in `while`/`do-while`:** the update statement may be skipped, causing an infinite loop.
>
> ```cpp
> int i = 0;
> while (i < 10) {
>     if (i % 2 == 0) continue;   // BUG: i++ never runs when i is 0
>     cout << i << " ";
>     i++;
> }
> ```
>
> Fix: increment before `continue`, or restructure the loop. In a `for` loop the update always runs, so `continue` is safe there.

### `break` in nested loops

`break` exits only the **innermost** loop.

```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        if (j == 2) break;          // leaves the inner loop only
        cout << i << "," << j << " ";
    }
}
```

**Output**

```
1,1 2,1 3,1 
```

### `return`

```cpp
int main() {
    int n = -5;
    if (n < 0) {
        cout << "Negative input, exiting." << endl;
        return 1;          // non-zero usually means an error
    }
    cout << "This line is not reached." << endl;
    return 0;
}
```

**Output**

```
Negative input, exiting.
```

> `goto` makes code hard to follow; structured statements (`if`, loops, `break`, `continue`, functions) can do everything it can.

**Key takeaways**
- `break` ends the loop; `continue` skips to the next iteration.
- Both affect only the innermost loop.
- Be careful using `continue` in `while` loops.

---

## 8. Loop Tracing and Bugs

**Dry running** means executing code by hand with a **trace table**, one column per variable, one row per iteration. It is the most important skill for "trace the output" questions.

### Trace 1: `while` loop

```cpp
int i = 1, sum = 0;
while (i <= 4) {
    sum += i * i;
    i++;
}
cout << sum;
```

| Iteration | `i` (at check) | `i <= 4` | `sum` after body | `i` after body |
|-----------|---------------|----------|------------------|----------------|
| 1 | 1 | true | 0 + 1 = 1 | 2 |
| 2 | 2 | true | 1 + 4 = 5 | 3 |
| 3 | 3 | true | 5 + 9 = 14 | 4 |
| 4 | 4 | true | 14 + 16 = 30 | 5 |
| Check | 5 | false | | |

**Output:** `30`

### Trace 2: nested loops

```cpp
for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= i; j++)
        cout << i + j << " ";
```

| `i` | `j` values | Values printed |
|-----|-----------|----------------|
| 1 | 1 | 2 |
| 2 | 1, 2 | 3, 4 |
| 3 | 1, 2, 3 | 4, 5, 6 |

**Output:** `2 3 4 4 5 6 `

### Typical loop bugs

| Bug | Code | What happens | Fix |
|-----|------|--------------|-----|
| **Off-by-one (too few)** | `for (int i = 1; i < 5; i++)` meant to print 1–5 | Prints 1 2 3 4 | Use `i <= 5` |
| **Off-by-one (too many)** | `for (int i = 0; i <= n; i++)` over `n` items | One extra pass | Use `i < n` |
| **Infinite loop (no update)** | `while (i < 5) { cout << i; }` | `i` never changes | Add `i++` |
| **Infinite loop (wrong direction)** | `int i = 10; while (i > 0) { i++; }` | `i` only grows | Use `i--` |
| **Stray semicolon** | `for (int i = 0; i < 3; i++);` | Empty body; next line runs once | Remove the `;` |
| **Assignment in condition** | `while (x = 1)` | Always true (assigns 1) | Use `==` |
| **Uninitialized variable** | `int sum; ... sum += i;` | Garbage result | `int sum = 0;` |

### The stray semicolon in action

```cpp
for (int i = 0; i < 3; i++);       // <-- semicolon ends the loop body
    cout << "Hi" << endl;
```

**Output**

```
Hi
```

The loop runs 3 times doing nothing, then `cout` runs **once**.

> If your program seems to hang, it is probably in an infinite loop. Press **Ctrl + C** in the terminal to stop it, then check each loop's condition and update.

**Key takeaways**
- Trace with a table: one column per variable, one row per iteration.
- Check the first and last iterations carefully (off-by-one).
- Every loop needs a path to a false condition.

---

## 9. Pattern Printing

Pattern problems use **nested loops**:

- The **outer loop** controls the **rows**.
- The **inner loop(s)** control what is printed in each **column** (spaces, then symbols).
- Print `endl` after each row.

### General approach

1. Count the rows → outer loop.
2. For each row, find how many **spaces** and how many **symbols** appear, as a formula of the row number `i`.
3. Write one inner loop per part (spaces, symbols).

### Pattern 1: right-angled triangle

```
*
**
***
****
*****
```

```cpp
int n = 5;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
        cout << "*";
    cout << endl;
}
```

Row `i` has `i` stars.

### Pattern 2: inverted triangle

```
*****
****
***
**
*
```

```cpp
int n = 5;
for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= i; j++)
        cout << "*";
    cout << endl;
}
```

### Pattern 3: number triangle

```
1
12
123
1234
12345
```

```cpp
int n = 5;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
        cout << j;
    cout << endl;
}
```

Print the **column number** `j`.

### Pattern 4: repeated row number

```
1
22
333
4444
```

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
        cout << i;
    cout << endl;
}
```

Print the **row number** `i`.

### Pattern 5: alphabet triangle

```
A
AB
ABC
ABCD
```

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++)
        cout << (char)('A' + j);
    cout << endl;
}
```

`'A' + j` is the ASCII code of the j-th letter; the cast turns it back into a character.

### Pattern 6: pyramid

```
    *
   ***
  *****
 *******
*********
```

```cpp
int n = 5;
for (int i = 1; i <= n; i++) {
    for (int s = 1; s <= n - i; s++)      // leading spaces
        cout << " ";
    for (int j = 1; j <= 2 * i - 1; j++)  // stars
        cout << "*";
    cout << endl;
}
```

| Row `i` | Spaces `n - i` | Stars `2i - 1` |
|---------|---------------|----------------|
| 1 | 4 | 1 |
| 2 | 3 | 3 |
| 3 | 2 | 5 |
| 4 | 1 | 7 |
| 5 | 0 | 9 |

### Pattern 7: hollow square

```
*****
*   *
*   *
*   *
*****
```

```cpp
int n = 5;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == 1 || i == n || j == 1 || j == n)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;
}
```

A star is printed only on the border: first/last row or first/last column.

### Pattern 8: Floyd's triangle

```
1
2 3
4 5 6
7 8 9 10
```

```cpp
int n = 4, num = 1;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        cout << num << " ";
        num++;
    }
    cout << endl;
}
```

A running counter `num` is declared **outside** the loops and keeps increasing.

### Pattern formulas at a glance

| Pattern type | Spaces in row `i` | Symbols in row `i` |
|--------------|-------------------|--------------------|
| Left triangle | 0 | `i` |
| Inverted triangle | 0 | `n - i + 1` |
| Right-aligned triangle | `n - i` | `i` |
| Pyramid | `n - i` | `2i - 1` |
| Inverted pyramid | `i - 1` | `2(n - i) + 1` |

**Key takeaways**
- Outer loop = rows; inner loops = spaces and symbols.
- Express the number of spaces/symbols as a formula in the row number.
- Always print `endl` once per row, after the inner loops.

---

## 10. Classic Programs

### 10.1 Even or odd

A number is even if the remainder on dividing by 2 is 0.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 17;
    cout << n << (n % 2 == 0 ? " is even" : " is odd") << endl;

    // count even numbers from 1 to 10
    int evens = 0;
    for (int i = 1; i <= 10; i++)
        if (i % 2 == 0) evens++;
    cout << "Even numbers from 1 to 10: " << evens << endl;
    return 0;
}
```

**Output**

```
17 is odd
Even numbers from 1 to 10: 5
```

### 10.2 Sum of `n` numbers (read from the user)

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, x, sum = 0;
    cout << "How many numbers? ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Enter number " << i << ": ";
        cin >> x;
        sum += x;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
```

**Sample run**

```
How many numbers? 4
Enter number 1: 10
Enter number 2: 20
Enter number 3: 30
Enter number 4: 40
Sum = 100
```

### 10.3 Reverse the digits of a number

Peel off the last digit with `% 10`, append it to the reversed number with `rev * 10 + digit`, and drop it from `n` with `/ 10`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 1234, rev = 0;
    while (n > 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    cout << "Reversed = " << rev << endl;
    return 0;
}
```

**Output**

```
Reversed = 4321
```

| Pass | `digit = n % 10` | `rev = rev*10 + digit` | `n = n / 10` |
|------|------------------|------------------------|--------------|
| 1 | 4 | 0×10 + 4 = 4 | 123 |
| 2 | 3 | 4×10 + 3 = 43 | 12 |
| 3 | 2 | 43×10 + 2 = 432 | 1 |
| 4 | 1 | 432×10 + 1 = 4321 | 0 |

> Trailing zeros are lost (`1200` becomes `21`), and the program as written handles only positive numbers.

### 10.4 Fibonacci series

Each term is the sum of the previous two: `0, 1, 1, 2, 3, 5, 8, ...`

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    long long a = 0, b = 1;
    cout << "Fibonacci series: ";
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
    return 0;
}
```

**Output**

```
Fibonacci series: 0 1 1 2 3 5 8 13 21 34 
```

| `i` | prints `a` | `next = a + b` | new `a` | new `b` |
|-----|-----------|----------------|---------|---------|
| 1 | 0 | 1 | 1 | 1 |
| 2 | 1 | 2 | 1 | 2 |
| 3 | 1 | 3 | 2 | 3 |
| 4 | 2 | 5 | 3 | 5 |
| 5 | 3 | 8 | 5 | 8 |

**Key takeaways**
- `n % 10` extracts the last digit; `n / 10` removes it.
- Loops that build a result (sum, factorial, reverse) need a properly **initialized** accumulator.
- In Fibonacci, use a temporary variable so no value is overwritten too early.

---

## 11. Choosing the Right Loop

All three loops can do the same job. The right choice makes the code shorter and clearer.

### The same task three ways: print 1 to 5

```cpp
// for
for (int i = 1; i <= 5; i++)
    cout << i << " ";

// while
int i = 1;
while (i <= 5) {
    cout << i << " ";
    i++;
}

// do-while
int k = 1;
do {
    cout << k << " ";
    k++;
} while (k <= 5);
```

All three print `1 2 3 4 5 `.

### Decision guide

```
Do you know in advance how many times to repeat?
 ├─ Yes → for
 └─ No  → Must the body run at least once?
            ├─ Yes → do-while
            └─ No  → while
```

| Situation | Best loop | Why |
|-----------|-----------|-----|
| Print a table, sum 1 to n, factorial | `for` | Count is known; init/condition/update fit on one line |
| Process each digit of a number | `while` | Number of digits unknown; may be zero iterations |
| Read values until the user enters 0 (sentinel) | `while` | Condition depends on input, tested before use |
| Show a menu and repeat until "Exit" | `do-while` | Menu must show at least once |
| Validate input (ask, then re-ask if bad) | `do-while` | Always ask once |
| Nested patterns (rows × columns) | `for` | Two known counts |
| Retry until an operation succeeds | `while` or `do-while` | Count unknown |

### Quick rules

- **Counting** from a start to an end → `for`.
- **Condition-driven** (until something happens) → `while`.
- **At least once** → `do-while`.
- If you find yourself writing `int i = 0;` before a `while` and `i++;` at the end, a `for` is probably cleaner.

**Key takeaways**
- Known count → `for`; unknown count → `while`; at least once → `do-while`.
- Pick the loop whose structure matches the problem.

---

## 12. Number-Theory Mini Programs

These appear often in practicals. Each uses only the tools from this chapter.

### 12.1 Prime number check

A prime has exactly two divisors: 1 and itself. It is enough to test divisors up to √n (the loop condition `i * i <= n`).

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 29;
    bool isPrime = (n > 1);                 // 0 and 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;                          // one divisor is enough
        }
    }
    cout << n << (isPrime ? " is prime" : " is not prime") << endl;
    return 0;
}
```

**Output**

```
29 is prime
```

For 29 the loop tests `i = 2, 3, 4, 5` (since `5 × 5 = 25 <= 29`), finds no divisor and stops at `i = 6`.

### 12.2 Prime numbers in a range

```cpp
#include <iostream>
using namespace std;

int main() {
    int low = 1, high = 30;
    cout << "Primes from " << low << " to " << high << ": ";
    for (int n = low; n <= high; n++) {
        if (n < 2) continue;
        bool isPrime = true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) { isPrime = false; break; }
        }
        if (isPrime) cout << n << " ";
    }
    cout << endl;
    return 0;
}
```

**Output**

```
Primes from 1 to 30: 2 3 5 7 11 13 17 19 23 29 
```

### 12.3 Palindrome number

A number is a palindrome if it reads the same forwards and backwards. Reverse it and compare with the original.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 12321, original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    if (rev == original)
        cout << original << " is a palindrome" << endl;
    else
        cout << original << " is not a palindrome" << endl;
    return 0;
}
```

**Output**

```
12321 is a palindrome
```

Keep a copy (`original`) because the loop destroys `n`. For `123`, `rev` becomes `321`, which differs, so it is not a palindrome.

### 12.4 Armstrong number

An Armstrong number equals the sum of its digits each raised to the power of the **number of digits**. Example: `153 = 1³ + 5³ + 3³ = 1 + 125 + 27`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 153, temp = n, digits = 0;

    while (temp > 0) {            // step 1: count the digits
        digits++;
        temp /= 10;
    }

    temp = n;
    int sum = 0;
    while (temp > 0) {            // step 2: add digit^digits
        int d = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++)
            power *= d;
        sum += power;
        temp /= 10;
    }

    if (sum == n)
        cout << n << " is an Armstrong number" << endl;
    else
        cout << n << " is not an Armstrong number" << endl;
    return 0;
}
```

**Output**

```
153 is an Armstrong number
```

An integer-multiplication loop is used for the power instead of `pow()`, because `pow()` returns a `double` and can introduce rounding errors.

### 12.5 GCD and LCM (Euclid's algorithm)

The **GCD** (greatest common divisor) of `a` and `b` equals the GCD of `b` and `a % b`. Repeat until the remainder is 0. Then `LCM = (a × b) / GCD`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 48, b = 18;
    long long product = (long long)a * b;

    int x = a, y = b;
    while (y != 0) {
        int t = y;
        y = x % y;
        x = t;
    }
    int gcd = x;

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << product / gcd << endl;
    return 0;
}
```

**Output**

```
GCD = 6
LCM = 144
```

| Step | `x` | `y` | `x % y` |
|------|-----|-----|---------|
| 1 | 48 | 18 | 12 |
| 2 | 18 | 12 | 6 |
| 3 | 12 | 6 | 0 |
| End | 6 | 0 | GCD = 6 |

### 12.6 Perfect number

A perfect number equals the sum of its proper divisors (all divisors except itself). Example: `6 = 1 + 2 + 3`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 28, sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            sum += i;
    }
    cout << n << (sum == n ? " is a perfect number" : " is not a perfect number") << endl;
    return 0;
}
```

**Output**

```
28 is a perfect number
```

The proper divisors of 28 are `1, 2, 4, 7, 14`, which add up to 28.

**Key takeaways**
- Use `% 10` and `/ 10` to take numbers apart digit by digit.
- Keep a copy of the original value when the loop modifies it.
- `break` as soon as the answer is known (prime check).

---

## Common Mistakes

| # | Mistake | Wrong | Correct |
|---|---------|-------|---------|
| 1 | `=` instead of `==` in a condition | `if (x = 5)` | `if (x == 5)` |
| 2 | Semicolon right after `if (...)` | `if (x > 5);` | `if (x > 5) { ... }` |
| 3 | Semicolon after `for (...)` / `while (...)` | `for (int i=0;i<3;i++);` | Remove the `;` |
| 4 | Missing `break` in `switch` | `case 1: ... case 2: ...` | Add `break;` after each case |
| 5 | Using `switch` on `float`/`double`/`string` | `switch (price)` | Use `int`/`char`, or `if-else` |
| 6 | Duplicate `case` labels | `case 2: ... case 2:` | Each value only once |
| 7 | Off-by-one in loop bounds | `i < n` vs `i <= n` | Decide whether the end value is included |
| 8 | Loop variable never updated | `while (i < 5) { ... }` | Add `i++` inside the loop |
| 9 | Uninitialized accumulator | `int sum; sum += x;` | `int sum = 0;` |
| 10 | Chained comparison | `if (0 < x < 10)` | `if (0 < x && x < 10)` |
| 11 | Missing `;` after `do-while` | `} while (x < 5)` | `} while (x < 5);` |
| 12 | `continue` skipping the update in `while` | See Section 7 | Update the variable before `continue` |
| 13 | Using the loop variable outside the loop | `for (int i...) ...; cout << i;` | Declare `i` before the loop |
| 14 | Integer overflow in factorial/sum | `int fact` for 15! | Use `long long` |

> **Why `0 < x < 10` is wrong:** it is evaluated as `(0 < x) < 10`. The first part gives `0` or `1`, which is always `< 10`, so the whole condition is always true.

---

## Trace-the-Output Exercises

Work out the output by hand first, then open the answer.

**Q1.**

```cpp
int x = 15;
if (x > 10) cout << "A";
if (x > 20) cout << "B";
else cout << "C";
cout << "D";
```

<details>
<summary>Answer</summary>

```
ACD
```

The first `if` is true (prints `A`). The second `if` is false, so its `else` runs (prints `C`). `D` always prints.
</details>

**Q2.**

```cpp
int n = 2;
switch (n) {
    case 1: cout << "One ";
    case 2: cout << "Two ";
    case 3: cout << "Three "; break;
    default: cout << "Other ";
}
```

<details>
<summary>Answer</summary>

```
Two Three 
```

Case 2 matches, there is no `break`, so it falls through into case 3, which has a `break`.
</details>

**Q3.**

```cpp
for (int i = 1; i <= 10; i += 3)
    cout << i << " ";
```

<details>
<summary>Answer</summary>

```
1 4 7 10 
```

`i` takes the values 1, 4, 7, 10; the next value 13 fails the condition.
</details>

**Q4.**

```cpp
int i = 5;
while (i > 0) {
    cout << i << " ";
    i -= 2;
}
```

<details>
<summary>Answer</summary>

```
5 3 1 
```

After printing 1, `i` becomes `-1`, so `-1 > 0` is false.
</details>

**Q5.**

```cpp
int i = 10;
do {
    cout << i << " ";
    i++;
} while (i < 5);
```

<details>
<summary>Answer</summary>

```
10 
```

A `do-while` runs its body once before testing the condition.
</details>

**Q6.**

```cpp
for (int i = 1; i <= 8; i++) {
    if (i % 2 == 0) continue;
    if (i > 6) break;
    cout << i << " ";
}
```

<details>
<summary>Answer</summary>

```
1 3 5 
```

Even values are skipped. At `i = 7`, it is odd but `7 > 6`, so `break` ends the loop before printing.
</details>

**Q7.**

```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= i; j++)
        cout << j;
    cout << endl;
}
```

<details>
<summary>Answer</summary>

```
1
12
123
```

The inner loop runs `i` times for each row.
</details>

**Q8.**

```cpp
int n = 1234, s = 0;
while (n > 0) {
    s += n % 10;
    n /= 10;
}
cout << s;
```

<details>
<summary>Answer</summary>

```
10
```

Digits added: `4 + 3 + 2 + 1 = 10`.
</details>

**Q9.**

```cpp
int c = 0;
for (int i = 0; i < 5; i++);
    c++;
cout << c;
```

<details>
<summary>Answer</summary>

```
1
```

The semicolon makes the loop body empty. `c++` runs only once, after the loop.
</details>

**Q10.**

```cpp
int a = 0;
if (a = 0) cout << "Zero";
else       cout << "Nonzero";
```

<details>
<summary>Answer</summary>

```
Nonzero
```

`a = 0` is an assignment whose value is `0` (false), so the `else` branch runs. The condition never actually compares anything.
</details>

---

## Debug-the-Code Exercises

Each program has one or more errors. Find and fix them.

**D1.** Expected: print `Good` only.

```cpp
#include <iostream>
using namespace std;
int main() {
    char grade = 'B';
    switch (grade) {
        case 'A': cout << "Excellent";
        case 'B': cout << "Good";
        case 'C': cout << "Fair";
        default:  cout << "Invalid";
    }
    return 0;
}
```

<details>
<summary>Answer</summary>

**Error:** missing `break` statements, so it prints `GoodFairInvalid` (fall-through).

```cpp
switch (grade) {
    case 'A': cout << "Excellent"; break;
    case 'B': cout << "Good";      break;
    case 'C': cout << "Fair";      break;
    default:  cout << "Invalid";
}
```
</details>

**D2.** Expected: print `1 2 3 4 5`.

```cpp
#include <iostream>
using namespace std;
int main() {
    for (int i = 1; i <= 5; i++);
    {
        cout << i << " ";
    }
    return 0;
}
```

<details>
<summary>Answer</summary>

**Error:** the semicolon after the `for` header ends the loop with an empty body. The block that follows is no longer inside the loop, and `i` is out of scope there, which causes a compile error ("`i` was not declared").

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
```
</details>

**D3.** Expected: count down from 10 to 1.

```cpp
int i = 10;
while (i > 0) {
    cout << i << " ";
    i++;
}
```

<details>
<summary>Answer</summary>

**Error:** `i++` moves `i` away from 0, so the loop never ends (infinite loop). Use `i--`.
</details>

**D4.** Expected: even/odd check.

```cpp
int n = 10;
if (n % 2 = 0)
    cout << "Even";
else
    cout << "Odd";
```

<details>
<summary>Answer</summary>

**Error:** `=` is assignment; it does not compile here because `n % 2` is not something you can assign to. Use the comparison `==`:

```cpp
if (n % 2 == 0)
```
</details>

**D5.** Expected: sum of 1 to n.

```cpp
int n = 5;
int sum;
for (int i = 1; i < n; i++)
    sum += i;
cout << sum;
```

<details>
<summary>Answer</summary>

**Two errors:** (1) `sum` is not initialized, so it contains garbage; (2) `i < n` stops one step early (off-by-one) and misses `n`.

```cpp
int sum = 0;
for (int i = 1; i <= n; i++)
    sum += i;       // sum = 15
```
</details>

**D6.** Expected: reverse the digits of 123.

```cpp
int n = 123, rev;
while (n > 0) {
    rev = rev * 10 + n % 10;
    n /= 10;
}
cout << rev;
```

<details>
<summary>Answer</summary>

**Error:** `rev` is uninitialized. Fix: `int n = 123, rev = 0;` The output is then `321`.
</details>

**D7.** Expected: print the name of the chosen option.

```cpp
float choice = 2;
switch (choice) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    case 2: cout << "Again"; break;
}
```

<details>
<summary>Answer</summary>

**Errors:** (1) `switch` cannot use a `float` expression; (2) `case 2` appears twice. Fix:

```cpp
int choice = 2;
switch (choice) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    case 3: cout << "Again"; break;
}
```
</details>

---

## Practice Programs

Write each program yourself first. Sample input/output is given; solutions are hidden below each task.

### P1. Positive, negative or zero

Read an integer and report whether it is positive, negative or zero.

```
Input : -8
Output: Negative
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n > 0)       cout << "Positive" << endl;
    else if (n < 0)  cout << "Negative" << endl;
    else             cout << "Zero" << endl;
    return 0;
}
```
</details>

### P2. Electricity bill

Charges: first 100 units at 5 per unit, the next 100 units at 7 per unit, and anything above 200 at 10 per unit. Read the units and print the bill.

```
Input : 250
Output: Bill = 1700
```

(100 × 5 = 500, 100 × 7 = 700, 50 × 10 = 500, total 1700.)

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int units;
    cout << "Enter units: ";
    cin >> units;

    int bill;
    if (units <= 100)
        bill = units * 5;
    else if (units <= 200)
        bill = 100 * 5 + (units - 100) * 7;
    else
        bill = 100 * 5 + 100 * 7 + (units - 200) * 10;

    cout << "Bill = " << bill << endl;
    return 0;
}
```
</details>

### P3. Calculator with `switch`, repeated with `do-while`

Read two numbers and an operator (`+ - * /`), print the result, and ask whether to continue.

```
Input : 12 * 4, then n
Output: Result = 48
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op, again;
    do {
        cout << "Enter expression (e.g. 12 * 4): ";
        cin >> a >> op >> b;
        switch (op) {
            case '+': cout << "Result = " << a + b << endl; break;
            case '-': cout << "Result = " << a - b << endl; break;
            case '*': cout << "Result = " << a * b << endl; break;
            case '/':
                if (b != 0) cout << "Result = " << a / b << endl;
                else        cout << "Cannot divide by zero" << endl;
                break;
            default: cout << "Invalid operator" << endl;
        }
        cout << "Another calculation (y/n)? ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    return 0;
}
```
</details>

### P4. Multiplication table of any number

Read `n` and print its table from 1 to 10.

```
Input : 5
Output: 5 x 1 = 5
        ...
        5 x 10 = 50
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n * i << endl;
    return 0;
}
```
</details>

### P5. Sum of even numbers and count of odd numbers up to `n`

```
Input : 10
Output: Sum of evens = 30
        Count of odds = 5
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, evenSum = 0, oddCount = 0;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) evenSum += i;
        else            oddCount++;
    }
    cout << "Sum of evens = " << evenSum << endl;
    cout << "Count of odds = " << oddCount << endl;
    return 0;
}
```
</details>

### P6. Number pyramid

Read `n` and print this pattern (shown for `n = 4`):

```
   1
  121
 12321
1234321
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter rows: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)      // leading spaces
            cout << " ";
        for (int j = 1; j <= i; j++)          // ascending 1..i
            cout << j;
        for (int j = i - 1; j >= 1; j--)      // descending i-1..1
            cout << j;
        cout << endl;
    }
    return 0;
}
```
</details>

### P7. Digit count and digit sum

```
Input : 4096
Output: Digits = 4
        Sum of digits = 19
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, count = 0, sum = 0;
    cout << "Enter a positive number: ";
    cin >> n;
    while (n > 0) {
        sum += n % 10;
        count++;
        n /= 10;
    }
    cout << "Digits = " << count << endl;
    cout << "Sum of digits = " << sum << endl;
    return 0;
}
```
</details>

### P8. Harmonic series

Print `1 + 1/2 + 1/3 + ... + 1/n` to 4 decimal places.

```
Input : 4
Output: 2.0833
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double sum = 0;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += 1.0 / i;                 // 1.0 avoids integer division
    cout << fixed << setprecision(4) << sum << endl;
    return 0;
}
```
</details>

### P9. Menu-driven program

Show a menu: `1. Square`, `2. Cube`, `3. Exit`. Repeat until the user chooses Exit.

```
Input : 1, then 5, then 2, then 3, then 3
Output: Square = 25
        Cube = 27
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice, n;
    do {
        cout << "\n1. Square\n2. Cube\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number: ";
                cin >> n;
                cout << "Square = " << n * n << endl;
                break;
            case 2:
                cout << "Enter number: ";
                cin >> n;
                cout << "Cube = " << n * n * n << endl;
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);
    return 0;
}
```
</details>

### P10. Number guessing game

The secret number is 7. Keep asking for guesses, give a "too low" or "too high" hint, and finally print the number of attempts.

```
Input : 3, 9, 7
Output: Too low
        Too high
        Correct! Attempts: 3
```

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    const int SECRET = 7;
    int guess, attempts = 0;
    do {
        cout << "Guess the number: ";
        cin >> guess;
        attempts++;
        if (guess < SECRET)      cout << "Too low" << endl;
        else if (guess > SECRET) cout << "Too high" << endl;
        else                     cout << "Correct! Attempts: " << attempts << endl;
    } while (guess != SECRET);
    return 0;
}
```
</details>

---

## Quick Revision Cheat Sheet

### Selection statements

```cpp
if (cond) { ... }

if (cond) { ... } else { ... }

if (c1) { ... } else if (c2) { ... } else { ... }

switch (intExpr) {
    case 1: ...; break;
    case 2: ...; break;
    default: ...;
}

result = (cond) ? valueIfTrue : valueIfFalse;
```

### Loops

```cpp
for (init; condition; update) { ... }

while (condition) { ... }

do { ... } while (condition);      // note the ;
```

### Jump statements

| Statement | Effect |
|-----------|--------|
| `break` | Exit the innermost loop / `switch` |
| `continue` | Skip to the next iteration |
| `return` | Leave the function |

### Loop comparison

| | `for` | `while` | `do-while` |
|---|-------|---------|------------|
| Test | Before | Before | After |
| Runs at least once | No | No | **Yes** |
| Best for | Known count | Unknown count | Menus / validation |

### Digit toolkit

| Task | Code |
|------|------|
| Last digit | `n % 10` |
| Remove last digit | `n /= 10` |
| Build reverse | `rev = rev * 10 + digit` |
| Count digits | loop `n /= 10` until `n == 0` |

### Pattern toolkit

| Pattern | Spaces in row `i` | Symbols in row `i` |
|---------|-------------------|--------------------|
| Left triangle | 0 | `i` |
| Right-aligned triangle | `n - i` | `i` |
| Pyramid | `n - i` | `2i - 1` |
| Inverted triangle | 0 | `n - i + 1` |

### Rules to remember

- `=` assigns, `==` compares.
- No semicolon after `if (...)`, `for (...)` or `while (...)` (unless you really want an empty body).
- Put `break` in every `switch` case unless fall-through is intended.
- Initialize accumulators: `sum = 0`, `product = 1`.
- `break` and `continue` affect only the innermost loop.
- `do-while` ends with a semicolon and runs at least once.
- Validate input with a loop; after a failed `cin`, call `cin.clear()` and `cin.ignore()`.

---

## References

1. E. Balagurusamy, *Object Oriented Programming with C++*, 7th ed., McGraw Hill, 2017.
2. Yashavant Kanetkar, *Let Us C++*, 2nd ed., BPB Publications, 2015.
3. Course syllabus: *Programming Fundamentals using C++* (BHCS01), B.Sc. (Hons) Computer Science.

---

*Next chapter: **Chapter 3 – Functions** (prototypes, call by value/reference, overloading, recursion).*
