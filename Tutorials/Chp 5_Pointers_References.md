# Chapter 5: Pointers & References

## 1. Pointer Basics

A pointer is a variable that stores the **address** of another variable.

```cpp
int x = 10;
int *p = &x;   // p stores address of x
cout << p;     // prints address
cout << *p;    // dereference: prints value at that address -> 10
```

- `&` — address-of operator (gives address of a variable)
- `*` — two meanings depending on context:
  - In declaration: `int *p;` declares p as a pointer to int
  - In expression: `*p` dereferences p (accesses the value it points to)

Every pointer has a **type** — `int*`, `float*`, `char*`, etc. The type tells the compiler how many bytes to read/write and how to interpret pointer arithmetic.

A pointer that doesn't point anywhere valid should be initialized to `nullptr`:

```cpp
int *p = nullptr;   // safe: no address, not garbage
```

---

## 2. Declaration Validity & Dereference Tracing

Common declaration forms:

```cpp
int *p;        // pointer to int
int *p, q;     // p is pointer to int, q is a plain int (common trap)
int *p, *q;    // both p and q are pointers
const int *p;  // pointer to constant int (value can't change via p)
int * const p; // constant pointer (p itself can't be reassigned)
```

**Dereference tracing example:**

```cpp
int a = 5, b = 10;
int *p = &a;
int *q = &b;

*p = *p + *q;   // a = a + b -> a = 15
p = q;          // p now points to b (not a copy of value, the address)
*p = 20;        // b = 20
cout << a << " " << b;   // 15 20
```

Tip for tracing: always ask two questions at each line — *what does the pointer point to?* and *what value is at that address?*

---

## 3. Pointer Arithmetic

Pointer arithmetic is scaled by the size of the pointed-to type, not raw bytes.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;        // p points to arr[0]

cout << *p;           // 10
cout << *(p + 1);     // 20  (p+1 moves by sizeof(int), not 1 byte)
p++;                  // now points to arr[1]
cout << *p;           // 20
p += 2;               // now points to arr[3]
cout << *p;           // 40
```

- `p + 1` → address = `p + 1 * sizeof(*p)`
- Subtracting two pointers of the same array gives the number of elements between them, not bytes.

```cpp
int *start = &arr[0], *end = &arr[4];
cout << (end - start);   // 4 (number of elements apart)
```

Pointer arithmetic is only well-defined within (or one-past-the-end of) the same array.

---

## 4. Pointers & Arrays

An array name decays to a pointer to its first element in most expressions.

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;            // same as &arr[0]

for (int i = 0; i < 5; i++)
    cout << *(p + i) << " ";   // same as arr[i]
```

Key differences between an array name and a pointer:

| Array name | Pointer |
|---|---|
| Not reassignable (`arr = p;` is illegal) | Reassignable |
| `sizeof(arr)` gives total array size | `sizeof(p)` gives pointer size (e.g. 8 bytes) |
| Address is fixed at compile time | Can point to different addresses at runtime |

Passing arrays to functions always passes a pointer (decays), which is why array size must be passed separately:

```cpp
void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
}
```

---

## 5. Generic Pointers (`void*`)

A `void*` can hold the address of any data type but **cannot be dereferenced directly** — it has no type information to know how many bytes to read.

```cpp
int x = 10;
void *vp = &x;
// cout << *vp;         // ERROR: cannot dereference void*
cout << *(int*)vp;      // OK after casting back to int*
```

Limitations:
- No pointer arithmetic allowed on `void*` (compiler doesn't know the element size)
- Must be explicitly cast to a concrete type before dereferencing
- Used in generic/low-level contexts (e.g. `memcpy`, `malloc` return type)

---

## 6. Dynamic Memory (`new` / `delete`)

Static/automatic variables have memory allocated at compile time with fixed scope. Dynamic memory is allocated at runtime on the **heap** and persists until explicitly freed.

```cpp
int *p = new int;        // allocate single int on heap
*p = 25;
delete p;                // free it

int *arr = new int[10];  // allocate array of 10 ints
delete[] arr;            // free array (must use [])
```

Rules:
- Every `new` must be matched with exactly one `delete` (or `new[]` with `delete[]`)
- Forgetting `delete` causes a **memory leak**
- Using a pointer after `delete` (without resetting it) causes a **dangling pointer** bug
- After deleting, it's good practice to set `p = nullptr;`

```cpp
int *p = new int(5);
delete p;
p = nullptr;      // prevents accidental reuse
```

---

## 7. Swapping via Pointers

```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    cout << x << " " << y;   // 10 5
}
```

Call-by-pointer passes the **address**, so the function can modify the caller's original variables — it behaves like call-by-reference under the hood, since in both cases the function works on the same memory location rather than a copy.

---

## 8. References

A reference is an **alias** (another name) for an existing variable. Unlike a pointer, it must be initialized when declared and cannot be reseated to refer to something else afterward.

```cpp
int a = 10;
int &ref = a;   // ref is an alias for a
ref = 20;       // changes a too
cout << a;      // 20
```

Reference parameters:

```cpp
void addTen(int &x) {
    x = x + 10;
}

int main() {
    int n = 5;
    addTen(n);
    cout << n;   // 15
}
```

| Pointer | Reference |
|---|---|
| Can be reassigned to point elsewhere | Cannot be re-bound after initialization |
| Can be `nullptr` | Must always refer to a valid object |
| Needs `*` to dereference | Used like a normal variable |
| Needs explicit `&` to get address | No separate address-of step needed |
| Can have pointer arithmetic | No arithmetic |

---

## 9. `this` Pointer

Inside a non-static member function, `this` is an implicit pointer to the object on which the function was called.

```cpp
class Box {
    int side;
public:
    Box& setSide(int side) {
        this->side = side;   // disambiguates member vs parameter
        return *this;        // returns the current object (enables chaining)
    }
    void show() { cout << side; }
};

int main() {
    Box b;
    b.setSide(5).show();   // chained call using *this
}
```

Common uses of `this`:
- Resolving naming conflicts between member and parameter names
- Returning the current object by reference (method chaining)
- Comparing the current object with another (`if (this == &other)`)

---

## 10. Pointers to Functions & Objects

**Pointer to a function** stores the address of a function and can be called through it:

```cpp
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    int (*fp)(int, int) = add;   // function pointer
    cout << fp(3, 4);            // 7
    fp = sub;
    cout << fp(3, 4);            // -1
}
```

Useful for passing behaviour as a parameter (e.g. a comparison function) or building simple callback/menu dispatch tables.

**Pointer to an object** accesses members via the `->` operator instead of `.`:

```cpp
class Point {
public:
    int x = 5;
    void show() { cout << x; }
};

int main() {
    Point p1;
    Point *ptr = &p1;
    ptr->show();        // same as (*ptr).show();
    cout << ptr->x;
}
```

Difference between pointer-to-function and pointer-to-object: a function pointer's type is determined by the function's **signature** (return type + parameter types), while an object pointer's type is determined by the **class**; dereferencing a function pointer calls the function, while dereferencing an object pointer gives the object itself.

---

## 11. Binary Search using Pointers

```cpp
#include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int key) {
    int *low = arr;
    int *high = arr + size - 1;

    while (low <= high) {
        int *mid = low + (high - low) / 2;
        if (*mid == key) return mid - arr;   // return index
        else if (*mid < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 9, 7, 21, 46};   // must be sorted for binary search
    int sorted[] = {2, 7, 9, 21, 46};
    int size = 5;

    int idx = binarySearch(sorted, size, 21);
    if (idx != -1) cout << "Found at index " << idx;
    else cout << "Not found";
}
```

Note: `mid - arr` gives the element's index because subtracting two pointers into the same array returns the number of elements between them (Section 3).

---

## Practice Programs

1. Write a program to swap two numbers using pointers (no extra variable in `main`, swap logic inside the function).
2. Write a program to find the maximum and minimum of two integers using pointer arguments (`findMaxMin(int a, int b, int *max, int *min)`).
3. Write a program that dynamically allocates an array of `n` integers (user-input `n`), fills it, prints the sum, and frees the memory.
4. Write a program demonstrating a reference parameter that doubles the value of the variable passed to it.
5. Write a class `Counter` with a member function that uses `this` to return `*this`, enabling two chained calls like `c.increment().increment().show();`.
6. Write a program with a function pointer that can be set to either an `add` or `multiply` function, and call it based on user menu choice.
7. Write a program to perform binary search on a sorted array using pointer arithmetic (as in Section 11), and print the number of comparisons made.
8. Write a program that demonstrates the difference in output when a pointer is incremented (`p++`) versus when the integer it points to is incremented (`(*p)++`).

---

## Key Takeaways

- A pointer stores an address; `&` gets an address, `*` dereferences it.
- Pointer arithmetic is scaled by the pointed-to type's size, not raw bytes.
- An array name decays to a pointer to its first element in most expressions.
- `void*` can hold any address but must be cast before dereferencing or doing arithmetic.
- `new`/`delete` (and `new[]`/`delete[]`) manage heap memory manually — always pair them to avoid leaks.
- A reference is a fixed alias for a variable: must be initialized, can't be re-bound, no `nullptr`.
- `this` is an implicit pointer to the current object inside non-static member functions.
- Function pointers let behaviour be passed as data; object pointers access members via `->`.
- Call-by-pointer achieves the same effect as call-by-reference by operating on the original memory address.
