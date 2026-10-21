# Chapter 3: Functions in C++

**Course:** Programming Fundamentals using C++ (BHCS01)

A complete, example-driven tutorial on functions in C++: how to define and call them, how arguments are passed, and the C++ features built around functions (default arguments, overloading, inline, recursion, static locals, templates, and command-line arguments).

---

## Table of Contents

1. [Introduction to Functions](#1-introduction-to-functions)
2. [Prototype, Definition and Call](#2-prototype-definition-and-call)
3. [Function Call Flow](#3-function-call-flow)
4. [Call by Value](#4-call-by-value)
5. [Call by Reference](#5-call-by-reference)
6. [Call by Pointer](#6-call-by-pointer)
7. [Value vs Reference vs Pointer](#7-value-vs-reference-vs-pointer)
8. [Default Arguments](#8-default-arguments)
9. [Function Overloading](#9-function-overloading)
10. [Inline Functions](#10-inline-functions)
11. [Recursion](#11-recursion)
12. [Static Local Variables](#12-static-local-variables)
13. [Function Templates](#13-function-templates)
14. [Command-Line Arguments](#14-command-line-arguments)
15. [Choosing the Right Parameter Passing Method](#15-choosing-the-right-parameter-passing-method)
16. [Returning Values: By Value, Reference, Pointer](#16-returning-values-by-value-reference-pointer)
17. [Scope and Lifetime of Variables](#17-scope-and-lifetime-of-variables)
18. [Mini Programs Using Functions](#18-mini-programs-using-functions)
19. [Trace the Output Exercises](#19-trace-the-output-exercises)
20. [Debug the Code Exercises](#20-debug-the-code-exercises)
21. [Practice Programs](#21-practice-programs)
22. [Cheat Sheet](#22-cheat-sheet)
23. [Key Takeaways](#23-key-takeaways)

---

## 1. Introduction to Functions

A **function** is a named block of code that performs one specific task. You write it once and use it as many times as needed.

### Why use functions?

| Benefit | Explanation |
|---------|-------------|
| Modularity | A big program is split into small, manageable pieces |
| Reusability | Write once, call many times |
| Readability | `calculateTotal()` is clearer than 20 lines of arithmetic |
| Easy debugging | A bug is isolated to one function |
| Easy maintenance | Change the logic in one place only |

### Types of functions

| Type | Description | Example |
|------|-------------|---------|
| Library (built-in) | Already provided by C++ | `sqrt()`, `pow()`, `strlen()` |
| User-defined | Written by the programmer | `add()`, `isPrime()` |

### Without functions vs with functions

**Without functions (repeated code):**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3;
    cout << "Sum: " << a + b << endl;

    int c = 10, d = 20;
    cout << "Sum: " << c + d << endl;

    int e = 7, f = 8;
    cout << "Sum: " << e + f << endl;
    return 0;
}
```

**With a function:**

```cpp
#include <iostream>
using namespace std;

int add(int x, int y) {
    return x + y;
}

int main() {
    cout << "Sum: " << add(5, 3) << endl;
    cout << "Sum: " << add(10, 20) << endl;
    cout << "Sum: " << add(7, 8) << endl;
    return 0;
}
```

**Output:**

```
Sum: 8
Sum: 30
Sum: 15
```

`main()` itself is a function. It is the entry point where every C++ program starts executing.

---

## 2. Prototype, Definition and Call

Every function involves three parts.

| Part | Purpose | Example |
|------|---------|---------|
| **Declaration (prototype)** | Tells the compiler the function's name, return type and parameter types | `int add(int, int);` |
| **Definition** | The actual body of the function | `int add(int x, int y) { return x + y; }` |
| **Call** | Uses the function | `add(5, 3);` |

### Syntax

```cpp
return_type function_name(parameter_list) {
    // body
    return value;      // if return_type is not void
}
```

### Example: all three parts together

```cpp
#include <iostream>
using namespace std;

int add(int, int);                 // 1. Prototype (declaration)

int main() {
    int result = add(5, 3);        // 3. Call
    cout << "Result: " << result << endl;
    return 0;
}

int add(int x, int y) {            // 2. Definition
    return x + y;
}
```

**Output:**

```
Result: 8
```

### Why is a prototype needed?

C++ compiles top to bottom. If you call a function **before** the compiler has seen it, you get an error. A prototype introduces the function early; the definition can come later.

```cpp
int main() {
    cout << square(4);     // ERROR: 'square' was not declared in this scope
}
int square(int n) { return n * n; }
```

**Fix:** add `int square(int);` above `main()`, or define `square()` above `main()`.

> Parameter **names** are optional in a prototype: `int add(int, int);` and `int add(int x, int y);` are both valid.

### Parameters vs arguments

| Term | Meaning | Where |
|------|---------|-------|
| **Parameter (formal)** | Variable in the function definition | `int x, int y` in `add(int x, int y)` |
| **Argument (actual)** | Value passed in the call | `5, 3` in `add(5, 3)` |

### Return types

| Return type | Meaning | Example |
|-------------|---------|---------|
| `int`, `float`, `double`, `char`, `bool` | Returns a value of that type | `int add(int, int)` |
| `void` | Returns nothing | `void greet()` |

### Example: void function

```cpp
#include <iostream>
using namespace std;

void printStars(int n) {
    for (int i = 0; i < n; i++)
        cout << "*";
    cout << endl;
}

int main() {
    printStars(5);
    printStars(10);
    return 0;
}
```

**Output:**

```
*****
**********
```

### Example: function returning bool

```cpp
#include <iostream>
using namespace std;

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    cout << isEven(4) << endl;   // 1 (true)
    cout << isEven(7) << endl;   // 0 (false)

    if (isEven(10))
        cout << "10 is even" << endl;
    return 0;
}
```

**Output:**

```
1
0
10 is even
```

### Important rules

- A function can have **only one** `return` executed per call (it ends the function immediately).
- A non-`void` function must return a value on every path.
- A `void` function may use `return;` (without a value) to exit early.
- A function cannot be defined inside another function in C++.
- You can call a function from `main()` or from other functions.

---

## 3. Function Call Flow

When a function is called, control **jumps** to the function, runs it, and then **returns** to the point right after the call.

```cpp
#include <iostream>
using namespace std;

void second() {
    cout << "In second()" << endl;
}

void first() {
    cout << "Start of first()" << endl;
    second();
    cout << "End of first()" << endl;
}

int main() {
    cout << "Start of main()" << endl;
    first();
    cout << "End of main()" << endl;
    return 0;
}
```

**Output:**

```
Start of main()
Start of first()
In second()
End of first()
End of main()
```

### How the call stack works (basics)

| Step | What happens |
|------|--------------|
| 1 | `main()` starts and is placed on the **call stack** |
| 2 | `main()` calls `first()`; `first()` is placed on top of the stack |
| 3 | `first()` calls `second()`; `second()` is placed on top |
| 4 | `second()` finishes and is removed; control returns to `first()` |
| 5 | `first()` finishes and is removed; control returns to `main()` |
| 6 | `main()` finishes; the program ends |

Each call gets its own **stack frame** that holds its parameters and local variables. When the function returns, its frame is destroyed. This is why local variables vanish after a function ends.

### Using a returned value

```cpp
int add(int a, int b) { return a + b; }

int main() {
    int r1 = add(2, 3);                 // store the result
    cout << add(4, 5) << endl;          // use directly in output
    int r2 = add(add(1, 2), add(3, 4)); // nested calls: add(3, 7) = 10
    cout << r1 << " " << r2 << endl;
}
```

**Output:**

```
9
5 10
```

---

## 4. Call by Value

In **call by value**, a **copy** of the argument is given to the function. Changes made to the parameter affect only the copy; the original variable is unchanged.

### Example: the failed swap

```cpp
#include <iostream>
using namespace std;

void swapValues(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside:  a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 10, y = 20;
    swapValues(x, y);
    cout << "Outside: x = " << x << ", y = " << y << endl;
    return 0;
}
```

**Output:**

```
Inside:  a = 20, b = 10
Outside: x = 10, y = 20
```

### Explanation

| Variable | Memory | Value after call |
|----------|--------|------------------|
| `x` (in `main`) | Address A | 10 (unchanged) |
| `y` (in `main`) | Address B | 20 (unchanged) |
| `a` (in `swapValues`) | Address C (copy of `x`) | 20 |
| `b` (in `swapValues`) | Address D (copy of `y`) | 10 |

The swap happened on `a` and `b`, which are separate copies. `x` and `y` were never touched.

### When to use call by value

- The function only needs to **read** the value.
- The data is small (`int`, `char`, `double`, `bool`).
- You want the caller's variable to stay safe from modification.

---

## 5. Call by Reference

A **reference** is an alias (another name) for an existing variable. When a parameter is declared as a reference using `&`, the function works on the **original** variable, not a copy.

### Syntax

```cpp
void func(int &param);     // param is a reference to the caller's variable
```

### Example: working swap

```cpp
#include <iostream>
using namespace std;

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After:  x = " << x << ", y = " << y << endl;
    return 0;
}
```

**Output:**

```
Before: x = 10, y = 20
After:  x = 20, y = 10
```

Here `a` is just another name for `x`, and `b` is another name for `y`. Changing `a` changes `x`.

### Example: returning multiple results

A function can return only one value, but reference parameters let it "return" several.

```cpp
#include <iostream>
using namespace std;

void minMax(int a, int b, int &smaller, int &larger) {
    if (a < b) { smaller = a; larger = b; }
    else       { smaller = b; larger = a; }
}

int main() {
    int s, l;
    minMax(8, 3, s, l);
    cout << "Smaller: " << s << ", Larger: " << l << endl;
    return 0;
}
```

**Output:**

```
Smaller: 3, Larger: 8
```

### Example: const reference (read-only, no copy)

For large objects (like strings) copying is wasteful. A `const` reference avoids the copy **and** prevents modification.

```cpp
#include <iostream>
#include <string>
using namespace std;

void printLength(const string &s) {
    cout << "Length: " << s.length() << endl;
    // s = "new";   // ERROR: s is const
}

int main() {
    string text = "Programming";
    printLength(text);
    return 0;
}
```

**Output:**

```
Length: 11
```

### Rules for references

| Rule | Note |
|------|------|
| Must be initialised when created | `int &r;` is an error |
| Cannot be reseated to another variable | A reference stays bound to its original variable |
| The argument must be a variable (lvalue) | `swapValues(5, 6)` is an error for `int &` parameters |
| No special syntax at the call site | You call `swapValues(x, y)`, not `swapValues(&x, &y)` |

---

## 6. Call by Pointer

Here the function receives the **address** of the variable. Using the `*` (dereference) operator, it reads or modifies the original.

### Syntax

```cpp
void func(int *p);      // p holds an address
func(&x);               // pass the address of x
```

### Example: pointer swap

```cpp
#include <iostream>
using namespace std;

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swapValues(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}
```

**Output:**

```
x = 20, y = 10
```

### Reading the code

| Expression | Meaning |
|------------|---------|
| `&x` | Address of `x` (passed at the call) |
| `int *a` | `a` is a pointer that stores an address |
| `*a` | The value stored at the address `a` holds |

### Example: modify through a pointer

```cpp
#include <iostream>
using namespace std;

void doubleIt(int *p) {
    *p = *p * 2;
}

int main() {
    int n = 7;
    doubleIt(&n);
    cout << n << endl;     // 14
    return 0;
}
```

### Checking for null

A pointer can be `nullptr`. Dereferencing it crashes the program, so check first when null is possible.

```cpp
void safeIncrement(int *p) {
    if (p != nullptr)
        (*p)++;
}
```

Note the brackets in `(*p)++`. Without them, `*p++` increments the **pointer**, not the value.

### The pointer itself is passed by value

```cpp
void f(int *p) {
    *p = 100;        // changes the caller's variable
    p = nullptr;     // changes only the local copy of the pointer
}

int main() {
    int a = 5;
    f(&a);
    cout << a;       // 100
}
```

---

## 7. Value vs Reference vs Pointer

### Comparison table

| Feature | By Value | By Reference | By Pointer |
|---------|----------|--------------|------------|
| Declaration | `void f(int x)` | `void f(int &x)` | `void f(int *x)` |
| Call | `f(a)` | `f(a)` | `f(&a)` |
| What is passed | A copy of the value | An alias of the variable | The address of the variable |
| Can change the original? | No | Yes | Yes (via `*x`) |
| Extra memory for copy | Yes | No | Only the pointer itself |
| Can be null? | n/a | No | Yes |
| Syntax inside function | `x` | `x` | `*x` |
| Can be reassigned to other variable? | n/a | No | Yes (pointer can change) |

### Same task, three ways: increment a number

```cpp
#include <iostream>
using namespace std;

void byValue(int x)      { x++; }
void byReference(int &x) { x++; }
void byPointer(int *x)   { (*x)++; }

int main() {
    int n = 5;

    byValue(n);
    cout << "After byValue:     " << n << endl;

    byReference(n);
    cout << "After byReference: " << n << endl;

    byPointer(&n);
    cout << "After byPointer:   " << n << endl;
    return 0;
}
```

**Output:**

```
After byValue:     5
After byReference: 6
After byPointer:   7
```

---

## 8. Default Arguments

A parameter can be given a **default value**. If the caller omits that argument, the default is used.

### Syntax and example

```cpp
#include <iostream>
using namespace std;

int power(int base, int exp = 2) {     // exp defaults to 2
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

int main() {
    cout << power(5) << endl;       // uses exp = 2  -> 25
    cout << power(2, 5) << endl;    // exp = 5       -> 32
    return 0;
}
```

**Output:**

```
25
32
```

### Example: area of a rectangle (breadth defaults to length, giving a square)

```cpp
#include <iostream>
using namespace std;

double area(double l, double b = 1) {
    return l * b;
}

int main() {
    cout << area(5) << endl;        // 5
    cout << area(5, 4) << endl;     // 20
    return 0;
}
```

**Output:**

```
5
20
```

### Rules

| Rule | Explanation |
|------|-------------|
| Defaults go **right to left** | Once a parameter has a default, all parameters to its right must also have defaults |
| Valid | `void f(int a, int b = 2, int c = 3);` |
| Invalid | `void f(int a = 1, int b);` (error) |
| Specify defaults only once | Put them in the prototype **or** the definition, not both. If a prototype exists, put them there |
| Arguments fill left to right | You cannot skip a middle argument: with `f(a, b=2, c=3)` you cannot pass `a` and `c` while skipping `b` |

### Example with the prototype

```cpp
#include <iostream>
using namespace std;

int calc(int a, int b = 2, int c = 3);      // defaults in the prototype

int main() {
    cout << calc(1) << endl;         // 1*2 + 3 = 5
    cout << calc(1, 4) << endl;      // 1*4 + 3 = 7
    cout << calc(1, 4, 5) << endl;   // 1*4 + 5 = 9
    return 0;
}

int calc(int a, int b, int c) {      // no defaults repeated here
    return a * b + c;
}
```

**Output:**

```
5
7
9
```

### Caution: default arguments and overloading can clash

```cpp
void show(int a);
void show(int a, int b = 0);

show(5);      // ERROR: ambiguous, both functions match
```

---

## 9. Function Overloading

**Function overloading** means having multiple functions with the **same name** but **different parameter lists** in the same scope. The compiler picks the right one at compile time based on the arguments (this is *compile-time polymorphism*).

### What must differ?

| Can differ | Example |
|------------|---------|
| Number of parameters | `add(int, int)` vs `add(int, int, int)` |
| Types of parameters | `add(int, int)` vs `add(double, double)` |
| Order of parameter types | `f(int, double)` vs `f(double, int)` |

**The return type alone is NOT enough** to overload a function.

### Example: area

```cpp
#include <iostream>
#include <cmath>
using namespace std;

double area(double r) {                       // circle
    return 3.14159 * r * r;
}

double area(double l, double b) {             // rectangle
    return l * b;
}

double area(double a, double b, double c) {   // triangle (Heron's formula)
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    cout << "Circle:    " << area(3.0) << endl;
    cout << "Rectangle: " << area(4.0, 5.0) << endl;
    cout << "Triangle:  " << area(6.0, 4.0, 5.0) << endl;
    return 0;
}
```

**Output:**

```
Circle:    28.2743
Rectangle: 20
Triangle:  9.92157
```

### Example: overloading by type

```cpp
#include <iostream>
using namespace std;

void show(int x)    { cout << "int: " << x << endl; }
void show(double x) { cout << "double: " << x << endl; }
void show(char x)   { cout << "char: " << x << endl; }

int main() {
    show(10);
    show(3.14);
    show('A');
    return 0;
}
```

**Output:**

```
int: 10
double: 3.14
char: A
```

### How the compiler chooses (overload resolution)

| Priority | Match type | Example |
|----------|-----------|---------|
| 1 | Exact match | `show(10)` matches `show(int)` |
| 2 | Promotion | `show(5.5f)` (float) promotes to `double`; `char` to `int` |
| 3 | Standard conversion | `double` to `int`, `int` to `double` |
| 4 | Ambiguous: compile error | Two equally good candidates |

### Example of ambiguity

```cpp
void f(int x);
void f(double x);

f(5L);    // long: converts equally well to int or double -> ERROR: ambiguous
```

### Invalid overload (return type only)

```cpp
int    getValue();
double getValue();     // ERROR: cannot overload on return type alone
```

---

## 10. Inline Functions

A normal function call has overhead (jump, stack frame setup, return). For very small functions, an **inline function** asks the compiler to **replace the call with the function body** directly.

### Syntax and example

```cpp
#include <iostream>
using namespace std;

inline int square(int n) {
    return n * n;
}

int main() {
    cout << square(5) << endl;     // may be expanded to: 5 * 5
    cout << square(1 + 2) << endl; // 9
    return 0;
}
```

**Output:**

```
25
9
```

### Pros and cons

| Advantages | Disadvantages |
|------------|---------------|
| No call overhead, which can be faster for tiny functions | Code size grows if used for large functions or called often |
| Type checking is done (unlike macros) | `inline` is only a **request**; the compiler may ignore it |
| Can be debugged and scoped like normal functions | Not suitable for functions with loops, recursion, or large bodies |

### When the compiler may ignore `inline`

- The function contains loops, `switch`, or `goto`
- The function is recursive
- The function contains `static` variables
- The function is very large

### Inline function vs macro

| Feature | Inline function | Macro (`#define`) |
|---------|-----------------|-------------------|
| Processed by | Compiler | Preprocessor (text replacement) |
| Type checking | Yes | No |
| Argument evaluated | Once | Possibly multiple times |
| Debugging | Easier | Harder |

### The classic macro trap

```cpp
#include <iostream>
using namespace std;

#define SQUARE(x) x * x
inline int square(int x) { return x * x; }

int main() {
    cout << SQUARE(1 + 2) << endl;    // expands to 1 + 2 * 1 + 2 = 5  (WRONG)
    cout << square(1 + 2) << endl;    // 3 * 3 = 9                      (correct)
    return 0;
}
```

**Output:**

```
5
9
```

---

## 11. Recursion

A function that **calls itself** is a **recursive function**. Every recursive function needs:

| Part | Purpose |
|------|---------|
| **Base case** | The condition where recursion stops (no further self-call) |
| **Recursive case** | The function calls itself with a **smaller/simpler** problem |

Without a base case, the function calls itself forever until the stack overflows and the program crashes.

### Example 1: factorial

`n! = n × (n-1)!` and `0! = 1`

```cpp
#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1)          // base case
        return 1;
    return n * factorial(n - 1);   // recursive case
}

int main() {
    cout << "5! = " << factorial(5) << endl;
    return 0;
}
```

**Output:**

```
5! = 120
```

**Trace of `factorial(4)`:**

| Call | Returns |
|------|---------|
| `factorial(4)` | `4 * factorial(3)` |
| `factorial(3)` | `3 * factorial(2)` |
| `factorial(2)` | `2 * factorial(1)` |
| `factorial(1)` | `1` (base case) |

Then the results come back up: `factorial(2) = 2 × 1 = 2`, `factorial(3) = 3 × 2 = 6`, `factorial(4) = 4 × 6 = 24`.

### Example 2: Fibonacci

Series: 0, 1, 1, 2, 3, 5, 8, ...

```cpp
#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;          // base case 1
    if (n == 1) return 1;          // base case 2
    return fib(n - 1) + fib(n - 2);
}

int main() {
    for (int i = 0; i < 8; i++)
        cout << fib(i) << " ";
    cout << endl;
    return 0;
}
```

**Output:**

```
0 1 1 2 3 5 8 13 
```

### Example 3: sum of digits

```cpp
#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    cout << sumDigits(1234) << endl;     // 1+2+3+4 = 10
    return 0;
}
```

**Output:**

```
10
```

### Example 4: power (x^n)

```cpp
#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main() {
    cout << power(2, 10) << endl;        // 1024
    return 0;
}
```

### Example 5: GCD (Euclid's algorithm)

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cout << gcd(48, 18) << endl;         // 6
    return 0;
}
```

**Trace of `gcd(48, 18)`:** `gcd(48,18)` → `gcd(18,12)` → `gcd(12,6)` → `gcd(6,0)` → returns `6`.

### Example 6: order of statements matters

Code placed **before** the recursive call runs on the way down; code **after** it runs on the way back up.

```cpp
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) return;
    cout << n << " ";        // before the call: runs going down
    countdown(n - 1);
    cout << n << " ";        // after the call: runs coming back up
}

int main() {
    countdown(3);
    cout << endl;
    return 0;
}
```

**Output:**

```
3 2 1 1 2 3 
```

### Types of recursion

| Type | Description | Example |
|------|-------------|---------|
| Direct | Function calls itself | `factorial()` |
| Indirect | `A()` calls `B()` and `B()` calls `A()` | `isEven()` / `isOdd()` mutual calls |
| Tail | The recursive call is the **last** operation | `gcd()` |
| Non-tail | Work remains after the recursive call | `factorial()` (multiplies after return) |

### Common pitfalls

- Forgetting the base case leads to infinite recursion and stack overflow.
- The recursive call must move **towards** the base case (e.g. `n - 1`, not `n + 1`).
- `fib()` as written recomputes the same values many times, so it becomes very slow for large `n`.

---

## 12. Static Local Variables

A normal local variable is created each time the function is called and destroyed when it ends. A **static local variable** is created **once** and **keeps its value** between calls.

### Example

```cpp
#include <iostream>
using namespace std;

void counter() {
    static int count = 0;    // initialised only once
    int normal = 0;          // re-initialised on every call

    count++;
    normal++;
    cout << "static: " << count << ", normal: " << normal << endl;
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```

**Output:**

```
static: 1, normal: 1
static: 2, normal: 1
static: 3, normal: 1
```

### Comparison

| Property | Normal local | Static local |
|----------|-------------|--------------|
| Scope | Inside the function only | Inside the function only |
| Lifetime | Each call | Entire program run |
| Initialisation | Every call | Only the first time |
| Default value if not initialised | Garbage | `0` |
| Stored in | Stack | Static/data memory |

Scope stays the same (the variable is still invisible outside the function); only the **lifetime** changes.

### Practical use: counting calls

```cpp
int nextId() {
    static int id = 100;
    return ++id;
}
// nextId() -> 101, then 102, then 103 ...
```

---

## 13. Function Templates

Overloading a function for every data type is tedious:

```cpp
int    maxOf(int a, int b)       { return a > b ? a : b; }
double maxOf(double a, double b) { return a > b ? a : b; }
char   maxOf(char a, char b)     { return a > b ? a : b; }
```

A **function template** lets you write the logic **once** for any type. The compiler generates the needed version automatically.

### Syntax

```cpp
template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}
```

`T` is a placeholder for a type. (`class T` and `typename T` mean the same here.)

### Example

```cpp
#include <iostream>
using namespace std;

template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maxOf(3, 7) << endl;           // T = int
    cout << maxOf(2.5, 1.5) << endl;       // T = double
    cout << maxOf('a', 'z') << endl;       // T = char
    return 0;
}
```

**Output:**

```
7
2.5
z
```

### Example: generic swap

```cpp
#include <iostream>
using namespace std;

template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1, b = 2;
    swapValues(a, b);
    cout << a << " " << b << endl;         // 2 1

    double x = 1.5, y = 2.5;
    swapValues(x, y);
    cout << x << " " << y << endl;         // 2.5 1.5
    return 0;
}
```

### Multiple type parameters

```cpp
#include <iostream>
using namespace std;

template <typename T1, typename T2>
void showPair(T1 a, T2 b) {
    cout << a << " and " << b << endl;
}

int main() {
    showPair(10, "apples");
    showPair('A', 3.14);
    return 0;
}
```

**Output:**

```
10 and apples
A and 3.14
```

### Type deduction problem

```cpp
maxOf(5, 3.2);       // ERROR: T cannot be both int and double
```

**Fixes:**

```cpp
maxOf<double>(5, 3.2);          // explicitly choose T = double
maxOf(static_cast<double>(5), 3.2);
```

### Templates vs overloading

| Feature | Overloading | Templates |
|---------|-------------|-----------|
| Code | Separate function per type | One function for all types |
| Logic can differ per type | Yes | No (same logic) |
| Best for | Different behaviour per type | Same behaviour for many types |

A normal (non-template) function is preferred over a template if both match exactly.

---

## 14. Command-Line Arguments

Programs can receive input when they are launched from the terminal. For that, `main()` is written with two parameters:

```cpp
int main(int argc, char *argv[])
```

| Parameter | Meaning |
|-----------|---------|
| `argc` | **Argument count**: number of items typed on the command line (including the program name) |
| `argv` | **Argument vector**: array of C-strings holding each item |
| `argv[0]` | The program name |
| `argv[1] ... argv[argc-1]` | The actual arguments |

### Example: print all arguments

```cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Argument count: " << argc << endl;
    for (int i = 0; i < argc; i++)
        cout << "argv[" << i << "] = " << argv[i] << endl;
    return 0;
}
```

Compile and run:

```
g++ args.cpp -o args
./args hello 42 world
```

**Output:**

```
Argument count: 4
argv[0] = ./args
argv[1] = hello
argv[2] = 42
argv[3] = world
```

### Example: add two numbers from the command line

All arguments arrive as **strings**, so numbers must be converted (`stoi` for int, `stod` for double, or `atoi` from `<cstdlib>`).

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <num1> <num2>" << endl;
        return 1;
    }

    int a = stoi(argv[1]);
    int b = stoi(argv[2]);
    cout << a << " + " << b << " = " << a + b << endl;
    return 0;
}
```

Run:

```
./add 12 30
```

**Output:**

```
12 + 30 = 42
```

### Points to remember

- Arguments are separated by spaces; use quotes for an argument containing spaces: `./args "hello world"`.
- Always check `argc` before accessing `argv[i]`.
- Returning a non-zero value from `main()` conventionally signals an error.

---

## 15. Choosing the Right Parameter Passing Method

| Situation | Best choice | Why |
|-----------|------------|-----|
| Small built-in type, function only reads it | By value | Cheap to copy, safe |
| Function must modify the caller's variable | By reference (`T &`) | Clean syntax, cannot be null |
| Large object (string, vector), read only | `const T &` | No copy, no modification |
| Argument may be "absent" (null allowed) | By pointer | Can pass `nullptr` |
| Working with arrays | By pointer (`int *arr`) | Arrays decay to pointers |
| Need to rebind to different objects inside the function | By pointer | References cannot be reseated |

### Quick decision guide

```
Does the function need to change the original?
 |-- No  --> Is the type small (int, char, double)?
 |             |-- Yes --> pass by value
 |             |-- No  --> pass by const reference
 |-- Yes --> Can the argument be null / optional?
               |-- No  --> pass by reference
               |-- Yes --> pass by pointer
```

---

## 16. Returning Values: By Value, Reference, Pointer

### Return by value (the normal case)

```cpp
int add(int a, int b) { return a + b; }
```

A copy of the result is returned. This is always safe.

### Return by reference

Useful when the function should give back an **existing** variable (for example, to allow assignment to it).

```cpp
#include <iostream>
using namespace std;

int &larger(int &a, int &b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10, y = 20;
    larger(x, y) = 99;           // assigns to y
    cout << x << " " << y << endl;
    return 0;
}
```

**Output:**

```
10 99
```

### Return by pointer

```cpp
int *findFirstNegative(int arr[], int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            return &arr[i];
    return nullptr;              // nothing found
}
```

### The dangling reference/pointer trap

Never return a reference or pointer to a **local variable**. It is destroyed when the function ends.

```cpp
int &bad() {
    int x = 5;
    return x;        // WRONG: x is destroyed, the reference dangles
}

int *alsoBad() {
    int y = 7;
    return &y;       // WRONG: address of a dead variable
}
```

Using these results is **undefined behaviour**.

**Safe to return by reference or pointer:**

- A parameter that was passed by reference or pointer
- A `static` or global variable
- Dynamically allocated memory (`new`), which the caller must later `delete`

### Summary

| Return style | Safe when | Avoid when |
|--------------|-----------|------------|
| By value | Always | Very large objects (copy cost) |
| By reference | Returning a long-lived variable | Returning a local variable |
| By pointer | Result may be "none" (`nullptr`) | Returning the address of a local variable |

---

## 17. Scope and Lifetime of Variables

| Term | Meaning |
|------|---------|
| **Scope** | The region of code where a variable's name is visible |
| **Lifetime** | How long the variable exists in memory |

### Kinds of variables

| Kind | Declared | Scope | Lifetime | Default value |
|------|----------|-------|----------|---------------|
| Local | Inside a function or block | That function or block | While the block runs | Garbage |
| Parameter | In the function header | The function | While the function runs | Passed value |
| Global | Outside all functions | Whole file (after declaration) | Entire program | `0` |
| Static local | Inside a function with `static` | That function | Entire program | `0` |

### Example

```cpp
#include <iostream>
using namespace std;

int g = 100;                 // global

void show() {
    int local = 5;           // local to show()
    cout << "g = " << g << ", local = " << local << endl;
}

int main() {
    show();
    g = g + 1;               // globals can be modified anywhere
    cout << "g = " << g << endl;
    // cout << local;        // ERROR: 'local' is not visible here
    return 0;
}
```

**Output:**

```
g = 100, local = 5
g = 101
```

### Local variable hides a global (the `::` operator)

```cpp
#include <iostream>
using namespace std;

int x = 10;                  // global

int main() {
    int x = 20;              // local x hides global x
    cout << x << endl;       // 20  (local)
    cout << ::x << endl;     // 10  (global, via scope resolution operator)
    return 0;
}
```

**Output:**

```
20
10
```

### Block scope

```cpp
int main() {
    int a = 1;
    {
        int a = 2;           // new variable in the inner block
        cout << a << endl;   // 2
    }
    cout << a << endl;       // 1
}
```

> Avoid heavy use of global variables. Any function can change them, which makes bugs hard to trace. Prefer passing data through parameters.

---

## 18. Mini Programs Using Functions

### 1. Prime number check

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    for (int i = 1; i <= 20; i++)
        if (isPrime(i))
            cout << i << " ";
    cout << endl;
    return 0;
}
```

**Output:**

```
2 3 5 7 11 13 17 19 
```

### 2. Palindrome number

```cpp
#include <iostream>
using namespace std;

int reverseNum(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(int n) {
    return n == reverseNum(n);
}

int main() {
    cout << isPalindrome(121) << endl;    // 1
    cout << isPalindrome(123) << endl;    // 0
    return 0;
}
```

### 3. GCD and LCM

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    cout << "GCD(12, 18) = " << gcd(12, 18) << endl;
    cout << "LCM(12, 18) = " << lcm(12, 18) << endl;
    return 0;
}
```

**Output:**

```
GCD(12, 18) = 6
LCM(12, 18) = 36
```

### 4. Simple calculator using functions

```cpp
#include <iostream>
using namespace std;

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }

int main() {
    double x, y;
    char op;
    cout << "Enter expression (e.g. 8 * 3): ";
    cin >> x >> op >> y;

    switch (op) {
        case '+': cout << add(x, y) << endl; break;
        case '-': cout << sub(x, y) << endl; break;
        case '*': cout << mul(x, y) << endl; break;
        case '/':
            if (y == 0) cout << "Cannot divide by zero" << endl;
            else        cout << divide(x, y) << endl;
            break;
        default: cout << "Invalid operator" << endl;
    }
    return 0;
}
```

**Sample run:**

```
Enter expression (e.g. 8 * 3): 8 * 3
24
```

### 5. Armstrong number check

```cpp
#include <iostream>
using namespace std;

int cube(int n) { return n * n * n; }

bool isArmstrong(int n) {
    int sum = 0, temp = n;
    while (temp > 0) {
        sum += cube(temp % 10);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    cout << isArmstrong(153) << endl;     // 1  (1 + 125 + 27 = 153)
    cout << isArmstrong(154) << endl;     // 0
    return 0;
}
```

### 6. Temperature conversion with overloading and default argument

```cpp
#include <iostream>
using namespace std;

double toFahrenheit(double c) { return c * 9 / 5 + 32; }
double toCelsius(double f)    { return (f - 32) * 5 / 9; }

int main() {
    cout << toFahrenheit(100) << endl;    // 212
    cout << toCelsius(98.6) << endl;      // 37
    return 0;
}
```

---

## 19. Trace the Output Exercises

Work out the output yourself, then check the answers below.

**Q1.**

```cpp
void f(int x) { x = x + 5; cout << x << " "; }
int main() { int a = 10; f(a); cout << a; }
```

**Q2.**

```cpp
void f(int &x) { x += 5; }
int main() { int a = 10; f(a); f(a); cout << a; }
```

**Q3.**

```cpp
void counter() {
    static int c = 0;
    int d = 0;
    c++; d++;
    cout << c << d << " ";
}
int main() { counter(); counter(); counter(); }
```

**Q4.**

```cpp
void show(int x)    { cout << "int "; }
void show(double x) { cout << "double "; }
void show(char x)   { cout << "char "; }
int main() { show(5); show(5.5); show('A'); show(5.5f); }
```

**Q5.**

```cpp
int f(int n) {
    if (n <= 0) return 0;
    return n + f(n - 2);
}
int main() { cout << f(7); }
```

**Q6.**

```cpp
int calc(int a, int b = 2, int c = 3) { return a * b + c; }
int main() { cout << calc(1) << " " << calc(1, 4) << " " << calc(1, 4, 5); }
```

**Q7.**

```cpp
void p(int n) {
    if (n == 0) return;
    cout << n << " ";
    p(n - 1);
    cout << n << " ";
}
int main() { p(3); }
```

**Q8.**

```cpp
void f(int *p) { *p = *p * 2; p = nullptr; }
int main() { int a = 4; f(&a); cout << a; }
```

**Q9.**

```cpp
#define SQ(x) x * x
inline int sq(int x) { return x * x; }
int main() { cout << SQ(2 + 3) << " " << sq(2 + 3); }
```

**Q10.**

```cpp
int x = 5;
void f() { int x = 10; cout << x << " " << ::x << " "; }
int main() { f(); cout << x; }
```

### Answers

| Q | Output | Reason |
|---|--------|--------|
| 1 | `15 10` | Call by value: only the copy changes |
| 2 | `20` | Call by reference: `a` changes twice (10, 15, 20) |
| 3 | `11 21 31 ` | `c` is static and keeps counting; `d` resets to 0 each call |
| 4 | `int double char double ` | `5.5f` is a `float` that is promoted to `double` (better than converting to `int` or `char`) |
| 5 | `16` | 7 + 5 + 3 + 1 + f(-1) where f(-1) = 0 |
| 6 | `5 7 9` | 1×2+3, 1×4+3, 1×4+5 |
| 7 | `3 2 1 1 2 3 ` | First half prints going down, second half prints coming back up |
| 8 | `8` | `*p` doubled the original; `p = nullptr` only changed the local pointer |
| 9 | `11 25` | Macro expands to `2 + 3 * 2 + 3 = 11`; inline function gives `5 * 5 = 25` |
| 10 | `10 5 5` | Local `x` = 10, `::x` = 5, then global `x` = 5 in `main` |

---

## 20. Debug the Code Exercises

Find the error in each program, then check the fixes below.

**D1.**

```cpp
#include <iostream>
using namespace std;
int main() {
    cout << cube(3);
    return 0;
}
int cube(int n) { return n * n * n; }
```

**D2.**

```cpp
void greet(string name = "User", int times) {
    for (int i = 0; i < times; i++)
        cout << "Hello " << name << endl;
}
```

**D3.**

```cpp
int add(int a, int b)    { return a + b; }
double add(int a, int b) { return a + b; }
```

**D4.**

```cpp
int sumTo(int n) {
    return n + sumTo(n - 1);
}
```

**D5.**

```cpp
int &getValue() {
    int x = 50;
    return x;
}
```

**D6.**

```cpp
template <typename T>
T maxOf(T a, T b) { return a > b ? a : b; }

int main() { cout << maxOf(5, 3.2); }
```

**D7.** The programmer wants to swap two numbers, but nothing changes.

```cpp
void swapValues(int a, int b) {
    int t = a; a = b; b = t;
}
int main() {
    int x = 1, y = 2;
    swapValues(x, y);
    cout << x << " " << y;
}
```

**D8.**

```cpp
int main(int argc, char *argv[]) {
    int n = stoi(argv[1]);
    cout << n * 2;
}
```

### Fixes

| Q | Problem | Fix |
|---|---------|-----|
| D1 | `cube` is used before it is declared | Add `int cube(int);` before `main()` or move the definition above `main()` |
| D2 | Default argument is not on the rightmost parameter | Use `void greet(int times, string name = "User")` or give `times` a default as well |
| D3 | Overloading by return type alone is not allowed | Change the parameter lists (e.g. `add(double, double)`) or rename one function |
| D4 | No base case: infinite recursion and stack overflow | Add `if (n == 0) return 0;` at the start |
| D5 | Returns a reference to a local variable that is destroyed | Return by value (`int getValue()`), or make `x` `static` |
| D6 | `T` deduced as both `int` and `double` | Call `maxOf<double>(5, 3.2)` or cast one argument |
| D7 | Call by value swaps copies only | Change the parameters to `int &a, int &b` (or use pointers) |
| D8 | No check on `argc`; crashes if no argument is given | Add `if (argc < 2) { cout << "Usage..."; return 1; }` |

---

## 21. Practice Programs

Write a function-based program for each question.

| # | Problem | Sample output |
|---|---------|---------------|
| 1 | Write `int maxOfThree(int, int, int)` and use it from `main()` | `maxOfThree(4, 9, 6)` gives `9` |
| 2 | Write `bool isPerfect(int n)` (sum of proper divisors equals `n`) and print all perfect numbers up to 1000 | `6 28 496` |
| 3 | Write a function that swaps two numbers using (a) references and (b) pointers | `x=5, y=3` becomes `x=3, y=5` |
| 4 | Write a recursive function to compute the sum of the first `n` natural numbers | `sum(5)` gives `15` |
| 5 | Write a recursive function that prints the binary representation of a decimal number | `13` gives `1101` |
| 6 | Overload `area()` for a circle, rectangle and square and test all three | `area(2)`, `area(3, 4)` give different results |
| 7 | Write a function with a default argument: `double interest(double principal, double rate, int years = 1)` | `interest(1000, 5)` gives `50` |
| 8 | Write a function template `T findMin(T a, T b, T c)` and test it with `int`, `double` and `char` | `findMin(4, 2, 8)` gives `2` |
| 9 | Use a static local variable to write a function that returns how many times it has been called | Calls give `1`, `2`, `3`, ... |
| 10 | Write a program that takes two numbers and an operator (`+`, `-`, `x`, `/`) as command-line arguments and prints the result | `./calc 8 + 5` gives `13` |
| 11 | Write a recursive function that reverses a number's digits | `reverse(1234)` gives `4321` |
| 12 | Write `void minMax(int arr[], int n, int &mn, int &mx)` that finds both smallest and largest elements using reference parameters | Array `{4, 9, 1, 7}` gives `min=1, max=9` |
| 13 | Write a recursive function to compute `x^n` and compare it with `pow()` | `power(3, 4)` gives `81` |
| 14 | Write functions `isEven()` and `isOdd()` that call each other (indirect recursion) | `isEven(10)` gives `1` |

---

## 22. Cheat Sheet

### Function basics

| Item | Syntax |
|------|--------|
| Prototype | `int add(int, int);` |
| Definition | `int add(int a, int b) { return a + b; }` |
| Call | `add(2, 3);` |
| No return value | `void show() { ... }` |

### Parameter passing

| Method | Declare | Call | Modifies original? |
|--------|---------|------|--------------------|
| By value | `void f(int x)` | `f(a)` | No |
| By reference | `void f(int &x)` | `f(a)` | Yes |
| By const reference | `void f(const int &x)` | `f(a)` | No (no copy) |
| By pointer | `void f(int *x)` | `f(&a)` | Yes (`*x`) |

### Function features

| Feature | Syntax | Key rule |
|---------|--------|----------|
| Default argument | `void f(int a, int b = 5)` | Defaults go right to left |
| Overloading | Same name, different parameters | Return type alone is not enough |
| Inline | `inline int sq(int x) { return x*x; }` | A request only; avoid for large or recursive functions |
| Recursion | Function calls itself | Needs a base case |
| Static local | `static int c = 0;` | Initialised once; keeps its value |
| Template | `template <typename T> T f(T a, T b)` | One logic for many types |
| Command line | `int main(int argc, char *argv[])` | `argv[0]` is the program name; arguments are strings |

### Scope and lifetime

| Kind | Scope | Lifetime |
|------|-------|----------|
| Local | Block or function | While the block runs |
| Global | Whole file | Whole program |
| Static local | Function | Whole program |

### Common return rules

| Return | Safe? |
|--------|-------|
| By value | Always |
| Reference or pointer to a parameter, static or global variable | Yes |
| Reference or pointer to a local variable | No (dangling) |

---

## 23. Key Takeaways

- A function is a named, reusable block of code. It has a **prototype**, a **definition**, and **calls**.
- **Parameters** are in the definition; **arguments** are in the call.
- A prototype lets you call a function before its definition appears.
- **Call by value** copies the argument, so the original is safe.
- **Call by reference** (`&`) and **call by pointer** (`*`) let the function change the original.
- Use `const &` for large read-only objects to avoid copying.
- **Default arguments** must be on the rightmost parameters, and defaults go in the prototype.
- **Overloading** needs a different number or type of parameters; the return type alone does not count.
- **Inline** is only a request to the compiler and suits tiny functions.
- **Recursion** needs a base case and a call that moves towards it.
- **Static local variables** keep their value between calls and are initialised only once.
- **Templates** let one function work for many types; mixed argument types cause a deduction error unless you specify `<type>`.
- **Command-line arguments** arrive through `argc` and `argv` as strings; always check `argc` first.
- Never return a reference or pointer to a local variable.
- A local variable hides a global of the same name; use `::` to reach the global.

---

*End of Chapter 3.*
