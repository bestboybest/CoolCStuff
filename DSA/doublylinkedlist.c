#include <stdio.h>
#include <stdlib.h>

// Problem statement: Create two double linked lists based on user input of same size and perform operations on both them like:
// 1) Adding the lists, 2) multiplying them, 3) reversing lists, 4) sorting lists, 5)Adding a fixed constant etc...

struct node
{
    int data;
    struct node *next;
    struct node *back;
};

void printList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int input(char inp[])
{
    printf("\n%s\n", inp);
    int n;
    scanf("%d", &n);
    return n;
}

void dashes()
{
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------");
}

void printInterface()
{
    printf("\n\nEnter just 0 to exit otherwise enter a 2/3/4 digit number with each digit corresponding to these operations:");
    dashes();
    printf("\nDigit 1:\n");
    printf("Enter 1 if you want to use only one of the linked lists, and 2 if u want to do a combined operation on both linked lists.");
    dashes();
    printf("\nDigit 2:\n");
    printf("If you are doing operation with one of the linked lists, enter 1 to do with first linked list and 2 to do with second\n");
    printf("If you are doing a combined operation, enter 1 to view both lists (no 3rd digit req), 2 to add both lists, 3 to subtract like list1-list2, 4 to do list2-list1, 5 to multiply the lists");
    dashes();
    printf("\nDigit 3:\n");
    printf("Enter 1 to print output as it is, 2 to add a constant to final output, 3 to subtract a constant, 4 to multiply a scalar, 5 to reverse the output, 6 to sort it in ascending order, 7 for descending order");
    dashes();
    printf("\nDigit 4:\n");
    printf("Enter 1 to print output as it is, 2 to reverse it, 3 to sort in ascending order, 4 to sort in desecending order\n\n");
}

void addEnd(struct node *head, int data)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->back = ptr;
    ptr->next = new;
    new->next = NULL;
}
struct node *addBefore(struct node *head, int data, int n)
{
    struct node *ptr = head;
    while (ptr->data != n)
    {
        ptr = ptr->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr;
    new->back = ptr->back;
    if (head->data != n)
    {
        ptr->back->next = new;
    }
    ptr->back = new;

    if (head->data == n)
    {
        return head->back;
    }
    else
    {
        return head;
    }
}

struct node *copyList(struct node *head)
{
    struct node *start = malloc(sizeof(struct node));
    start->back = NULL;
    start->next = NULL;
    start->data = head->data;

    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        addEnd(start, ptr->data);
    }

    return start;
}

struct node *addLists(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    // Initializing head node
    struct node *head = malloc(sizeof(struct node));
    head->back = NULL;
    head->data = head1->data + head2->data;
    head->next = NULL;

    // Adding all other elements
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        addEnd(head, ptr1->data + ptr2->data);
    }
    return head;
}

struct node *subtractLists(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    // Initializing head node
    struct node *head = malloc(sizeof(struct node));
    head->back = NULL;
    head->data = head1->data - head2->data;
    head->next = NULL;

    // Adding all other elements
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        addEnd(head, ptr1->data - ptr2->data);
    }
    return head;
}

struct node *multiplyLists(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    // Initializing head node
    struct node *head = malloc(sizeof(struct node));
    head->back = NULL;
    head->data = head1->data * head2->data;
    head->next = NULL;

    // Adding all other elements
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        addEnd(head, ptr1->data * ptr2->data);
    }
    return head;
}

struct node *addConst(struct node *head, int n)
{
    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr->data += n;
        ptr = ptr->next;
    }
    ptr->data += n;

    return head;
}

struct node *multConst(struct node *head, int n)
{
    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr->data *= n;
        ptr = ptr->next;
    }
    ptr->data *= n;

    return head;
}

struct node *reverse(struct node *head)
{
    struct node *ptr = head;
    int n = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        n++;
    }

    struct node *last = ptr;

    struct node *reversed = malloc(sizeof(struct node));
    reversed->data = last->data;
    reversed->next = NULL;
    reversed->back = NULL;

    while (last->back != NULL)
    {
        last = last->back;
        addEnd(reversed, last->data);
    }

    return reversed;
}

// inspired by insertion sort (my own goated alorithm)
struct node *sort(struct node *head, int ascending)
{
    // First element
    struct node *sorted = malloc(sizeof(struct node));
    sorted->back = NULL;
    sorted->next = NULL;
    sorted->data = head->data;

    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        struct node *ptrs = sorted;
        int i = 0;

        while (ptrs != NULL)
        {
            if (ptrs->data >= ptr->data)
            {
                sorted = addBefore(sorted, ptr->data, ptrs->data);
                i = 1;
                break;
            }
            ptrs = ptrs->next;
        }
        if (i != 1)
        {
            addEnd(sorted, ptr->data);
        }
    }

    if (ascending == 0)
    {
        sorted = reverse(sorted);
    }

    return sorted;
}

struct node *listInit(int n)
{
    int first, last;
    // Initialize first element
    struct node *head = malloc(sizeof(struct node));
    scanf("%d", &first);
    head->data = first;
    head->back = NULL;
    head->next = NULL;

    struct node *ptr = head;

    // Middle elements and last
    for (int i = 0; i < n - 1; i++)
    {
        int n;
        struct node *new = malloc(sizeof(struct node));
        scanf("%d", &n);
        ptr->next = new;

        new->data = n;
        new->back = ptr;
        new->next = NULL;

        ptr = ptr->next;
    }

    return head;
}

void printFinal(struct node *head)
{
    printf("\nHere is your desired list:\n\n");
    printList(head);
}

void freeAll(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        struct node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main()
{
    int n = input("How many elements do you want in the linked lists (will be fixed)?");
    if (n < 1)
    {
        printf("How tf did u mess up already\n");
        return 1;
    }

    // Initializing the two linked lists
    printf("\nEnter elements of the first linked list:\n");
    struct node *head1 = listInit(n);
    printf("\nEnter elements of the second linked list\n");
    struct node *head2 = listInit(n);

    printf("\nHere is your first initialized linked list:\n");
    printList(head1);
    printf("\n\nHere is your second initialized linked list:\n");
    printList(head2);

    while (1)
    {
        struct node *work;
        printInterface();
        int loop = input("Enter input:");

        if (loop == 0)
        {
            freeAll(head1);
            freeAll(head2);
            return 0;
        }

        int dig4, loop1, loop2, loop3, loop4;
        dig4 = 0;
        if (loop / 100 == 0)
        {
            if (loop == 21)
            {
                printf("\nList1:\n");
                printList(head1);
                printf("\n\nList2:\n");
                printList(head2);
                continue;
            }
        }
        else if (loop / 1000 == 0)
        {
            loop1 = loop / 100;
            loop2 = (loop / 10) % 10;
            loop3 = loop % 10;
        }
        else if (loop / 10000 == 0)
        {
            dig4 = 1;
            loop1 = loop / 1000;
            loop2 = (loop / 100) % 10;
            loop3 = (loop / 10) % 10;
            loop4 = loop % 10;
        }

        // Checking first 2 digits to get working list
        if (loop1 == 1)
        {
            if (loop2 == 1)
            {
                work = copyList(head1);
            }
            else if (loop2 == 2)
            {
                work = copyList(head2);
            }
            else
            {
                printf("\nInvalid input, retry:");
                continue;
            }
        }

        else if (loop1 == 2)
        {
            if (loop2 == 2)
            {
                struct node *temp = addLists(head1, head2);
                work = copyList(temp);
                freeAll(temp);
            }
            else if (loop2 == 3)
            {
                struct node *temp = subtractLists(head1, head2);
                work = copyList(temp);
                freeAll(temp);
            }
            else if (loop2 == 4)
            {
                struct node *temp = subtractLists(head2, head1);
                work = copyList(temp);
                freeAll(temp);
            }
            else if (loop2 == 5)
            {
                struct node *temp = multiplyLists(head1, head2);
                work = copyList(temp);
                freeAll(temp);
            }
            else
            {
                printf("\nInvalid input, retry:");
                continue;
            }
        }

        else
        {
            printf("\nInvalid input, retry:");
            continue;
        }

        // Checking last digit to perform operation on list
        if (loop3 == 1)
        {
            printFinal(work);
            freeAll(work);
            continue;
        }
        else if (loop3 == 2)
        {
            int c = input("What constant do you want to add?");
            work = addConst(work, c);
        }
        else if (loop3 == 3)
        {
            int c = input("What constant would you like to subtract?");
            work = addConst(work, -c);
        }
        else if (loop3 == 4)
        {
            int c = input("What constant would you like to multiply by?");
            work = multConst(work, c);
        }
        else if (loop3 == 5)
        {
            printFinal(reverse(work));
            freeAll(work);
            continue;
        }
        else if (loop3 == 6)
        {
            printFinal(sort(work, 1));
            freeAll(work);
            continue;
        }
        else if (loop3 == 7)
        {
            printFinal(sort(work, 0));
            freeAll(work);
            continue;
        }
        else
        {
            printf("\nInvalid input, retry:");
            continue;
        }

        if (dig4 == 1)
        {
            if (loop4 == 1)
            {
                printFinal(work);
            }
            else if (loop4 == 2)
            {
                printFinal(reverse(work));
            }
            else if (loop4 == 3)
            {
                printFinal(sort(work, 1));
            }
            else if (loop4 == 4)
            {
                printFinal(sort(work, 0));
            }
            else
            {
                printf("\nInvalid input, retry");
                continue;
            }
        }
        else
        {
            printFinal(work);
        }
        freeAll(work);
    }
}