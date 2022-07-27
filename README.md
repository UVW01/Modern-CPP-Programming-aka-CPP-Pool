# C++ Pool
This project contains a bunch of sub modules which—themselves—contain mini programs aimed at teaching you the basics of the mighty **C++** language. Hope you like this humble explanation of different part of this awesome language.

### Rules

- _C++11_ (and derived forms) and _Boost_ libraries are **forbidden**. The following functions are forbidden too: `*printf()`, `*alloc()` and `free()`.

- The using namespace `<ns_name>` and friend keywords are **forbidden**

- You **aren't allowed** to use the _STL_. That means: **no** _Containers (vector/list/map/and so forth)_ and **no** _Algorithms (anything that requires to include the `<algorithm>` header)_

- Any function implementation put in a header file _(except for function templates)_ **means 0** to the exercise

- You are **allowed** to use the _STL_ in _Module 08_ only.

- From _Module 02_ to _Module 08_, your classes **must be** designed in the _Orthodox Canonical Form_, **except** when explicitely stated otherwise.

## What is ...

### `Class` in C++
It is a user-defined data type,  which has data members _(its own data variables)_ and member functions _(it own functions that are used to manipulate the previously mentionned data members)_. It is like a blueprint for an _Object_, and defined as the folowing:

![Class definition in C++](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Classes-and-Objects-in-C.png)

### Allocation with `new`
The C++ operator new allocates heap memory. The delete operator frees heap memory. For every new, you should use a delete so that you free the same memory you allocated:

```c++
char* str = new char[30];   // Allocate 30 bytes to house a string.
delete []str;               // Clear those 30 bytes and make str point nowhere.
str = nullptr;              // set the pointer to null after deletion
```

### `namespace` in C++
A namespace is similar to a folder. It is a way to organize your code by grouping _related functions_ and _variables_ into a _single unit_ that can be accessed by other parts of your program or by other people who might need to use your code in the future, and you can also use it to avoid _name conflicts_ between similarly named variables or functions. 

```c++
namespace MyNamespace {
    void myFunction();
    int myVariable;
}
```

To access Namespaces in C++, you need to use the following syntax if you want to use them in the current scope:

```c++
ns_name::ns_name_function();
ns_name::ns_variable;
``` 

or you can use the `using namespace ns_name` syntax if you want to use them in the global scope.

```c++
using namespace ns_name;
ns_name_function();
ns_variable;
```

but that means you can't use the `ns_name::ns_name_function()` syntax anymore. And that any other variables or functions with the same name as the ones in the namespace will be shadowed.

### The difference between a Class and an Object
The difference between a Class and an Object is that a Class is a blueprint for an Object, and an Object is an instance of a Class. I.e. you can create as many Objects as you want from a Class, e.g. :

```c++
MyClass myObject;
MyClass myOtherObject;

myObject.myFunction();
myOtherObject.myOtherFunction();
myObject.myVariable = 10;
```

The diffrence between a a global variable and a namespace is that a global variable is accessible from anywhere in the program, and a namespace is only accessible from within the namespace. Another thing is that a namespace is a way to organize your code, and a global variable is a way to access your data from anywhere in the program.






## Glossary

**Static Member Function:** is a function that is defined inside a class, but it is not part of the object. It is a function that is called without an object.

The difference between `.` and `::` in C++ is that `.` is used to access data members of an object, and `::` is used to access static members of a class.

`::` _**(scope resolution operator):**_ is used to access a member of a _Class_ or a _Namespace_. Don't confuse it with the `.` operator, as this latter is used to access a member of an _Object_.

`<<` _**(stream insertion operator)**_  is used to insert data into a stream. Meaning that you can use it to insert data into a stream, and it will be printed out.

`>>` _**(stream extraction operator)**_ is used to extract data from a stream. Meaning that you can use it to extract data from a stream, and it will be read in.
 
**Stream** in _C++_ is a way to transfer data from the computer to the user, and vice versa.
