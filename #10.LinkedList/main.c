#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
}Node;

Node *createNode(int value)
{
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_back(Node **ptp, int value)
{
    if(*ptp == NULL)
    {
        *ptp = createNode(value);
    }
    else
    {
        Node *temp = *ptp;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(value);
    }
}

void insert(Node **ptp, int position, int value)
{
    Node *temp = *ptp;
    int i = 0;
    while (temp->next != NULL && i !=(position-1))
    {
        temp = temp->next;
        i++;
    }
    Node *p = createNode(value);
    p->next = temp->next;
    temp->next = p;
}
int main(int argc, char const *argv[])
{
    Node *ptr = NULL;

    push_back(&ptr, 7);
    push_back(&ptr, 3);
    push_back(&ptr, 1);
    push_back(&ptr, 4);

    insert(&ptr, 2, 99);
    
    return 0;
}
