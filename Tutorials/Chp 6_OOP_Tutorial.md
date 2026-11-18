# Chapter 6: Object-Oriented Programming in C++

> Maps to **Syllabus Unit 3** (DU B.Sc. CS — Programming Using C++)

[Link to PPT](https://docs.google.com/presentation/d/11qj6-42zHKsO05PiHpZFmed1bpKnp4Y_C_JbkgFfRto/present)
---

## Table of Contents

1. [OOP Concepts](#1-oop-concepts)
2. [Classes & Objects](#2-classes--objects)
3. [Access Specifiers](#3-access-specifiers)
4. [Constructors & Destructors](#4-constructors--destructors)
5. [Copy Constructor vs. Assignment Operator](#5-copy-constructor-vs-assignment-operator)
6. [Static Members & Friend Functions](#6-static-members--friend-functions)
7. [Inline Functions](#7-inline-functions)
8. [Operator & Function Overloading](#8-operator--function-overloading)
9. [Inheritance](#9-inheritance)
10. [Polymorphism](#10-polymorphism)
11. [Templates](#11-templates)
12. [Practical Programs](#12-practical-programs)
13. [Trace the Output](#13-trace-the-output)
14. [Debug the Code](#14-debug-the-code)
15. [True / False](#15-true--false)
16. [Differentiate Between](#16-differentiate-between)
17. [Write a Program — Exam Style](#17-write-a-program--exam-style)
18. [Common Mistakes](#18-common-mistakes)

---

## 1. OOP Concepts

**Procedural vs. Object-Oriented Programming**

| Procedural | Object-Oriented |
|---|---|
| Program divided into functions | Program divided into objects/classes |
| Data and functions are separate | Data and functions bundled together |
| Data can be accessed freely by functions | Data access controlled (encapsulation) |
| Harder to reuse/extend | Easier to reuse via inheritance |
| Example: C | Example: C++, Java |

**Abstraction** — showing only essential features and hiding implementation details. Example: a `Car` class exposes `start()` and `stop()`, hiding engine internals.

**Encapsulation** — bundling data and the functions that operate on it into a single unit (a class), and restricting direct access to the data using access specifiers.

```cpp
class BankAccount {
private:
    double balance;   // data hidden
public:
    void deposit(double amt) { balance += amt; }   // controlled access
    double getBalance() { return balance; }
};
```

### Key Points
- OOP models real-world entities as objects.
- Four pillars: Encapsulation, Abstraction, Inheritance, Polymorphism.
- Abstraction = *what* is shown; Encapsulation = *how* it is protected.

---

## 2. Classes & Objects

A **class** is a user-defined blueprint; an **object** is an instance of that class.

```cpp
class Student {
    int roll;          // data member
    string name;
public:
    void setData(int r, string n) { roll = r; name = n; }   // member function
    void display() { cout << roll << " " << name; }
};

int main() {
    Student s1;          // object
    s1.setData(1, "Ankith");
    s1.display();
}
```

Scope resolution operator `::` is used to define a member function outside the class:

```cpp
class Box {
public:
    int volume();
};
int Box::volume() { return 10; }   // defined outside using ::
```

### Key Points
- Class = template; Object = variable of that class type.
- Member functions can be defined inside (implicitly inline) or outside (using `::`) the class.
- Multiple objects of a class each get their own copy of data members, but share member functions.

---

## 3. Access Specifiers

| Specifier | Accessible from... |
|---|---|
| `private` | Only within the same class (default for `class`) |
| `protected` | Same class + derived classes |
| `public` | Anywhere the object is visible |

Access specifiers are the primary **tool of encapsulation** — they let a class hide its internal data (`private`) while exposing a controlled public interface.

```cpp
class Account {
private:
    double balance;        // hidden
public:
    void setBalance(double b) { balance = b; }   // controlled entry point
};
```

> **Note:** `struct` members are `public` by default; `class` members are `private` by default — this is the only structural difference between the two in C++.

---

## 4. Constructors & Destructors

A **constructor** is a special member function, same name as the class, no return type, called automatically on object creation.

| Type | Description |
|---|---|
| Default constructor | No parameters; sets default values |
| Parameterized constructor | Takes arguments to initialize members |
| Copy constructor | Initializes an object using another object of the same class |

```cpp
class Point {
    int x, y;
public:
    Point() { x = 0; y = 0; }                         // default
    Point(int a, int b) { x = a; y = b; }             // parameterized
    Point(const Point &p) { x = p.x; y = p.y; }       // copy constructor
    void show() { cout << x << "," << y; }
};
int main() {
    Point p1;            // default
    Point p2(3, 4);       // parameterized
    Point p3(p2);         // copy constructor
    Point p4 = p2;        // also invokes copy constructor
}
```

A **destructor** (`~ClassName()`) is called automatically when an object goes out of scope or is deleted. It takes no arguments, cannot be overloaded, and is used for cleanup (e.g., releasing dynamically allocated memory).

**Order of construction/destruction:**
- Objects are constructed in the order they are declared.
- Objects are destructed in the **reverse** order of construction.
- In inheritance, base class constructor runs **before** derived class constructor; destructors run in the opposite order (derived first, then base).

```cpp
class Base {
public:
    Base() { cout << "Base ctor\n"; }
    ~Base() { cout << "Base dtor\n"; }
};
class Derived : public Base {
public:
    Derived() { cout << "Derived ctor\n"; }
    ~Derived() { cout << "Derived dtor\n"; }
};
int main() {
    Derived d;
}
// Output: Base ctor -> Derived ctor -> Derived dtor -> Base dtor
```

### Key Points
- Constructors can be overloaded; destructors cannot.
- A constructor can be `private` (used in Singleton pattern).
- If no constructor is defined, the compiler supplies a default one.

---

## 5. Copy Constructor vs. Assignment Operator

| Copy Constructor | Assignment Operator |
|---|---|
| Called when a **new** object is created from an existing one | Called when an **already-existing** object is assigned another object's values |
| `Point p2(p1);` or `Point p2 = p1;` (at declaration) | `p2 = p1;` (after both are already declared) |
| Signature: `ClassName(const ClassName &obj)` | Signature: `ClassName& operator=(const ClassName &obj)` |

**Shallow copy** (default compiler-generated behaviour) copies member values directly — if the class holds a raw pointer, both objects point to the *same* memory, causing double-free bugs. **Deep copy** allocates separate memory and copies the actual data, which must be written manually when a class manages dynamic memory.

```cpp
class Arr {
    int *data;
public:
    Arr(int val) { data = new int(val); }
    Arr(const Arr &a) { data = new int(*a.data); }   // deep copy
    ~Arr() { delete data; }
};
```

---

## 6. Static Members & Friend Functions

**Static data member** — shared by all objects of a class; exists independent of any object; must be defined outside the class.

```cpp
class Counter {
    static int count;
public:
    Counter() { count++; }
    static int getCount() { return count; }   // static member function
};
int Counter::count = 0;   // definition outside class

int main() {
    Counter c1, c2, c3;
    cout << Counter::getCount();   // 3
}
```

**Friend function** — a non-member function granted access to a class's private/protected members by declaring it `friend` inside the class.

```cpp
class Box {
    int width;
public:
    Box(int w) : width(w) {}
    friend void printWidth(Box b);   // friend declaration
};
void printWidth(Box b) { cout << b.width; }   // can access private member
```

**`this` pointer** — an implicit pointer available inside every non-static member function, pointing to the object on which the function was called. Used to resolve naming conflicts and to return the current object (e.g., `return *this;` for method chaining).

### Key Points
- Static functions can only access static data members directly.
- Friend functions break encapsulation slightly but are useful for operator overloading.
- `this` is not available in static member functions (no object context).

---

## 7. Inline Functions

Member functions **defined inside the class body** are implicitly `inline`. A function declared outside with the `inline` keyword is also a request (not a guarantee) to the compiler to substitute the function call with the function body, avoiding call overhead for small, frequently used functions.

```cpp
class Small {
public:
    int square(int x) { return x * x; }   // implicitly inline
};
inline int cube(int x) { return x * x * x; }   // explicitly inline
```

The compiler may **ignore** `inline` for functions that:
- contain loops, recursion, or switch/large bodies
- are virtual
- have their address taken
- are too large/complex to expand usefully

---

## 8. Operator & Function Overloading

**Operator overloading** lets built-in operators work with user-defined types.

```cpp
class Complex {
    float re, im;
public:
    Complex(float r = 0, float i = 0) : re(r), im(i) {}
    Complex operator+(const Complex &c) {
        return Complex(re + c.re, im + c.im);
    }
    void show() { cout << re << " + " << im << "i"; }
};
int main() {
    Complex c1(2, 3), c2(1, 4);
    Complex c3 = c1 + c2;   // calls operator+
    c3.show();              // 3 + 7i
}
```

**Function overloading** (overloaded member functions) — same function name, different parameter list (number/type), resolved at **compile time**.

```cpp
class Shape {
public:
    double area(double r) { return 3.14159 * r * r; }          // circle
    double area(double l, double b) { return l * b; }          // rectangle
};
```

> Overloading **cannot** be done on return type alone — the parameter list must differ.

---

## 9. Inheritance

Inheritance lets a class (derived) acquire properties of another class (base), enabling code reuse.

| Type | Description |
|---|---|
| Single | One base, one derived |
| Multilevel | A → B → C (chain) |
| Multiple | One derived class, two or more base classes |
| Hierarchical | One base, multiple derived classes |

**Inheritance access specifiers** control how base class members are inherited:

| Base member | `public` inheritance | `protected` inheritance | `private` inheritance |
|---|---|---|---|
| `public` | becomes `public` | becomes `protected` | becomes `private` |
| `protected` | stays `protected` | stays `protected` | becomes `private` |
| `private` | not accessible | not accessible | not accessible |

```cpp
class Animal {
public:
    void eat() { cout << "Eating\n"; }
};
class Dog : public Animal {
public:
    void bark() { cout << "Barking\n"; }
};
int main() {
    Dog d;
    d.eat();   // inherited
    d.bark();
}
```

**Multiple inheritance & ambiguity:** if two base classes have a member with the same name, the derived class must use `::` to disambiguate, or the base classes must share a common ancestor using `virtual` inheritance to avoid duplicate copies (the "diamond problem").

```cpp
class A { public: void show() { cout << "A"; } };
class B { public: void show() { cout << "B"; } };
class C : public A, public B {
public:
    void show() { A::show(); B::show(); }   // disambiguation
};
```

```cpp
// Diamond problem fix with virtual base class
class Base { public: int x; };
class B1 : virtual public Base {};
class B2 : virtual public Base {};
class Derived : public B1, public B2 {};   // only one copy of Base::x
```

---

## 10. Polymorphism

**Polymorphism** = "many forms" — the same function behaving differently depending on context.

| Compile-time (Early binding) | Run-time (Late binding) |
|---|---|
| Resolved at compile time | Resolved at run time |
| Function overloading, operator overloading | Virtual functions |
| Faster | Slightly slower (vtable lookup) |

**Virtual functions** enable run-time polymorphism — a base class pointer/reference can call the derived class's overridden version.

```cpp
class Shape {
public:
    virtual double area() { return 0; }    // virtual function
};
class Circle : public Shape {
    double r;
public:
    Circle(double rad) : r(rad) {}
    double area() override { return 3.14159 * r * r; }
};
int main() {
    Shape *s = new Circle(5);
    cout << s->area();   // calls Circle::area() — run-time polymorphism
    delete s;
}
```

**Pure virtual function & abstract class:**

```cpp
class Shape {
public:
    virtual double area() = 0;   // pure virtual -> makes Shape abstract
};
// Shape obj; // ERROR: cannot instantiate an abstract class
class Rectangle : public Shape {
    double l, b;
public:
    Rectangle(double l_, double b_) : l(l_), b(b_) {}
    double area() override { return l * b; }
};
```

**`final` keyword** — prevents further overriding of a virtual function or further inheritance of a class.

```cpp
class Base {
public:
    virtual void show() final { cout << "Base"; }   // cannot be overridden
};
class Sealed final { /* ... */ };   // cannot be inherited from
```

### Key Points
- Without `virtual`, the compiler uses the pointer's **static type** (early binding) — the base class version is called regardless of the actual object type.
- A class with at least one pure virtual function is abstract and cannot be instantiated.
- `override` keyword (optional but recommended) catches signature mismatches at compile time.

---

## 11. Templates

**Function template** — one function definition that works with multiple data types.

```cpp
template <class T>
T maxVal(T a, T b) {
    return (a > b) ? a : b;
}
int main() {
    cout << maxVal(3, 7);       // T = int
    cout << maxVal(3.5, 2.1);   // T = double
}
```

**Class template** — a class that operates on a generic type, specified when the object is created.

```cpp
template <class T>
class TwoDim {
protected:
    T x, y;
public:
    TwoDim() : x(0), y(0) {}                 // default constructor
    TwoDim(T a, T b) : x(a), y(b) {}         // parameterized constructor
    void print() { cout << x << ", " << y << endl; }
};

template <class T>
class ThreeDim : public TwoDim<T> {
    T z;
public:
    ThreeDim() : TwoDim<T>(), z(0) {}
    ThreeDim(T a, T b, T c) : TwoDim<T>(a, b), z(c) {}
    void print() { TwoDim<T>::print(); cout << "z = " << z << endl; }
};

int main() {
    TwoDim<int> p1(2, 3);
    ThreeDim<int> p2(1, 2, 3);
    TwoDim<int> *ptr = &p2;
    // demonstrating runtime polymorphism requires print() to be virtual
}
```

> To show true **run-time polymorphism** with `TwoDim`/`ThreeDim`, `print()` must be declared `virtual` in the base template class, and called through a base class pointer/reference.

---

## 12. Practical Programs

### (a) Triangle class with overloaded area functions

```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
public:
    // Overload 1: base & height
    double area(double base, double height) {
        return 0.5 * base * height;
    }
    // Overload 2: three sides (Heron's formula)
    double area(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    Triangle t;
    cout << "Area (base,height): " << t.area(5.0, 4.0) << endl;
    cout << "Area (3 sides): " << t.area(3.0, 4.0, 5.0) << endl;
    return 0;
}
```

### (b) Person / Student / Employee hierarchy

```cpp
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual void display() { cout << "Name: " << name << endl; }
};

class Student : public Person {
    int roll;
public:
    Student(string n, int r) : Person(n), roll(r) {}
    void display() override {
        Person::display();
        cout << "Roll: " << roll << endl;
    }
};

class Employee : public Person {
    double salary;
public:
    Employee(string n, double s) : Person(n), salary(s) {}
    void display() override {
        Person::display();
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person *p1 = new Student("Riya", 23);
    Person *p2 = new Employee("Aman", 55000);
    p1->display();
    p2->display();
    delete p1; delete p2;
    return 0;
}
```

### (c) Matrix class (operator overloading)

```cpp
#include <iostream>
using namespace std;
const int N = 2;

class Matrix {
    int m[N][N];
public:
    Matrix() { for (int i=0;i<N;i++) for (int j=0;j<N;j++) m[i][j]=0; }
    void input() { for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> m[i][j]; }
    Matrix operator+(const Matrix &b) {
        Matrix r;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                r.m[i][j] = m[i][j] + b.m[i][j];
        return r;
    }
    void display() {
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) cout << m[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    Matrix a, b;
    a.input(); b.input();
    Matrix c = a + b;
    c.display();
    return 0;
}
```

---

## 13. Trace the Output

**Q1.**
```cpp
class Test {
    int x;
public:
    Test(int v) { x = v; cout << "Ctor " << x << endl; }
    ~Test() { cout << "Dtor " << x << endl; }
};
int main() {
    Test t1(1);
    {
        Test t2(2);
    }
    Test t3(3);
}
```
**Output:**
```
Ctor 1
Ctor 2
Dtor 2
Ctor 3
Dtor 3
Dtor 1
```
*Explanation:* `t2` is destroyed when the inner block ends (before `t3` is even created). `t1` and `t3` are destroyed in reverse order of construction at the end of `main()`.

**Q2.**
```cpp
class A {
public:
    A() { cout << "A"; }
};
class B : public A {
public:
    B() { cout << "B"; }
};
int main() { B obj; }
```
**Output:** `AB` — base constructor always runs before derived constructor.

**Q3.**
```cpp
class Base {
public:
    void show() { cout << "Base show\n"; }
};
class Derived : public Base {
public:
    void show() { cout << "Derived show\n"; }
};
int main() {
    Base *b;
    Derived d;
    b = &d;
    b->show();
}
```
**Output:** `Base show` — `show()` is **not virtual**, so the call is resolved using the pointer's static type (`Base*`), i.e. early binding.

---

## 14. Debug the Code

**Q1.**
```cpp
class Account {
private:
    double balance;
public:
    void setBalance(double b) { balance = b; }
};
int main() {
    Account obj;
    obj.balance = 1000.0;   // ERROR
}
```
**Error:** `balance` is `private`; it cannot be accessed directly from `main()`.
**Fix:** `obj.setBalance(1000.0);`

**Q2.**
```cpp
class Employee {
    int id;
    string name;
public:
    setId(int i) { id = i; }   // ERROR: missing return type
    void setName(string n) { name = n; }
};
```
**Error:** `setId` has no return type specified (pre-C++ allowed implicit `int`, modern C++ does not).
**Fix:** `void setId(int i) { id = i; }`

**Q3.**
```cpp
int *ptr;
*ptr = 10;          // ERROR: dereferencing uninitialized pointer
cout << *ptr;
delete ptr;
```
**Error:** `ptr` is declared but never allocated memory (`new`) or assigned a valid address — dereferencing it is undefined behaviour.
**Fix:** `int *ptr = new int; *ptr = 10;`

**Q4.**
```cpp
class Test {
public:
    ~Test(int x) { }   // ERROR: destructor cannot take parameters
};
```
**Error:** Destructors never take arguments and cannot be overloaded.
**Fix:** `~Test() { }`

---

## 15. True / False

1. A constructor can be overloaded. — **True**
2. A destructor can be overloaded. — **False** (only one destructor per class, no parameters)
3. `private` members of a base class are inherited but not accessible in the derived class. — **True**
4. Multiple inheritance can cause ambiguity if two base classes share a member name. — **True**
5. A class with a pure virtual function can be instantiated. — **False** (it is abstract)
6. Static data members are shared across all objects of a class. — **True**
7. The `this` pointer is available inside static member functions. — **False**
8. Operator overloading can change the number of operands an operator takes. — **False**
9. A `friend` function is a member of the class that declares it. — **False** (it is non-member but has access)
10. Virtual functions enable run-time polymorphism. — **True**

---

## 16. Differentiate Between

**Constructor vs. Destructor**

| Constructor | Destructor |
|---|---|
| Called when object is created | Called when object is destroyed |
| Can be overloaded | Cannot be overloaded |
| Can take arguments | Never takes arguments |
| Name: `ClassName()` | Name: `~ClassName()` |

**Early Binding vs. Late Binding**

| Early (Static) Binding | Late (Dynamic) Binding |
|---|---|
| Resolved at compile time | Resolved at run time |
| Faster execution | Slight overhead (vtable) |
| Used in overloading, non-virtual calls | Used with virtual functions |

**Inheritance vs. Polymorphism**

| Inheritance | Polymorphism |
|---|---|
| Mechanism for reusing/extending a class | Mechanism for one interface, many implementations |
| Establishes an "is-a" relationship | Allows the same call to behave differently |
| Example: `Dog : public Animal` | Example: `shape->area()` behaving differently for `Circle`/`Rectangle` |

**Data Abstraction vs. Data Encapsulation**

| Abstraction | Encapsulation |
|---|---|
| Hiding implementation complexity, showing only essential features | Bundling data + methods, restricting direct access |
| Achieved via abstract classes / interfaces | Achieved via access specifiers |
| Focuses on *design* ("what") | Focuses on *implementation* ("how") |

**Operator Overloading vs. Function Overloading**

| Operator Overloading | Function Overloading |
|---|---|
| Redefines behaviour of an existing operator (`+`, `==`, etc.) for a class | Same function name, different parameter lists |
| Syntax: `ReturnType operator@(params)` | Syntax: normal function declarations with varying signatures |

**Copy Constructor vs. Assignment Operator** *(see also Section 5)*

| Copy Constructor | Assignment Operator |
|---|---|
| Used during object initialization | Used after both objects already exist |
| `ClassName obj2 = obj1;` or `ClassName obj2(obj1);` | `obj2 = obj1;` |

---

## 17. Write a Program — Exam Style

**Q1.** Create a class `Box` with a static data member `count`. Display the number of objects created and destroyed.

```cpp
#include <iostream>
using namespace std;
class Box {
    static int count;
public:
    Box() { count++; cout << "Object created. Count = " << count << endl; }
    ~Box() { cout << "Object destroyed. Count = " << count << endl; count--; }
};
int Box::count = 0;
int main() {
    Box b1;
    { Box b2; }
    return 0;
}
```

**Q2.** Write a program to define an abstract class `Polygon` with a pure virtual `area()` function, and derive a `Rectangle` class from it.

```cpp
#include <iostream>
using namespace std;
class Polygon {
protected:
    double area_;
public:
    virtual double area() = 0;
};
class Rectangle : public Polygon {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override { return length * width; }
};
int main() {
    Polygon *p = new Rectangle(5, 3);
    cout << "Area: " << p->area();
    delete p;
    return 0;
}
```

**Q3.** Write a function template `minimum(T arr[], int size)` to find the minimum element for `int`, `char`, and `float` arrays.

```cpp
#include <iostream>
using namespace std;
template <class T>
T minimum(T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}
int main() {
    int a[] = {5, 2, 8, 1};
    float f[] = {3.3, 1.1, 2.2};
    cout << minimum(a, 4) << endl;
    cout << minimum(f, 3) << endl;
    return 0;
}
```

**Q4.** Create a template class `TwoDim` with default & parameterized constructors and a `print()` function; derive `ThreeDim` from it and demonstrate run-time polymorphism.

```cpp
#include <iostream>
using namespace std;
template <class T>
class TwoDim {
protected:
    T x, y;
public:
    TwoDim() : x(0), y(0) {}
    TwoDim(T a, T b) : x(a), y(b) {}
    virtual void print() { cout << "(" << x << ", " << y << ")" << endl; }
};
template <class T>
class ThreeDim : public TwoDim<T> {
    T z;
public:
    ThreeDim() : TwoDim<T>(), z(0) {}
    ThreeDim(T a, T b, T c) : TwoDim<T>(a, b), z(c) {}
    void print() override {
        cout << "(" << this->x << ", " << this->y << ", " << z << ")" << endl;
    }
};
int main() {
    TwoDim<int> *p1 = new TwoDim<int>(1, 2);
    TwoDim<int> *p2 = new ThreeDim<int>(1, 2, 3);
    p1->print();   // (1, 2)
    p2->print();   // (1, 2, 3) -- run-time polymorphism via virtual print()
    delete p1; delete p2;
    return 0;
}
```

---

## 18. Common Mistakes

- Forgetting that `private` members of a class cannot be accessed directly by objects in `main()` — always go through public member functions.
- Trying to overload a destructor, or giving it parameters — destructors never take arguments.
- Omitting `virtual` on a base class function and then expecting run-time polymorphism through a base pointer — without `virtual`, the call is resolved using the static (pointer) type, not the actual object type.
- Using the default (shallow) copy constructor/assignment for a class that holds raw pointers — leads to double-free or dangling pointer bugs; write a deep-copy version instead.
- Instantiating an abstract class directly (a class with any pure virtual function) — this is a compile-time error.
- Forgetting `T::` or `this->` when accessing base class template members inside a derived template class — a common compiler error with class templates.
- Confusing overloading (compile-time, same scope, different signatures) with overriding (run-time, base/derived, same signature, requires `virtual`).
- Defining a static data member inside the class without a separate definition outside it (`int ClassName::member = 0;`) — causes a linker error.
