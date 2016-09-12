# Data-Structures-Learning
Some notes about Data Structures.

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
    
### Parameters in Functions
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
