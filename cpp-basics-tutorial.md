# C++ Basics Tutorial: Numbers, Input, a Calculator, and Mad Libs

A hands-on tutorial for graduate students learning C++. By the end you will be able to do math in C++, read input from the user, and build two small interactive programs.

**Prerequisites:** a working C++ compiler (g++, clang++, or MSVC) and familiarity with the basic structure of a C++ program (`#include`, `main()`, `cout`).

**Compile and run any example in this tutorial with:**

```bash
g++ -std=c++17 -Wall -Wextra -o program program.cpp
./program
```

## Table of Contents

1. [Working with Numbers & Math Operations](#1-working-with-numbers--math-operations)
2. [Getting User Input](#2-getting-user-input)
3. [Building a Basic Calculator](#3-building-a-basic-calculator)
4. [Building a Mad Libs Game](#4-building-a-mad-libs-game)
5. [Practice Exercises](#5-practice-exercises)
6. [Quick Reference](#6-quick-reference)

---

## 1. Working with Numbers & Math Operations

### 1.1 Number Types

C++ has several built-in numeric types. For this tutorial, three matter most:

| Type     | Holds                  | Example values       | Notes                                           |
|----------|------------------------|----------------------|-------------------------------------------------|
| `int`    | Whole numbers          | `-5`, `0`, `42`      | No fractional part                              |
| `float`  | Decimal numbers        | `3.14f`, `-0.5f`     | Lower precision (about 6-7 significant digits)  |
| `double` | Decimal numbers        | `3.14159265358979`   | Higher precision (about 15-16 significant digits) |

```cpp
#include <iostream>
using namespace std;

int main() {
    int    wholeNumber = 42;
    float  smallDecimal = 3.14159265358979f;
    double bigDecimal   = 3.14159265358979;

    cout.precision(15);   // show up to 15 significant digits
    cout << "int:    " << wholeNumber  << endl;
    cout << "float:  " << smallDecimal << endl;  // precision is lost
    cout << "double: " << bigDecimal   << endl;  // more accurate
    return 0;
}
```

> **Takeaway:** `double` gives you more precision for decimal places than `float`. Unless you have a specific reason (e.g., memory-constrained arrays), prefer `double` for decimal values.

---

### 1.2 Basic Arithmetic Operators

| Operator | Meaning        | Example   | Result |
|----------|----------------|-----------|--------|
| `+`      | Addition       | `7 + 3`   | `10`   |
| `-`      | Subtraction    | `7 - 3`   | `4`    |
| `*`      | Multiplication | `7 * 3`   | `21`   |
| `/`      | Division       | `6 / 3`   | `2`    |

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << 7 + 3 << endl;   // 10
    cout << 7 - 3 << endl;   // 4
    cout << 7 * 3 << endl;   // 21
    cout << 6 / 3 << endl;   // 2
    return 0;
}
```

---

### 1.3 The Modulus Operator (`%`)

The modulus operator returns the **remainder** of an integer division.

```cpp
cout << 10 % 3 << endl;   // 1   (10 = 3*3 + 1)
cout << 15 % 5 << endl;   // 0   (divides evenly)
cout << 7  % 2 << endl;   // 1   (odd numbers give 1)
```

**Common uses**

- **Even/odd check:** `n % 2 == 0` means `n` is even.
- **Divisibility:** `n % k == 0` means `k` divides `n`.
- **Wrapping around:** `index % size` keeps an index inside `0 ... size-1`.

> **Note:** `%` works only on integer types. Using it with `double` is a compile error. For decimals, use `fmod()` from `<cmath>`.

---

### 1.4 Order of Operations

C++ follows standard mathematical precedence: `*`, `/`, and `%` are evaluated **before** `+` and `-`. Operators at the same level are evaluated left to right.

```cpp
cout << 2 + 3 * 4 << endl;     // 14, not 20  (3*4 first, then +2)
cout << 20 - 8 / 4 << endl;    // 18          (8/4 first, then 20-2)
cout << 10 - 4 - 3 << endl;    // 3           (left to right: (10-4)-3)
```

**Overriding precedence with parentheses `()`**

Anything inside parentheses is evaluated first.

```cpp
cout << (2 + 3) * 4 << endl;       // 20
cout << (20 - 8) / 4 << endl;      // 3
cout << 2 * (3 + 4) * 5 << endl;   // 70
```

> **Best practice:** Even when precedence would give the right answer, add parentheses if it makes the code easier to read.

---

### 1.5 Variable Shorthand & Increments

#### Increment and Decrement

```cpp
int count = 5;
count++;                 // count is now 6  (adds 1)
count--;                 // count is now 5  (subtracts 1)
```

`++` and `--` each come in two forms. For now, use them as standalone statements; the subtle difference between them is covered below.

| Form      | Name        | Behavior                                    |
|-----------|-------------|---------------------------------------------|
| `x++`     | Post-increment | Use the current value, **then** add 1    |
| `++x`     | Pre-increment  | Add 1, **then** use the new value        |

```cpp
int a = 5;
cout << a++ << endl;   // prints 5, then a becomes 6
cout << a   << endl;   // prints 6

int b = 5;
cout << ++b << endl;   // b becomes 6, then prints 6
```

#### Compound Assignment Operators

These combine an arithmetic operation with assignment.

| Shorthand   | Equivalent to    |
|-------------|------------------|
| `x += 3;`   | `x = x + 3;`     |
| `x -= 3;`   | `x = x - 3;`     |
| `x *= 3;`   | `x = x * 3;`     |
| `x /= 3;`   | `x = x / 3;`     |

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    x += 5;  cout << x << endl;   // 15
    x -= 3;  cout << x << endl;   // 12
    x *= 2;  cout << x << endl;   // 24
    x /= 4;  cout << x << endl;   // 6
    return 0;
}
```

---

### 1.6 Integer vs. Decimal Arithmetic

This is one of the most common sources of bugs for beginners.

**Rule 1: An operation between two integers always returns an integer.** Any fractional part is **discarded (truncated)**, not rounded.

```cpp
cout << 10 / 3 << endl;   // 3    (not 3.333...)
cout << 7  / 2 << endl;   // 3    (not 3.5)
cout << 1  / 2 << endl;   // 0    (not 0.5)
```

**Rule 2: If either operand is a decimal, the result is a floating-point number.**

```cpp
cout << 10.0 / 3  << endl;   // 3.33333
cout << 10 / 3.0  << endl;   // 3.33333
cout << 10.0 / 3.0 << endl;  // 3.33333
cout << 7 / 2.0   << endl;   // 3.5
```

**Variables behave the same way:**

```cpp
int    a = 10, b = 3;
double c = 10.0;

cout << a / b << endl;   // 3        (int / int)
cout << c / b << endl;   // 3.33333  (double / int)
```

**Watch out: the type of the *result variable* does not fix integer division.**

```cpp
int a = 10, b = 3;
double result = a / b;    // a / b is computed as int first -> 3
cout << result << endl;   // prints 3, NOT 3.33333

double correct = static_cast<double>(a) / b;   // convert first
cout << correct << endl;  // 3.33333
```

> **Also remember:** dividing by zero with integers is undefined behavior (typically a crash). Always check the divisor when it comes from user input.

---

### 1.7 The `<cmath>` Library

C++ ships with many mathematical functions in the `<cmath>` header. Include it at the top of your file:

```cpp
#include <cmath>
```

| Function        | Description                                      | Example                | Result |
|-----------------|--------------------------------------------------|------------------------|--------|
| `pow(base, exp)`| Raises `base` to the power `exp`                 | `pow(2, 3)`            | `8`    |
| `sqrt(num)`     | Square root                                      | `sqrt(25)`             | `5`    |
| `round(num)`    | Rounds to the nearest whole number               | `round(3.6)`           | `4`    |
| `ceil(num)`     | Rounds **up** to the next whole number           | `ceil(3.1)`            | `4`    |
| `floor(num)`    | Rounds **down** to the previous whole number     | `floor(3.9)`           | `3`    |
| `fmax(a, b)`    | Returns the larger of two numbers                | `fmax(4, 9)`           | `9`    |
| `fmin(a, b)`    | Returns the smaller of two numbers               | `fmin(4, 9)`           | `4`    |

**Full example:**

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "pow(2, 3)     = " << pow(2, 3)     << endl;   // 8
    cout << "sqrt(36)      = " << sqrt(36)      << endl;   // 6
    cout << "round(3.5)    = " << round(3.5)    << endl;   // 4
    cout << "round(3.4)    = " << round(3.4)    << endl;   // 3
    cout << "ceil(3.1)     = " << ceil(3.1)     << endl;   // 4
    cout << "floor(3.9)    = " << floor(3.9)    << endl;   // 3
    cout << "fmax(4, 9)    = " << fmax(4, 9)    << endl;   // 9
    cout << "fmin(4, 9)    = " << fmin(4, 9)    << endl;   // 4
    return 0;
}
```

**Details worth knowing**

- These functions return a **floating-point** value (`double`), even when the answer looks like a whole number.
- `round()` uses the standard rule: `.5` and above rounds away from zero (`round(2.5)` is `3`, `round(-2.5)` is `-3`).
- `ceil` and `floor` behave differently for negative numbers: `ceil(-3.1)` is `-3`, while `floor(-3.1)` is `-4`.
- `pow` and `sqrt` are not integer operations. For very large integer powers, floating-point rounding can introduce small errors.

**Combining functions:**

```cpp
double side = 3.0, other = 4.0;
double hypotenuse = sqrt(pow(side, 2) + pow(other, 2));
cout << hypotenuse << endl;   // 5
```

---

## 2. Getting User Input

So far every value has been hard-coded. Real programs need to read data from the user.

### 2.1 Declaring Storage Variables

Before you can read a value, you need somewhere to put it. Declare a variable **without** an initial value:

```cpp
int    age;
double height;
char   grade;
```

These are *uninitialized*: until you assign something, they hold garbage values. Reading from them before assignment is a bug. Here, input from the user will fill them in immediately.

---

### 2.2 Prompting Users

A silent program looks frozen. Always tell the user what to type, using `cout`, **before** reading input:

```cpp
cout << "Enter your age: ";
```

Notice there is no `endl` or `\n`, so the cursor stays on the same line as the prompt.

---

### 2.3 Reading Primitive Data with `cin`

`cin` reads from the keyboard. It is used with the **extraction operator** `>>`, which pulls a value out of the input stream and places it into a variable.

```cpp
cin >> age;
```

**Reading an `int` and a `double`:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int    age;
    double height;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your height in meters: ";
    cin >> height;

    cout << "You are " << age << " years old and "
         << height << " m tall." << endl;
    return 0;
}
```

**Reading a single `char`:**

```cpp
#include <iostream>
using namespace std;

int main() {
    char grade;

    cout << "Enter your grade (A-F): ";
    cin >> grade;

    cout << "Your grade is " << grade << endl;
    return 0;
}
```

`cin >> grade` reads exactly one character. If the user types `ABC`, only `A` is stored; the rest stays in the input buffer.

**Reading several values in one statement:**

```cpp
int a, b;
cin >> a >> b;     // user can type: 5 10   (separated by whitespace)
```

**How `>>` handles whitespace:** the extraction operator skips leading whitespace (spaces, tabs, newlines) and stops reading at the next whitespace. This is exactly why it is a poor choice for sentences, as the next section explains.

---

### 2.4 Reading Full Lines with `getline()`

Suppose you want the user's full name:

```cpp
string name;
cout << "Enter your full name: ";
cin >> name;                       // problem!
cout << "Hello, " << name << endl;
```

Input `Ada Lovelace` produces `Hello, Ada`. The `>>` operator stops at the first space, and `Lovelace` is left in the buffer.

**The fix: `getline(cin, stringVariable)`** reads everything up to the end of the line, spaces included.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Hello, " << fullName << "!" << endl;   // Hello, Ada Lovelace!
    return 0;
}
```

> `getline` requires `#include <string>` and a `string` variable (not `char`).

#### A Classic Pitfall: Mixing `cin >>` and `getline()`

When you press Enter after typing a number, the newline character (`\n`) stays in the input buffer. `cin >>` leaves it there; a following `getline()` then reads that leftover newline and returns an **empty string**.

```cpp
int age;
string name;

cout << "Enter your age: ";
cin >> age;                     // leaves '\n' in the buffer

cout << "Enter your name: ";
getline(cin, name);             // reads the leftover '\n' -> name is ""
```

**Fix:** discard the leftover newline before calling `getline()`.

```cpp
#include <limits>   // for numeric_limits

cin >> age;
cin.ignore(numeric_limits<streamsize>::max(), '\n');   // clear the rest of the line
getline(cin, name);
```

(For quick scripts, `cin.ignore();` removes just one character and is often enough.)

#### Summary: `cin >>` vs. `getline()`

| Feature                       | `cin >> var`                   | `getline(cin, var)`         |
|-------------------------------|--------------------------------|-----------------------------|
| Stops reading at              | Any whitespace                 | End of line (`\n`)          |
| Skips leading whitespace      | Yes                            | No                          |
| Good for                      | Numbers, single words, `char`  | Full sentences, names with spaces |
| Leaves newline in buffer      | Yes                            | No (consumes it)            |

---

## 3. Building a Basic Calculator

Let's combine everything into our first interactive program: a calculator that adds two numbers.

### 3.1 Version 1: Integers

```cpp
#include <iostream>
using namespace std;

int main() {
    int num1, num2;                       // two variables, one line

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Answer: " << num1 + num2 << endl;
    return 0;
}
```

**Sample run:**

```
Enter first number: 12
Enter second number: 30
Answer: 42
```

**What's new here:**

1. **Inline declaration of multiple variables.** `int num1, num2;` declares two variables of the same type on one line.
2. **Sequential input.** The program prompts twice: the first value goes into `num1`, the second into `num2`.
3. **Computing inside the output stream.** `num1 + num2` is evaluated directly within the `cout` statement. No extra variable is required. Because `+` has higher precedence than `<<`, no parentheses are needed for addition, but see the caution below for other operators.

> **Caution:** `<<` has *higher* precedence than comparison operators like `==` and `<`, and than the ternary operator `?:`. If you write something like `cout << a > b;`, you will get unexpected behavior. Wrap such expressions in parentheses: `cout << (a > b);`

---

### 3.2 The Precision Problem

Run Version 1 with decimals:

```
Enter first number: 3.7
Enter second number: 2.5
Answer: 5
```

The answer is wrong. Why? `cin >> num1` reads `3` into an `int` and stops at the `.`; the leftover `.7` then confuses the next extraction. The result is garbage, or, as above, `5`.

---

### 3.3 Version 2: Decimals with `double`

Changing the variable type from `int` to `double` allows the calculator to handle decimal numbers:

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2;                    // only the type changed

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Answer: " << num1 + num2 << endl;
    return 0;
}
```

**Sample run:**

```
Enter first number: 3.7
Enter second number: 2.5
Answer: 6.2
```

A `double` variable can also accept whole numbers (typing `4` stores `4.0`), so this version is strictly more flexible.

---

### 3.4 Syntax Caution: Stream Direction

The most common beginner error in I/O code is mixing up the two stream operators. A helpful memory aid is to **picture the arrows pointing in the direction the data flows:**

| Statement          | Data flows...                    | Meaning               |
|--------------------|----------------------------------|-----------------------|
| `cout << value;`   | from `value` **into** `cout`     | Insertion (output)    |
| `cin >> variable;` | from `cin` **into** `variable`   | Extraction (input)    |

**Common mistakes:**

```cpp
cin  << num1;          // WRONG: compile error (cin is for input)
cout >> "Hello";       // WRONG: compile error (cout is for output)

cout << "Enter: " >> num1;   // WRONG: mixed directions
cin >> "Enter: ";            // WRONG: you can't read into a string literal

cin >> num1 + num2;    // WRONG: you can only read into a variable
cout << "Sum: " << num1 + num2 << endl;   // correct
```

Also watch for these related slips:

- Forgetting the semicolon at the end of a statement.
- Chaining prompts with `cin` (e.g. `cin >> "Enter number" >> num1`). Prompts always go through `cout`.
- Forgetting `using namespace std;` (or writing `std::cout`, `std::cin` throughout).

---

### 3.5 Extension: A Four-Function Calculator

Try extending the program once you're comfortable with the version above:

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    if (op == '+') {
        cout << "Answer: " << num1 + num2 << endl;
    } else if (op == '-') {
        cout << "Answer: " << num1 - num2 << endl;
    } else if (op == '*') {
        cout << "Answer: " << num1 * num2 << endl;
    } else if (op == '/') {
        if (num2 != 0) {
            cout << "Answer: " << num1 / num2 << endl;
        } else {
            cout << "Error: division by zero." << endl;
        }
    } else {
        cout << "Unknown operator." << endl;
    }
    return 0;
}
```

This introduces `if`/`else`, which you'll study in depth next.

---

## 4. Building a Mad Libs Game

### 4.1 Game Mechanics

**Mad Libs** is a word game. One player asks for random words (a color, a plural noun, a celebrity's name, etc.) **without revealing the story**. Those words are then inserted into blanks in a pre-written template, producing a (usually silly) result.

In programming terms:

1. Prompt the user for several words.
2. Store each one in a variable.
3. Print a fixed text template, substituting the stored variables into the blanks.

This is a perfect exercise in storing and outputting strings.

---

### 4.2 Variable Setup

Declare one `string` variable for each custom input:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string color;
    string pluralNoun;
    string celebrity;

    // ...
}
```

Choose descriptive names (`pluralNoun`, not `s2`). When the story grows to 10+ blanks, clear names keep the code manageable.

---

### 4.3 Capturing Story Inputs

Use `getline(cin, variable)` for each prompt. Even if you expect single words today, `getline` will correctly capture something like `Taylor Swift`, a celebrity name with a space, or `light blue`, a two-word color.

```cpp
cout << "Enter a color: ";
getline(cin, color);

cout << "Enter a plural noun: ";
getline(cin, pluralNoun);

cout << "Enter a celebrity: ";
getline(cin, celebrity);
```

> **Why not `cin >>`?** With `cin >> celebrity`, the input `Taylor Swift` would store only `Taylor`, and `Swift` would spill into the next prompt, producing a confusing mess.
>
> Because every input here uses `getline`, you won't encounter the leftover-newline problem from section 2.4. That problem only appears when `cin >>` is mixed in before a `getline`.

---

### 4.4 Template Output

Insert the stored variables into the story by chaining `<<` operators. Each fixed piece of text goes in quotes; each variable goes in *without* quotes.

```cpp
cout << "Roses are " << color << endl;
cout << pluralNoun << " are blue" << endl;
cout << "I love " << celebrity << endl;
```

**Common mistake:** putting the variable name inside the quotes.

```cpp
cout << "Roses are color" << endl;     // prints the literal word "color"
cout << "Roses are " << color << endl; // prints what the user typed
```

---

### 4.5 Complete Program

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Variables for each custom input
    string color;
    string pluralNoun;
    string celebrity;

    // 2. Collect the words
    cout << "Enter a color: ";
    getline(cin, color);

    cout << "Enter a plural noun: ";
    getline(cin, pluralNoun);

    cout << "Enter a celebrity: ";
    getline(cin, celebrity);

    // 3. Print the poem with the user's words inserted
    cout << endl;
    cout << "Roses are " << color << endl;
    cout << pluralNoun << " are blue" << endl;
    cout << "I love " << celebrity << endl;

    return 0;
}
```

**Sample run:**

```
Enter a color: magenta
Enter a plural noun: Toasters
Enter a celebrity: Taylor Swift

Roses are magenta
Toasters are blue
I love Taylor Swift
```

---

### 4.6 Extension Ideas

- Write a longer story with 8-10 blanks (adjectives, verbs, places, numbers).
- Mix input types: read an `int` for a number-of-things blank using `cin >>`, then clear the buffer with `cin.ignore(...)` before your next `getline`.
- Reuse a variable multiple times in the story (e.g. `celebrity` appearing in three places).

---

## 5. Practice Exercises

### Part A: Numbers & Math

1. Predict the output, then verify by running:
   ```cpp
   cout << 8 / 3 << " " << 8 % 3 << " " << 8.0 / 3 << endl;
   cout << 2 + 3 * 4 - 6 / 2 << endl;
   cout << (2 + 3) * (4 - 6) / 2 << endl;
   ```
2. Declare `int x = 5;`. Apply `x += 2; x *= 3; x -= 1; x /= 4;` and predict `x` after each step.
3. Write a program that computes the area of a circle given a radius. (Hint: use `pow` and define `const double PI = 3.14159265358979;`.)
4. Given a price of `19.99`, show it rounded, ceiled, and floored.
5. Explain why `double avg = (3 + 4) / 2;` prints `3` and rewrite it to print `3.5`.

### Part B: User Input

6. Write a program that asks for a user's first name, age, and favorite letter, then prints a sentence using all three.
7. Write a program that reads a full name with `getline` and an age with `cin >>`, **in that order**, and prints both.
8. Now swap the order (age first, then name). Observe what breaks, and fix it using `cin.ignore()`.

### Part C: Calculator

9. Extend the calculator to also print the difference, product, and quotient of the two numbers.
10. Add a modulus operation for integer inputs. What happens if you try `%` on `double` variables?
11. Write a program that reads three numbers and prints their average, using `double`.
12. Read two numbers and print the larger and smaller using `fmax` and `fmin`.

### Part D: Mad Libs

13. Create your own Mad Libs with at least five blanks and a four-line story.
14. Add one numeric blank (e.g., a number between 1 and 100) and include it in the story.

---

## 6. Quick Reference

### Operators

| Operator | Purpose                      |
|----------|------------------------------|
| `+ - * /`| Basic arithmetic             |
| `%`      | Remainder (integers only)    |
| `++ --`  | Increment / decrement by 1   |
| `+= -= *= /=` | Compound assignment     |
| `()`     | Override precedence          |

### `<cmath>` Functions

| Function     | Purpose                    |
|--------------|----------------------------|
| `pow(b, e)`  | `b` raised to the power `e`|
| `sqrt(x)`    | Square root                |
| `round(x)`   | Nearest integer            |
| `ceil(x)`    | Round up                   |
| `floor(x)`   | Round down                 |
| `fmax(a, b)` | Larger value               |
| `fmin(a, b)` | Smaller value              |

### Input / Output

| Task                          | Code                            |
|-------------------------------|---------------------------------|
| Print text                    | `cout << "text";`               |
| Read a number or single word  | `cin >> variable;`              |
| Read a full line              | `getline(cin, stringVariable);` |
| Discard rest of current line  | `cin.ignore(numeric_limits<streamsize>::max(), '\n');` |

### Top Mistakes to Avoid

1. Expecting `10 / 3` to equal `3.33`; it is `3` when both operands are `int`.
2. Using `%` with `double`.
3. Using `cin >>` for text with spaces; use `getline`.
4. Mixing `cin >>` and `getline` without clearing the buffer.
5. Reversing stream operators: `cout <<` outputs, `cin >>` inputs.
6. Putting variable names inside quotation marks.
7. Forgetting `#include <cmath>` or `#include <string>`.
8. Dividing by zero.

---

*Happy coding!*
