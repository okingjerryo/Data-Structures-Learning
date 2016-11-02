# Data-Structures-Learning
Basic Notes about C/C++ and Data Structure course.

* C/C++ 
  * [Reference](#Reference)
    * [Basic Data Types](#Basic_Data_Types)
    * [Struct](#Struct)
    * [Pointer](#Pointer)
    * [Parameters in Function](#Parameters_in_Function)
  * [Struct](#Struct)
    * [Declare & Define](#Declare_and_Define)
    * [Initialization](#Initialization)
    * [Access](#Access)
    * [Array of Structs](#Array_of_Structs)
    * [Point](#)
    * [Typedef](#Typedef)
  
---
<h2 id = "Reference">Reference</h2>
<h3 id = "Basic_Data_Types">Basic Data Types</h3>

    #include <iostream>
    using namespace std;
    int main(void)
    {
        int a = 1;
        int &b = a;
    
        b = 2
        cout << a << endl;
        return 0;
    }

<h3 id = "Struct">Struct</h3>

    #include <iostream>
    using namespace std;
    
    typedef struct
    {
        int x;
        int y;
    }Book
    
    int main(void)
    {
        Book A;
        Book &B = A;
        B.x = 1;
        B.y = 2;
        cout<< A.x << A.y << endl;
        return 0;
    }
    
<h3 id = "Pointer">Pointer</h3>

    #include <iostream>
    using namespace std;
    int main(void)
    {
        int x = 1;
        int *p = &x;
        int *&q =p;
        *q = 2;
        cout << x << endl;
        return 0;
    }
    
<h3 id = "Parameters_in_Function">Parameters in Function</h3>
Code of function:
    
    void changeNum(int &a, int &b)
    {
        int c = 0
        c = a;
        a = b;
        b = c;
    }
    
Use the function:
    
    int x = 1, y = 2;
    changeNum(x, y);

<h2 id ="Struct">Struct</h2>

A struct is an aggregate of elements of arbitrary types.

<h3 id = "Declare_and_Define">Declare & Define</h3>

    struct NameOfStruct
    {
        /* Arbitrary data types can be added here */
    }

For example, the code below creates a struct describing a labtop:

    struct labtop
    {
        char name[20];
        int price;
    };

Then we used the struct declared above to define a struct

    struct labtop MacPad;
 
Or define the struct directly when it be declared.

    struct labtop
    {
        char name[20];
        int price;
    }MacPad;
 
Also a struct can be defined without the name of struct declared.
  
    struct
    {
        char name[20];
        int price;
    }MacPad;

<h3 id = "Initialization">Initialization</h3>

Use a pair of curly braces to surround the values and the values will be assigned to the struct variables in order.

    struct labtop MacPad = {"MacPad Pro", 100};

<h3 id = "Access">Access</h3>

The struct variable can be accessed with `.`

    printf("%s\n", MacPad.name);

<h3 id = "Array_of_Structs">Array of Structs</h3>

    struct labtop Labtops[2] = {{"MacPad Pro", 100}, {"ThinkBook", 200}};
    printf("%s\n%s\n", Labtops[0].name, Labtops[1].price);

<h3 id ="Pointer">Pointer</h3>
    
    struct labtop *m
    m = &MacPad
    printf("name = %s\n",(*m).name);

Or with the operator `->`

    printf("name = %s", m->name);

**Attention**: The braces of `(*m)` can not be omitted in that dot operator (`.`) keeps a high priority!

    struct labtop *M
    M = Labtops; // M->name == Labtops[0].name
    printf("%s\n", M->name) // It will access the first element of the array.
    
    p++; 
    printf("%s\n", M->name) // It will access Labtops[1], just like "Labtops + 1"

<h3 id = "Typedef">Typedef</h3>
`typedef` is a reserved keyword which is used to create an alias for a data type. `typedef` statement must be terminated with a semicolon (`;`).
    
    typedef int integer
    integer a = 1;

It's the same as the code

    int a = 1;
    
In the situation:

    typedef  int *p

It creates an alias for `int *` called `p`. Therefore, when a new point is defined, the code can be written as below

    p q = NULL; // int *q = NULL
    
After creating a new struct type, the new struct type can be used as following
    
    struct student
    {
        int majorNum;
        int classNum;
    };
    
    struct student /* some statement here... */;
    
When it is added `typedef` statement, the code can be written easiler and more clear as

    typedef struct student
    {
        int majorNum;
        int classNum;
    }stu;
    
    stu /* some statement here... */;
