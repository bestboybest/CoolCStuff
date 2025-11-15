#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem statement: Initialize singly linked list and then perform a bunch of operations on it ig
// To make it a bit different, make it so that the linked list is a list of elements which are sums of first n squares

// Singly linked list
struct node
{
    int data;
    struct node *link;
};

// Take input as we need
int input(char inp[])
{
    int n;
    if (strcmp(inp, "none") == 0)
    {
        printf("\nEnter element to add:\n ");
        scanf("%d", &n);
        return n;
    }
    else
    {
        printf("\n%s:\n", inp);
        scanf("%d", &n);
        return n;
    }
}

// Quickly print dashes
void dashes()
{
    printf("\n--------------------------------------------------------------------------------------");
}

// Get number of elements of linked list
int numLink(struct node *head)
{
    // Find no of elements in linked list
    int n = 1;
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        n++;
        ptr = ptr->link;
    }
    return n;
}

// Check if a certain element is in linked list
int scanCheck(struct node *head, int data)
{
    // Check if a certain element is in a linked list
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        if (ptr->data == data)
        {
            return 1;
        }
        ptr = ptr->link;
    }
    if (ptr->data == data)
    {
        return 1;
    }
    return 0;
}

void addEnd(struct node *head, int data)
{
    // Traverse till end of linked list
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    // Add new node
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    ptr->link = new;
}

struct node *addStart(struct node *head, int data)
{
    // Add element at start of linked list
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = head;
    return new;
}

void addMiddle(struct node *head, int data, int pos)
{
    // Traverse to element we need to travel to
    struct node *ptr = head;

    for (int i = 0; i < pos - 2; i++)
    {
        ptr = ptr->link;
    }

    // Add element in middle
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = ptr->link;
    ptr->link = new;
}

void addAfter(struct node *head, int data, int n)
{
    struct node *ptr = head;

    while (ptr->data != n)
    {
        ptr = ptr->link;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = ptr->link;
    ptr->link = new;
}

void addBefore(struct node *head, int data, int n)
{
    struct node *ptr = head;

    while (ptr->link->data != n)
    {
        ptr = ptr->link;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = ptr->link;
    ptr->link = new;
}

void removeLast(struct node *head)
{
    struct node *ptr = head;
    int n = numLink(ptr);

    for (int i = 0; i < n - 2; i++)
    {
        ptr = ptr->link;
    }
    struct node *temp = ptr->link;
    ptr->link = NULL;
    free(temp);
}

struct node *removeFirst(struct node *head)
{
    struct node *temp = head->link;
    free(head);
    return temp;
}

void removeNum(struct node *head, int n)
{
    struct node *ptr = head;

    while (ptr->link->data != n)
    {
        ptr = ptr->link;
    }
    struct node *temp = ptr->link;
    ptr->link = ptr->link->link;
    free(temp);
}

void removePos(struct node *head, int pos)
{
    struct node *ptr = head;

    for (int i = 0; i < pos - 2; i++)
    {
        ptr = ptr->link;
    }

    struct node *temp = ptr->link;
    ptr->link = ptr->link->link;
    free(temp);
}

void replaceNum(struct node *head, int data, int n)
{
    struct node *ptr = head;

    while (ptr->data != n)
    {
        ptr = ptr->link;
    }
    ptr->data = data;
}

void replacePos(struct node *head, int data, int pos)
{
    struct node *ptr = head;

    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->link;
    }

    ptr->data = data;
}

void linkedSumSqr(struct node *head, int n)
{
    int sumSqr = 1;

    // Loop n-1 times (n-1 elemnts to add)
    for (int i = 2; i < n + 1; i++)
    {
        sumSqr += (i * i);
        addEnd(head, sumSqr);
    }
}

void printList(struct node *head)
{
    int n = numLink(head);
    // Print linked list
    struct node *ptr = head;
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
}

void freeAll(struct node *head)
{
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        struct node *temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
    free(ptr);
}

int main()
{
    // Creating our linked list (data = sum of squares of first n numbers)
    // Creating our head node
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    // Initialize linked list
    int n;
    n = input("How many sums of squares would you want in the linked list?");
    if (n < 1)
    {
        printf("Bruh u messed this up itself -_-\n");
        return 1;
    }
    linkedSumSqr(head, n);
    printf("\nHere is your initialized linked list: \n");
    printList(head);

    // Create a loop that runs forever that allows u to edit the linked list
    int loop;
    while (1)
    {
        loop = input("\nPress 0 to exit loop, 1 to view linked list, 2 to add element, 3 to remove element, 4 to replace element");
        if (loop == 0)
        {
            dashes();
            freeAll(head);
            return 0;
        }

        else if (loop == 1)
        {
            printList(head);
        }

        else if (loop == 2)
        {
            int i;
            i = input("Press 0 to return, 1 to add element at the end of list, 2 to add in the middle of list, 3 to add at the start of list, 4 to add after a certain element, 5 to add before a certain element");

            if (i == 0)
            {
                continue;
            }
            else if (i == 1)
            {
                int n;
                n = input("none");
                addEnd(head, n);
            }
            else if (i == 2)
            {
                int pos, n;
                pos = input("Enter which position you would like to add to");
                if ((pos > numLink(head) + 1) || (pos < 1))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                else if (pos == 1)
                {
                    n = input("none");
                    head = addStart(head, n);
                }
                else
                {
                    n = input("none");
                    addMiddle(head, n, pos);
                }
            }
            else if (i == 3)
            {
                int n;
                n = input("none");
                head = addStart(head, n);
            }
            else if (i == 4)
            {
                int element, n;
                element = input("After which number do you want to add element?");
                if (!scanCheck(head, element))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                n = input("none");
                addAfter(head, n, element);
            }
            else if (i == 5)
            {
                int element, n;
                element = input("Before which number do you want to add element?");
                if (!scanCheck(head, element))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                if (head->data == element)
                {
                    n = input("none");
                    head = addStart(head, n);
                }
                else
                {
                    n = input("none");
                    addBefore(head, n, element);
                }
            }
            else
            {
                printf("\nInvalid input, retry\n");
                dashes();
                continue;
            }
        }

        else if (loop == 3)
        {
            if (numLink(head) == 1)
            {
                printf("\nToo less elments to perform this operation");
                continue;
            }
            int i = input("Press 0 to return, 1 to remove last element, 2 to remove first element, 3 to remove element by number, 4 to remove element by position");

            if (i == 0)
            {
                continue;
            }

            else if (i == 1)
            {
                removeLast(head);
            }

            else if (i == 2)
            {
                head = removeFirst(head);
            }

            else if (i == 3)
            {
                int n = input("Which element do you want to remove?");
                if (!scanCheck(head, n))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                if (head->data == n)
                {
                    head = removeFirst(head);
                }
                else
                {
                    removeNum(head, n);
                }
            }

            else if (i == 4)
            {
                int pos = input("Which position do you want to eliminate?");
                if ((pos > numLink(head)) || (pos < 1))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                if (pos == 1)
                {
                    head = removeFirst(head);
                }
                else
                {
                    removePos(head, pos);
                }
            }

            else
            {
                printf("\nInvalid input, retry");
                dashes();
                continue;
            }
        }

        else if (loop == 4)
        {
            int i = input("Press 0 to return, 1 to replace by number, and 2 to replace by position");

            if (i == 0)
            {
                continue;
            }

            else if (i == 1)
            {
                int data = input("Which number do you want to replace?");
                if (!scanCheck(head, data))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                int n = input("none");
                replaceNum(head, n, data);
            }

            else if (i == 2)
            {
                int pos = input("Which position do you want to replace with?");
                if ((pos > numLink(head)) || (pos < 1))
                {
                    printf("\nInvalid input");
                    dashes();
                    continue;
                }
                int n = input("none");
                replacePos(head, n, pos);
            }

            else
            {
                printf("Invalid input, retry");
                dashes();
                continue;
            }
        }

        else
        {
            printf("\nInvalid input, retry\n");
        }
        dashes();
    }
}