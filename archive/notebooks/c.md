- there are standards for writing C:
    - https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html
    - https://google.github.io/styleguide/cppguide.html#Self_contained_Headers
- pointers point to the first memory location of the variable
    - they are denoted by *
- Calling ++ on a pointer will increment the postion of the pointer by 1
- All chars end with '\0'

## 20240-11-16

Structs are aliases for other existing data types in C;

```c
typedef struct  {
    int a;
    int b;
} NewStructName; 

NewStructName item {1, 2};

item.a // 1
item.b // 2

```

Structs can be self referential such as a linked list node. It contains a value and two pointers to other linked list nodes

```c
typedef struct LLNode {
    int val;
    struct LLNode *next ;
    struct LLNode *prev ;
} LLNode; 

LLNode node {1, NULL, NULL};

item.node // 1
item.prev // NULL
```

However there are a couple intricacies that need to be addressed
- A struct needs a tag, a unique name that each struct should have. That is the first LLNode in `typedef struct LLNode {`
- A typedef should define an alias . That is the second LLNode on line `} LLNode;`
- To have a self-referential struct that doesn't cause an inifinite size error we use pointers instead of instance of the struct itself
    - this is done using `struct LLNode *next ;` because C knows already the size of a pointer
