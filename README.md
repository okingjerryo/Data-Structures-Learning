# Data-Structures-Learning
Some notes about Data Structures.

* C++
  * Reference
    * Basic Data Types
    * Struct
    * Point
    * Parameters in Function
  * Struct
    * Declare & Define
    * Initialize
    * Access
    * Array of Structs
    * Typedef
  
---
#0x00 C++
## Reference
### Basic Data Types
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

### Struct
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
    
### Point
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
    
### Parameters in Function
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

## Struct

A struct is an aggregate of elements of arbitrary types.

### Declare & Define

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

    struct labtop Macintoss;
 
Or define the struct directly when it be declared.

    struct labtop
    {
      char name[20];
      int price;
    }Macintoss;
 
 Also a struct can be defined without the name of struct declared.
  
    struct
    {
      char name[20];
      int price;
    }Macintoss;

### Initialize

Use a pair of curly braces to surround the values and the values will be assigned to the struct variables in order.

    struct labtop Macintoss = {"Macintoss Alpha", 50};

### Access

The struct variable can be accessed with `.`

    printf("%s\n", Macintoss.name);

### Array of Structs

    struct labtop macintossGroup[2] = {{"Macintoss Alpha", 50}, {"Macintoss Beta", 100}};
    printf("%s\n%s\n",macintossGroup[0].name,macintossGroup[1].price);

###Point
    
    struct labtop *m
    m = &Macintoss
    printf("name = %s\n",(*m).name);

Or with the operator `->`

    printf("name = %s", m->name);

Attention: The braces of `(*m)` can not be omitted in that dot operator (`.`) keeps a high priority!

    struct labtop *M
    M = macintossGroup; // M->name macintossGroup[0].name
    printf("%s\n", M->name) // It will access the first element of the array.
    
    p++; 
    printf("%s\n", M->name) // It will access macintossGroup[1], just like "macintossGroup + 1"

### Typedef
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

