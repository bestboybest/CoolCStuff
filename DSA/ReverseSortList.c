#include <stdio.h>
#include <stdlib.h>

// Problem statement: to reverse and sort singly linked lists

struct node
{
    int data;
    struct node *link;
};

void addEnd(struct node *head, int data)
{
    struct node *ptr = head;

    struct node *new = malloc(sizeof(struct node));
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    new->data = data;
    ptr->link = new;
    new->link = NULL;
}

struct node *addStart(struct node *head, int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->link = head;
    new->data = data;

    return new;
}

void addPos(struct node *head, int data, int pos)
{
    struct node *ptr = head;

    struct node *new = malloc(sizeof(struct node));
    for (int i = 0; i < pos - 2; i++)
    {
        ptr = ptr->link;
    }
    new->data = data;
    new->link = ptr->link;
    ptr->link = new;
}

struct node *listInit(int n)
{
    struct node *head = malloc(sizeof(struct node));
    int a;
    scanf("%d", &a);
    head->data = a;
    head->link = NULL;

    struct node *ptr = head;
    for (int i = 0; i < n - 1; i++)
    {
        int i;
        scanf("%d", &i);
        addEnd(head, i);
    }

    return head;
}

void printList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

struct node *reverse(struct node *head)
{
    struct node *ptr, *prev, *next;

    prev = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;

        prev = ptr;
        ptr = next;
    }

    return prev;
}

struct node *sort(struct node *head, int ascending)
{

    struct node *ptr = head;

    struct node *sorted = malloc(sizeof(struct node));
    sorted->data = head->data;
    sorted->link = NULL;

    ptr = ptr->link;

    while (ptr != NULL)
    {
        struct node *ptrs = sorted;
        int i = 0;
        int pos = 1;

        while (ptrs != NULL)
        {
            if (ptrs->data > ptr->data)
            {
                i = 1;
                break;
            }
            ptrs = ptrs->link;
            pos++;
        }

        if (i == 0)
        {
            addEnd(sorted, ptr->data);
        }
        else
        {
            if (pos != 1)
            {
                addPos(sorted, ptr->data, pos);
            }
            else
            {
                sorted = addStart(sorted, ptr->data);
            }
        }

        ptr = ptr->link;
    }

    if (ascending == 0)
    {
        return reverse(sorted);
    }
    else
    {
        return sorted;
    }
}

void freeAll(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        struct node *temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
}

int main()
{
    int n;
    printf("\nHow many elements do you want in the linked list?\n");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Wrong bruh");
        return 1;
    }

    printf("\nEnter the elements: \n");
    struct node *head = listInit(n);

    printf("\nYour list is initialized as follows: \n");
    printList(head);

    while (1)
    {
        int func;
        printf("\n\nPress 0 to quit, 1 to reverse the list, 2 to sort in ascending order and 3 to sort in descending order:\n");
        scanf("%d", &func);

        if (func == 0)
        {
            break;
        }
        if (func == 1)
        {
            printList(reverse(head));
            printf("\n\n---------------------------------------------------------------------------------------------------------------");
            continue;
        }
        else if (func == 2)
        {
            printList(sort(head, 1));
            printf("\n\n---------------------------------------------------------------------------------------------------------------");
            continue;
        }
        else if (func == 3)
        {
            printList(sort(head, 0));
            printf("\n\n---------------------------------------------------------------------------------------------------------------");
            continue;
        }
        else
        {
            printf("Wrong input BRUHHHH");
            continue;
        }
    }
    freeAll(head);
    return 0;
}