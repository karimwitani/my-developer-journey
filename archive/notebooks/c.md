- there are standards for writing C:
    - https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html
    - https://google.github.io/styleguide/cppguide.html#Self_contained_Headers
- pointers point to the first memory location of the variable
    - they are denoted by *
- Calling ++ on a pointer will increment the postion of the pointer by 1
- All chars end with '\0'

## 20240-11-16
### Defining Structs
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

### Printing out memory addresses
In order to inspect the addresses of a variable, use %p instead of %d
```c
//node is a pointer while null_check is an int (0 or 1)
printf("node %p\n", node); 
printf("null_check %d\n", null_check);
```

## 2024-11-17
### Heap vs stack allocation

In C there are two ways memory is allocated to variables:
1. Heap allocation
2. Stack allocation

Stack allocation happens within the call stack of a function call. This is done without dynamic memory allocation (we dont use malloc). The lifetime of these variables is restricted to the function execution and the memory is freed automatically once the function returns. Because the call stack work with last in, first out (aka LIFO) the memory access is quicker.

Stack allocation on the other hand has two main limitations:
1. Size limitations which could cause stack overflows, often caused by large local variables or deep recursions
2. Risks of segmentation faults if the stack allocated is pointed at by a global variable, that global variable would be holding onto a dangling pointer

Example: the node x is allocated on the stack and once the function returns the memory allocated to the node is freed. However the linked list head is now a dangling pointer which could lead to bad behavior/crashes/corrupted data.

```c
void list_insert(LinkedList *L, int val)
{
    LLNode x = {NULL, NULL, val}; // Stack allocation
    if (L->head != NULL)
    {
        L->head->prev = &x;
    }
    L->head = &x;
    x.prev = NULL;
}
```

Heap allocation on the other hand refers to memory that is allocated from a large pool of unused data called the heap. this is done every time we call malloc, calloc or realloc in C. They remain in memory untill they are deallocated using `free()` and can persist beyond the function that created them. Access is slightly slower than stack-allocated memory but on the other hand has more flexibility.

Here is the table in Markdown format:
| Aspect             | Stack Allocation                                           | Heap Allocation                                      |
|--------------------|------------------------------------------------------------|------------------------------------------------------|
| **Allocation**     | Automatic by the system during function calls              | Manual using functions like `malloc` and `free`      |
| **Lifetime**       | Limited to the function scope                              | Remains until explicitly deallocated                 |
| **Memory Size**    | Limited (can cause stack overflow)                         | Larger (limited by system memory)                    |
| **Speed**          | Faster access                                              | Slower access due to overhead                        |
| **Management**     | Managed automatically                                      | Managed by the programmer                            |
| **Usage Scenario** | Temporary variables, function parameters, return addresses | Data needing persistence, large data, dynamic arrays |


## 2024-11-18
### What is array decay to pointers in C?

When passing an array to a function in C, we don't copy the entire array. Only the pointer to the first element of the array is passed. In the below example both are equivalent. Since we pass a pointer to the array, any changes made to it inside the function are reflected after the function returns.

```c
void func(int arr[]);

void func(int *arr);
```

### Why should you always pass an array's size to a function?

Because of decay to pointers, functions that take in arrays implicitly convert them to pointers to the first elements. In this case, computing the size of the array inside the function will return only the size of the pointer (ie: 2 bytes). 

```c
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void function_taking_array(int array[])
{
    printf("The array is of size %d\n", ARRAY_SIZE(array)); 
}


int main ()
{
    int array[] = {1,2,3};
    printf("The array is of size %d\n", ARRAY_SIZE(array)); // prints 3
    function_taking_array(array); // prints 2
}
```