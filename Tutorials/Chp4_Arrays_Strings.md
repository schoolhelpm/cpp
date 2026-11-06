# Chapter 4: Arrays & Strings

## Table of Contents
1. [Introduction](#1-introduction)
2. [1D Arrays](#2-1d-arrays)
3. [2D Arrays](#3-2d-arrays)
4. [Array Algorithms](#4-array-algorithms)
5. [More Array Algorithms](#5-more-array-algorithms)
6. [Menu-Driven Array Programs](#6-menu-driven-array-programs)
7. [C-style Strings](#7-c-style-strings)
8. [`string` Class](#8-string-class)
9. [Menu-Driven String Programs](#9-menu-driven-string-programs)
10. [Trace / Debug Exercises](#10-trace--debug-exercises)
11. [Differentiate Between](#11-differentiate-between)
12. [Practice Programs](#12-practice-programs)
13. [Key Takeaways](#13-key-takeaways)

---

## 1. Introduction

An **array** is a collection of elements of the same type stored in contiguous memory, accessed using an index. A **string** is a sequence of characters — either a C-style char array or an object of the `string` class.

Arrays and strings let us work with collections of data instead of handling one variable at a time.

---

## 2. 1D Arrays

### Declaration & Initialization
```cpp
int arr[5];                        // uninitialized
int arr[5] = {1, 2, 3, 4, 5};      // fully initialized
int arr[5] = {1, 2};               // remaining elements = 0
int arr[] = {1, 2, 3};             // size inferred = 3
```

### Traversal
```cpp
int arr[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";
```

- Index starts at `0`, ends at `size - 1`.
- Accessing out-of-bounds indices is **undefined behaviour** (no automatic bounds checking in C++).

---

## 3. 2D Arrays

### Declaration & Initialization
```cpp
int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
```

### Traversal
```cpp
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
        cout << mat[i][j] << " ";
    cout << endl;
}
```

### Common Matrix Operations
```cpp
// Matrix addition
int C[2][3];
for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
        C[i][j] = A[i][j] + B[i][j];
```

Matrix multiplication requires `A`'s columns == `B`'s rows; result size = `A.rows x B.cols`.

---

## 4. Array Algorithms

### Min, Max, Average
```cpp
int arr[5] = {12, 4, 9, 7, 25};
int mn = arr[0], mx = arr[0], sum = 0;
for (int i = 0; i < 5; i++) {
    if (arr[i] < mn) mn = arr[i];
    if (arr[i] > mx) mx = arr[i];
    sum += arr[i];
}
cout << "Min: " << mn << " Max: " << mx << " Avg: " << (float)sum / 5;
```

### Linear Search — O(n)
```cpp
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}
```

### Binary Search — O(log n), requires sorted array
```cpp
int binarySearch(int arr[], int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

---

## 5. More Array Algorithms

### Remove Duplicates (from a sorted array)
```cpp
int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] != arr[j])
            arr[++j] = arr[i];
    return j + 1;   // new length
}
```

### Merge Two Sorted Arrays
```cpp
void merge(int a[], int n, int b[], int m, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
        result[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < n) result[k++] = a[i++];
    while (j < m) result[k++] = b[j++];
}
```

---

## 6. Menu-Driven Array Programs

Typical exam pattern: one program offering multiple operations via a loop + `switch`.

```cpp
int choice;
do {
    cout << "1.Min/Max/Avg 2.Linear Search 3.Binary Search 4.Exit\n";
    cin >> choice;
    switch (choice) {
        case 1: /* ... */ break;
        case 2: /* ... */ break;
        case 3: /* ... */ break;
        case 4: cout << "Exiting\n"; break;
        default: cout << "Invalid choice\n";
    }
} while (choice != 4);
```

---

## 7. C-style Strings

A C-style string is a `char` array terminated by `'\0'` (null character).

```cpp
char str[20] = "Hello";     // stores H,e,l,l,o,'\0'
char str2[] = "World";      // size auto = 6
cout << str;                // cout stops at '\0'
```

- Common functions (from `<cstring>`): `strlen()`, `strcpy()`, `strcat()`, `strcmp()`.
- Writing beyond the array bounds (e.g. a string longer than the array) causes **buffer overflow** — undefined behaviour.

```cpp
#include <cstring>
char a[20] = "Hi ";
strcat(a, "there");         // a = "Hi there"
cout << strlen(a);          // length excluding '\0'
```

---

## 8. `string` Class

The `string` class (`<string>`) is a safer, dynamically-sized alternative to C-style strings.

| Function | Purpose |
|---|---|
| `s.length()` / `s.size()` | Number of characters |
| `s.substr(pos, len)` | Extract substring |
| `s.find(sub)` | Index of first occurrence, or `string::npos` |
| `s + t` | Concatenation |
| `s[i]` | Character access |
| `s.empty()` | Checks if string is empty |

```cpp
#include <string>
string s = "Hello World";
cout << s.length();              // 11
cout << s.substr(0, 5);          // "Hello"
cout << s.find("World");         // 6
if (s.find("xyz") == string::npos) cout << "Not found";
```

---

## 9. Menu-Driven String Programs

### Length
```cpp
string s;
cin >> s;
cout << s.length();
```

### Check if First Letter of Every Word is Uppercase
```cpp
bool checkCaps(string s) {
    bool newWord = true;
    for (char c : s) {
        if (newWord && c != ' ' && !isupper(c)) return false;
        newWord = (c == ' ');
    }
    return true;
}
```

### Reverse a String
```cpp
string reverseStr(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) swap(s[i++], s[j--]);
    return s;
}
```

---

## 10. Trace / Debug Exercises

**Trace the output:**
```cpp
int arr[5] = {5, 10, 15, 20, 25};
cout << arr[1] + arr[3];
```
*Output: 30 (10 + 20)*

**Debug the code:**
```cpp
int arr[5];
for (int i = 0; i <= 5; i++)   // bug: should be i < 5
    arr[i] = i;
```
*Error: loop runs from 0 to 5 (6 iterations) but array has only 5 valid indices (0–4) → out-of-bounds write at `arr[5]`.*

**Trace:**
```cpp
char str[10] = "Cat";
strcat(str, "Dog");
cout << str;
```
*Output: CatDog*

---

## 11. Differentiate Between

| Topic 1 | Topic 2 | Key Difference |
|---|---|---|
| Array | String | Array holds elements of any single type; a string is specifically a sequence of characters |
| Linear Search | Binary Search | Linear: O(n), works on unsorted data; Binary: O(log n), requires sorted data |
| C-style string | `string` class | C-style: fixed-size char array, manual null-termination, `<cstring>` functions; `string`: dynamic size, member functions, safer |
| 1D Array | 2D Array | 1D: single index/row of data; 2D: row & column index, used for matrices/tables |

---

## 12. Practice Programs

1. Write a program to find the second-largest element in an array.
2. Write a menu-driven program for array operations: min, max, average, linear search, binary search.
3. Write a program to check if a string is a palindrome.
4. Write a program to count vowels and consonants in a string.
5. Write a program to merge two sorted arrays into one sorted array.
6. Write a program to transpose a 2D matrix.

---

## 13. Key Takeaways

- Arrays store same-type elements contiguously; index from `0` to `size-1`; no automatic bounds checking.
- Binary search needs sorted data and is far faster than linear search for large arrays.
- C-style strings rely on `'\0'` termination and manual memory handling via `<cstring>`; the `string` class is safer and has built-in functions.
- Matrix operations (add, multiply, transpose) are common 2D array exam programs.
- Menu-driven programs combining several array/string operations are a frequent exam pattern.
