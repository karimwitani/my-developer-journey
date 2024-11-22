#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    struct LLNode *next;
    struct LLNode *prev;
    int val;
} LLNode;

typedef struct {
    LLNode *head;
} LinkedList;

LLNode* create_node(int val)
{
    LLNode *node = malloc(sizeof(LLNode));
    
    if (node == NULL)
    {
        fprintf(stderr, "Error: could not allocate memory to new node.\n");
        exit(EXIT_FAILURE);
    }

    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


LLNode* list_search(LinkedList *L, int val)
{
    LLNode *x = L->head;

    while (x != NULL && x->val != val)
    {
        x = x->next;
    }
    return x;
}

void list_insert(LinkedList *L, int val)
{

    LLNode *x = create_node(val);

    x->next = L->head;   // Points to the current head of the list. Set to NULL empty, else points to another node
    if (L->head != NULL) // If list wasn't empty, sets the old head's prev to point to x instead of null
    {
        L->head->prev = x;
    }
    L->head = x; // New head pointer to x
    x->prev = NULL; // New head's prev is null as it's a the list's start
}

void list_delete(LinkedList *L, LLNode *node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    else
    {
        L->head = node->next;
    }

    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    free(node);
}

// int main ()
// {
//     LinkedList ll = { NULL };  // Initialize head  to NULL
//     LLNode *node;
//     int null_check;

//     // Insert values into list    
//     list_insert(&ll, 3);
//     list_insert(&ll, 4);
    
//     // Search for value 3
//     node = list_search(&ll, 3);
//     null_check = (node == NULL);

//     if (node != NULL)
//     {
//         printf("Found node with val %d\n", node->val);
//     }
//     else
//     {
//         printf("Node with val 3 not found\n");
//     }
//     printf("null_check %d\n", null_check);

//     // Delete the node with value 3
//     if (node != NULL)
//     {
//         list_delete(&ll, node);
//     }

//     // Search again for value 3
//     node = list_search(&ll, 3);
//     null_check = (node == NULL);
//     if (node != NULL)
//     {
//         printf("Found node with val %d\n", node->val);
//     }
//     else
//     {
//         printf("Node with val 3 not found after deletion\n");
//     }
//     printf("null_check %d\n", null_check);

//     // Clean up remaining nodes
//     // Since we only have one node left (with val 4), we can delete it
//     node = list_search(&ll, 4);
//     if (node != NULL)
//     {
//         list_delete(&ll, node);
//     }

//     return 0;
// }