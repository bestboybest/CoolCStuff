#include <stdio.h>
#include <stdlib.h>
#define ERR_VAL -1000000000

// Implement stacks and queues with arrays and linked lists

// Structures
struct node
{
    int data;
    struct node *link;
};

struct arrStack
{
    int top, size, capacity;
    int *arr;
};
struct arrStack as;

struct linkStack
{
    int size;
    struct node *head;
};
struct linkStack ls;

struct arrQueue
{
    int front, rear, size, capacity;
    int *arr;
};
struct arrQueue aq;
struct arrQueue caq;

struct linkQueue
{
    int size;
    struct node *front, *rear;
};
struct linkQueue lq;

// Stack array implementation
void asInit()
{
    while (1)
    {
        printf("\nWhat is the total capacity of array you want: ");
        scanf("%d", &as.capacity);
        if (as.capacity < 1)
        {
            printf("\nInvalid value of capacity, retry");
            continue;
        }
        else
        {
            break;
        }
    }
    as.top = -1;
    as.size = 0;
    as.arr = malloc(sizeof(int) * as.capacity);
}

void arrPush(int data)
{
    if (as.top + 1 == as.capacity)
    {
        printf("\nStack Overflow! This operation cannot be performed.\n");
    }
    else
    {
        as.arr[as.top + 1] = data;
        as.top += 1;
        as.size += 1;
    }
}

int arrPop()
{
    if (as.top == -1)
    {
        printf("\nStack underflow! This operation cannot be performed.\n");
        return ERR_VAL;
    }
    else
    {
        as.top -= 1;
        as.size -= 1;
        return as.arr[as.top + 1];
    }
}

int arrPeek()
{
    if (as.size == 0)
    {
        printf("\nStack is empty! No top element.\n");
        return ERR_VAL;
    }
    return as.arr[as.top];
}

int asEmpty()
{
    if (as.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int asFull()
{
    if (as.top + 1 == as.capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int asSize()
{
    return as.size;
}

void asPrint()
{
    printf("\nHere are the elements of the stack: \n");
    for (int i = as.size; i > 0; i--)
    {
        printf("%d ", as.arr[i - 1]);
    }
}

// Stack linked list implementation
void lsInit()
{
    ls.size = 0;
    ls.head = NULL;
}

void lsPush(int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = ls.head;
    ls.head = new;
    ls.size += 1;
}

int lsPop()
{
    if (ls.size == 0)
    {
        printf("\nStack underflow! This operation cannot be performed.\n");
        return ERR_VAL;
    }
    int i = ls.head->data;
    struct node *ptr = ls.head;
    ls.head = ls.head->link;
    free(ptr);
    ls.size -= 1;
    return i;
}

int lsPeek()
{
    if (ls.size == 0)
    {
        printf("\nThere are no elements to peek.\n");
        return ERR_VAL;
    }
    return ls.head->data;
}

int lsEmpty()
{
    if (ls.size == 0)
    {
        return 1;
    }
    return 0;
}

int lssize()
{
    return ls.size;
}

void lsPrint()
{
    struct node *ptr = ls.head;
    printf("\nHere are the elements of the stack: \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

// Normal array queue implementation
void aqInit()
{
    while (1)
    {
        printf("\nWhat is the total capacity of array you want: ");
        scanf("%d", &aq.capacity);
        if (aq.capacity < 1)
        {
            printf("\nInvalid value of capacity, retry");
            continue;
        }
        else
        {
            break;
        }
    }
    aq.front = 0;
    aq.rear = -1;
    aq.size = 0;
    aq.arr = malloc(sizeof(int) * aq.capacity);
}

void aqEnqueue(int data)
{
    if (aq.rear + 1 == aq.capacity)
    {
        printf("\nQueue overflow! Total capacity has been reached! You must create a new stack/queue.\n");
    }
    else
    {
        aq.arr[aq.rear + 1] = data;
        aq.rear += 1;
        aq.size += 1;
    }
}

int aqDequeue()
{
    if (aq.size == 0)
    {
        printf("\nThere are no elements in queue!");
        return ERR_VAL;
    }
    aq.front += 1;
    aq.size -= 1;
    return aq.arr[aq.front - 1];
}

int aqPeekFront()
{
    if (aq.size == 0)
    {
        printf("\nThere is no element to peek");
        return ERR_VAL;
    }
    return aq.arr[aq.front];
}

int aqPeekRear()
{
    if (aq.size == 0)
    {
        printf("\nThere is no element to peek");
        return ERR_VAL;
    }
    return aq.arr[aq.rear];
}

int aqEmpty()
{
    if (aq.size == 0)
    {
        return 1;
    }
    return 0;
}

int aqFull()
{
    if (aq.rear + 1 == aq.capacity)
    {
        return 1;
    }
    return 0;
}

int aqSize()
{
    return aq.size;
}

void aqPrint()
{
    if (aq.size == 0)
    {
        printf("\nThere are no elements to print!");
    }
    else
    {
        printf("\nHere are the elements of queue:\n");
        for (int i = aq.front; i <= aq.rear; i++)
        {
            printf("%d ", aq.arr[i]);
        }
    }
}

// Circular array queue implementation
void caqInit()
{
    while (1)
    {
        printf("\nWhat is the total capacity of array you want: ");
        scanf("%d", &caq.capacity);
        if (caq.capacity < 1)
        {
            printf("\nInvalid value of capacity, retry");
            continue;
        }
        else
        {
            break;
        }
    }
    caq.front = 0;
    caq.rear = -1;
    caq.size = 0;
    caq.arr = malloc(sizeof(int) * caq.capacity);
}

void caqEnqueue(int data)
{
    if (caq.size == caq.capacity)
    {
        printf("\nQueue overflow! Total capacity has been reached!\n");
    }
    else
    {
        caq.rear = (caq.rear + 1) % caq.capacity;
        caq.size += 1;
        caq.arr[caq.rear] = data;
    }
}

int caqDequeue()
{
    if (caq.size == 0)
    {
        printf("\nThere is no element to dequeue!\n");
        return ERR_VAL;
    }
    int temp = caq.front;
    caq.front = (caq.front + 1) % caq.capacity;
    caq.size -= 1;
    return caq.arr[temp];
}

int caqPeekFront()
{
    if (caq.size == 0)
    {
        printf("\nThere is no element to peek");
        return ERR_VAL;
    }
    return caq.arr[caq.front];
}

int caqPeekRear()
{
    if (caq.size == 0)
    {
        printf("\nThere is no element to peek");
        return ERR_VAL;
    }
    return caq.arr[caq.rear];
}

int caqEmpty()
{
    if (caq.size == 0)
    {
        return 1;
    }
    return 0;
}

int caqFull()
{
    if (caq.size == caq.capacity)
    {
        return 1;
    }
    return 0;
}

int caqSize()
{
    return caq.size;
}

void caqPrint()
{
    if (caq.size == 0)
    {
        printf("\nThere are no elements to print!");
    }
    else
    {
        printf("\nHere are the elements of queue:\n");
        if (caq.rear < caq.front)
        {
            for (int i = caq.front; i < caq.capacity; i++)
            {
                printf("%d ", caq.arr[i]);
            }
            for (int i = 0; i <= caq.rear; i++)
            {
                printf("%d ", caq.arr[i]);
            }
        }
        else
        {
            for (int i = caq.front; i <= caq.rear; i++)
            {
                printf("%d ", caq.arr[i]);
            }
        }
    }
}

// Linked list queue implementation
void lqInit()
{
    lq.size = 0;
    lq.front = NULL;
    lq.rear = NULL;
}

void lqEnqueue(int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    if (lq.size == 0)
    {
        lq.rear = new;
        lq.front = lq.rear;
        lq.size += 1;
    }
    else
    {
        lq.rear->link = new;
        lq.rear = new;
        lq.size += 1;
    }
}

int lqDequeue()
{
    if (lq.size == 0)
    {
        printf("\nThere is no element to dequeue!\n");
        return ERR_VAL;
    }
    struct node *temp = lq.front;
    lq.front = lq.front->link;
    int n = temp->data;
    free(temp);
    lq.size -= 1;
    if (lq.size == 0)
    {
        lq.rear = NULL;
    }
    return n;
}

int lqPeekFront()
{
    if (lq.size == 0)
    {
        printf("\nThere is no element to peek");
        return ERR_VAL;
    }
    return lq.front->data;
}

int lqPeekRear()
{
    if (lq.size == 0)
    {
        printf("\nThere is no element to peek");
        return ERR_VAL;
    }
    return lq.rear->data;
}

int lqEmpty()
{
    if (lq.size == 0)
    {
        return 1;
    }
    return 0;
}

int lqSize()
{
    return lq.size;
}

void lqPrint()
{
    if (lq.size == 0)
    {
        printf("\nThere are no elements to print!");
    }
    else
    {
        printf("\nHere are the elements of queue:\n");
        struct node *ptr = lq.front;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}

// Function
int Init()
{
    int op1, op2, op3;
    while (1)
    {
        printf("\n\nPress 0 to exit, press 1 to create a stack, and 2 to create a queue:\n");
        scanf("%d", &op1);
        if (op1 == 0)
        {
            return 0;
        }
        if (op1 != 1 && op1 != 2)
        {
            printf("\nInvalid input, retry");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("\nPress 1 to implement with array and 2 to implement with linked lists:\n");
        scanf("%d", &op2);
        if (op2 != 1 && op2 != 2)
        {
            printf("\nInvalid input, retry");
            continue;
        }
        if (op1 == 1 && op2 == 1)
        {
            asInit();
            return 1;
        }
        else if (op1 == 1 && op2 == 2)
        {
            lsInit();
            return 2;
        }
        else if (op1 == 2 && op2 == 1)
        {
            printf("\nPress 1 for normal array queue, and 2 for circular array queue:\n");
            scanf("%d", &op3);
            if (op3 == 1)
            {
                aqInit();
                return 3;
            }
            else if (op3 == 2)
            {
                caqInit();
                return 5;
            }
            else
            {
                printf("\nInvalid input, retry");
                continue;
            }
        }
        else if (op1 == 2 && op2 == 2)
        {
            lqInit();
            return 4;
        }
    }
}

// Main
int main()
{
    while (1)
    {
        int main = Init();
        if (main == 0)
        {
            break;
        }

        // Stack array implementation
        else if (main == 1)
        {
            printf("\nStack has been initialized.");
            while (1)
            {
                printf("\n\nInput number to perform functions:\n");
                printf("0. Create new stack/queue\n1. Push\n2. Pop\n3. Peek\n4. Check if empty or full\n5. Return size of stack\n6. Print all elements of stack\n");
                int i;
                scanf("%d", &i);
                if (i == 0)
                {
                    free(as.arr);
                    as.arr = NULL;
                    break;
                }
                else if (i == 1)
                {
                    printf("\nWhat number would you like to push?\n");
                    int data;
                    scanf("%d", &data);
                    arrPush(data);
                }
                else if (i == 2)
                {
                    int j = arrPop();
                    if (j != ERR_VAL)
                    {
                        printf("\nPopped element is %d\n", j);
                    }
                }
                else if (i == 3)
                {
                    int j = arrPeek();
                    if (j != ERR_VAL)
                    {
                        printf("\nTopmost element is %d\n", j);
                    }
                }
                else if (i == 4)
                {
                    if (asEmpty())
                    {
                        printf("\nStack is empty\n");
                    }
                    else if (asFull())
                    {
                        printf("\nStack is full\n");
                    }
                    else
                    {
                        printf("\nStack isn't empty nor full\n");
                    }
                }
                else if (i == 5)
                {
                    printf("\nSize of stack is: %d\n", asSize());
                }
                else if (i == 6)
                {
                    asPrint();
                }
                else
                {
                    printf("\nInvalid input, retry:");
                }
            }
        }

        // Stack linked list implementation
        else if (main == 2)
        {
            printf("\nStack has been initialized.");
            while (1)
            {
                printf("\n\nInput number to perform functions:\n");
                printf("0. Create new stack/queue\n1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Return size of stack\n6. Print all elements of stack\n");
                int i;
                scanf("%d", &i);
                if (i == 0)
                {
                    struct node *ptr = ls.head;
                    while (ptr != NULL)
                    {
                        struct node *temp = ptr;
                        ptr = ptr->link;
                        free(temp);
                    }
                    break;
                }
                else if (i == 1)
                {
                    printf("\nWhat number would you like to push?\n");
                    int data;
                    scanf("%d", &data);
                    lsPush(data);
                }
                else if (i == 2)
                {
                    int j = lsPop();
                    if (j != ERR_VAL)
                    {
                        printf("\nPopped element is %d\n", j);
                    }
                }
                else if (i == 3)
                {
                    int j = lsPeek();
                    if (j != ERR_VAL)
                    {
                        printf("\nTopmost element is %d\n", j);
                    }
                }
                else if (i == 4)
                {
                    if (lsEmpty())
                    {
                        printf("\nStack is empty\n");
                    }
                    else
                    {
                        printf("\nStack isn't empty\n");
                    }
                }
                else if (i == 5)
                {
                    printf("\nSize of stack is: %d\n", lssize());
                }
                else if (i == 6)
                {
                    lsPrint();
                }
                else
                {
                    printf("\nInvalid input, retry:");
                }
            }
        }

        // Normal array queue implementation
        else if (main == 3)
        {
            printf("\nQueue has been initialized.");
            while (1)
            {
                printf("\n\nInput number to perform functions:\n");
                printf("0. Create new stack/queue\n1. Enqueue\n2. Dequeue\n3. Peek at front element\n4. Peek at rear element\n5. Check if empty/full\n6. Return size of queue\n7. Print all elements of queue\n");
                int i;
                scanf("%d", &i);
                if (i == 0)
                {
                    free(aq.arr);
                    aq.arr = NULL;
                    break;
                }
                else if (i == 1)
                {
                    printf("\nWhat number would you like to enqueue?\n");
                    int data;
                    scanf("%d", &data);
                    aqEnqueue(data);
                }
                else if (i == 2)
                {
                    int j = aqDequeue();
                    if (j != ERR_VAL)
                    {
                        printf("\nDequeued element is %d\n", j);
                    }
                }
                else if (i == 3)
                {
                    int j = aqPeekFront();
                    if (j != ERR_VAL)
                    {
                        printf("\nFront element is %d\n", j);
                    }
                }
                else if (i == 4)
                {
                    int j = aqPeekRear();
                    if (j != ERR_VAL)
                    {
                        printf("\nRear element is %d\n", j);
                    }
                }
                else if (i == 5)
                {
                    if (aqEmpty())
                    {
                        printf("\nQueue is empty\n");
                    }
                    else if (aqFull())
                    {
                        printf("\nQueue is full\n");
                    }
                    else
                    {
                        printf("\nQueue isn't empty nor full\n");
                    }
                }
                else if (i == 6)
                {
                    printf("\nSize of queue is: %d\n", aqSize());
                }
                else if (i == 7)
                {
                    aqPrint();
                }
                else
                {
                    printf("\nInvalid input, retry:");
                }
            }
        }

        // Linked list queue implementation
        else if (main == 4)
        {
            printf("\nQueue has been initialized.");
            while (1)
            {
                printf("\n\nInput number to perform functions:\n");
                printf("0. Create new stack/queue\n1. Enqueue\n2. Dequeue\n3. Peek at front element\n4. Peek at rear element\n5. Check if empty\n6. Return size of queue\n7. Print all elements of queue\n");
                int i;
                scanf("%d", &i);
                if (i == 0)
                {
                    struct node *ptr = lq.front;
                    while (ptr != NULL)
                    {
                        struct node *temp = ptr;
                        ptr = ptr->link;
                        free(temp);
                    }
                    break;
                }
                else if (i == 1)
                {
                    printf("\nWhat number would you like to enqueue?\n");
                    int data;
                    scanf("%d", &data);
                    lqEnqueue(data);
                }
                else if (i == 2)
                {
                    int j = lqDequeue();
                    if (j != ERR_VAL)
                    {
                        printf("\nDequeued element is %d\n", j);
                    }
                }
                else if (i == 3)
                {
                    int j = lqPeekFront();
                    if (j != ERR_VAL)
                    {
                        printf("\nFront element is %d\n", j);
                    }
                }
                else if (i == 4)
                {
                    int j = lqPeekRear();
                    if (j != ERR_VAL)
                    {
                        printf("\nRear element is %d\n", j);
                    }
                }
                else if (i == 5)
                {
                    if (lqEmpty())
                    {
                        printf("\nQueue is empty\n");
                    }
                    else
                    {
                        printf("\nQueue isn't empty\n");
                    }
                }
                else if (i == 6)
                {
                    printf("\nSize of queue is: %d\n", lqSize());
                }
                else if (i == 7)
                {
                    lqPrint();
                }
                else
                {
                    printf("\nInvalid input, retry:");
                }
            }
        }

        // Circular array queue implementation
        else if (main == 5)
        {
            printf("\nQueue has been initialized.");
            while (1)
            {
                printf("\n\nInput number to perform functions:\n");
                printf("0. Create new stack/queue\n1. Enqueue\n2. Dequeue\n3. Peek at front element\n4. Peek at rear element\n5. Check if empty/full\n6. Return size of queue\n7. Print all elements of queue\n");
                int i;
                scanf("%d", &i);
                if (i == 0)
                {
                    free(caq.arr);
                    caq.arr = NULL;
                    break;
                }
                else if (i == 1)
                {
                    printf("\nWhat number would you like to enqueue?\n");
                    int data;
                    scanf("%d", &data);
                    caqEnqueue(data);
                }
                else if (i == 2)
                {
                    int j = caqDequeue();
                    if (j != ERR_VAL)
                    {
                        printf("\nDequeued element is %d\n", j);
                    }
                }
                else if (i == 3)
                {
                    int j = caqPeekFront();
                    if (j != ERR_VAL)
                    {
                        printf("\nFront element is %d\n", j);
                    }
                }
                else if (i == 4)
                {
                    int j = caqPeekRear();
                    if (j != ERR_VAL)
                    {
                        printf("\nRear element is %d\n", j);
                    }
                }
                else if (i == 5)
                {
                    if (caqEmpty())
                    {
                        printf("\nQueue is empty\n");
                    }
                    else if (caqFull())
                    {
                        printf("\nQueue is full\n");
                    }
                    else
                    {
                        printf("\nQueue isn't empty nor full\n");
                    }
                }
                else if (i == 6)
                {
                    printf("\nSize of queue is: %d\n", caqSize());
                }
                else if (i == 7)
                {
                    caqPrint();
                }
                else
                {
                    printf("\nInvalid input, retry:");
                }
            }
        }
    }

    return 1;
}