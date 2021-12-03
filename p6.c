#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
struct node
{
    int data;
    int degree;
    struct node *parent;
    struct node *child;
    struct node *sibling;
};
struct node *empty_node()
{
    struct node *np;
    np = NULL;
    return np;
}

struct node *new_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->degree = 0;
    temp->data = data;
    temp->child = NULL;
    temp->parent = NULL;
    temp->sibling = NULL;
    return temp;
}
struct node *HEAP_SORT(struct node *H)
{
    struct node *current;
    struct node *prev;
    struct node *prev_prev;
    struct node *temp;
    temp = H;
    if (temp->sibling != NULL)
    {
        int p = temp->degree;
        temp = temp->sibling;

        int c = 0;

        while (temp != NULL)
        {
            if (p > temp->degree)
            {
                c = 1;
            }
            p = temp->degree;
            temp = temp->sibling;
        }
        if (c == 1)
        {

            current = H->sibling;
            prev = H;
            prev_prev = H;
            while (current != NULL && prev != NULL)
            {

                if (prev->degree > current->degree)
                {
                    if (prev == prev_prev)
                    {
                        prev->sibling = current->sibling;
                        current->sibling = prev;
                        temp = current;
                        current = prev;
                        prev = temp;
                    }
                    else
                    {

                        prev_prev->sibling = current;
                        prev->sibling = current->sibling;
                        current->sibling = prev;
                        temp = current;
                        current = prev;
                        prev = temp;
                        prev_prev = prev_prev->sibling;
                    }
                }
                current = current->sibling;
                prev = prev->sibling;
            }
            c = 1;
        }
    }
    return H;
}
struct node *HEAP_MERGE(struct node *H1, struct node *H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;

    struct node *head;
    struct node *h1It = H1;
    struct node *h2It = H2;
    struct node *tail;

    if (H1->degree <= H2->degree)
    {
        head = H1;
        h1It = H1->sibling;
    }
    else
    {
        head = H2;
        h2It = H2->sibling;
    }
    tail = head;
    while (h1It != NULL && h2It != NULL)
    {
        if (h1It->degree <= h2It->degree)
        {
            tail->sibling = h1It;
            h1It = h1It->sibling;
        }
        else
        {
            tail->sibling = h2It;
            h2It = h2It->sibling;
        }

        tail = tail->sibling;
    }

    tail->sibling = (h1It != NULL) ? h1It : h2It;

    struct node *h = HEAP_SORT(head);
    return h;
}

int link_nodes(struct node *y, struct node *z)
{
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

struct node *HEAP_UNION(struct node *H1, struct node *H2)
{

    struct node *prev_x;
    struct node *next_x;
    struct node *x;
    struct node *H = empty_node();
    H = HEAP_MERGE(H1, H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL)
    {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree))
        {
            prev_x = x;
            x = next_x;
        }
        else
        {
            if (x->data <= next_x->data)
            {
                x->sibling = next_x->sibling;
                link_nodes(next_x, x);
            }
            else
            {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                link_nodes(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}

struct node *generate_tree(struct node *H, int data)
{
    struct node *temp = new_node(data);
    struct node *H1 = empty_node();
    H1 = temp;
    H = HEAP_UNION(H, H1);
    return H;
}
int find_min(struct node *H)
{
    struct node *temp = H;
    if (temp != NULL)
    {
        int min = 9999999;
        while (temp != NULL)
        {
            if (min > temp->data)
            {
                min = temp->data;
            }
            temp = temp->sibling;
        }
        return min;
    }
    return 0;
}
struct node *find_node(struct node *H, int key)
{
    struct node *temp = H;
    struct node *pointer = NULL;
    if (temp->data == key)
    {
        //p = x;
        return temp;
    }
    if (temp->child != NULL && pointer == NULL)
    {
        pointer = find_node(temp->child, key);
    }

    if (temp->sibling != NULL && pointer == NULL)
    {
        pointer = find_node(temp->sibling, key);
    }
    return pointer;
}
int decrease_key(struct node *H, int key, int new_key)
{
    struct node *parent;
    struct node *current;
    int temp;
    current = find_node(H, key);
    if (current == NULL)
    {
        printf("node not found !");
        return 0;
    }
    else if (current->data < new_key)
    {
        printf("new value greater than old one. !");
        return 0;
    }
    else
    {
        current->data = new_key;
        parent = current->parent;
        while (parent != NULL && current->data < parent->data)
        {
            temp = current->data;
            current->data = parent->data;
            parent->data = temp;
            current = parent;
            parent = parent->parent;
        }
        return 1;
    }
}

struct node *delete_node(struct node *H, int key)
{
    if (decrease_key(H, key, -9999999))
    {
        if (H->sibling == NULL && H->degree == 0)
        {
            H = NULL;
        }
        else
        {
            struct node *current = H;
            struct node *precious = current;
            while (current->data != -99999999 && current->sibling != NULL)
            {
                precious = current;
                current = current->sibling;
            }

            if (precious == NULL && current->sibling == NULL)
            {
                H = NULL;
            }
            else if (precious != NULL && current->sibling == NULL)
            {
                precious->sibling = NULL;
            }
            else if (precious == NULL && current->sibling != NULL)
            {
                H = current->sibling;
            }
            else
            {
                precious->sibling = current->sibling;
            }
            if (current->child != NULL)
            {
                struct node *H2 = current->child;
                struct node *temp = H2;
                while (temp != NULL)
                {
                    temp->parent = NULL;
                    temp = temp->sibling;
                }
                H = HEAP_UNION(H, H2);
            }
        }
    }
    return H;
}

void main()
{

    int len1, len2, tmp, choice;
    int old, newk, heap;
    struct node *h1 = NULL;
    struct node *h2 = NULL;
    struct node *temp = NULL;
    printf("\nSelect Operation :");
    printf("\n  1. View Heap");
    printf("\n  2. Insert in Heap 1");
    printf("\n  3. Insert in Heap 2");
    printf("\n  4. Find minimum");
    printf("\n  5. Union");
    printf("\n  6. Decrease Key");
    printf("\n  7. Delete Key");
    printf("\n  8. Delete Key\n");
    scanf(" %d", &choice);

    while (choice < 8 && choice > 0)
    {

        switch (choice)
        {
        case 1:
            printf("\n 1st heap roots : ");
            temp = h1;
            while (temp != NULL)
            {
                printf("\n KEY =  %d ", temp->data);
                printf("DEGREE = %d ", temp->degree);
                printf("NODES = %.0f ", pow(2, temp->degree));
                temp = temp->sibling;
            }
            printf("\n 2st heap roots : ");
            temp = h2;
            while (temp != NULL)
            {
                printf("\n KEY =  %d ", temp->data);
                printf("DEGREE = %d ", temp->degree);
                printf("NODES = %.0f ", pow(2, temp->degree));
                temp = temp->sibling;
            }
            break;
        case 2:
            printf("Enter number of element in 1st Heap :");
            scanf(" %d", &len1);
            for (int i = 1; i <= len1; i++)
            {
                printf("\nenter node %d key = ", i);
                scanf(" %d", &tmp);
                h1 = generate_tree(h1, tmp);
            }
            printf("\n>>>> 1st heap generated!");
            break;
        case 3:
            printf("Enter number of element in 2nd Heap :");
            scanf(" %d", &len2);
            for (int i = 1; i <= len2; i++)
            {
                printf("\nenter node %d key = ", i);
                scanf(" %d", &tmp);
                h2 = generate_tree(h2, tmp);
            }
            printf("\n>>>> 2st heap generated!");
            break;
        case 4:
            printf("\nMinimum in 1st heap = %d ", find_min(h1));
            printf("\nMinimum in 2nd heap= %d ", find_min(h2));
            break;
        case 5:
            h1 = HEAP_UNION(h1, h2);
            printf("\n>>>> Union done! ");
            h2 = NULL;
            break;
        case 6:

            printf("\nEnter node key : ");
            scanf(" %d", &old);
            printf("\nEnter new key : ");
            scanf(" %d", &newk);
            printf("\nSelect Heap [1/2] : ");
            scanf(" %d", &heap);
            switch (heap)
            {
            case 1:
                decrease_key(h1, old, newk);
                break;
            case 2:
                decrease_key(h2, old, newk);
                break;
            }
            printf("Value decreased successfully");
            break;
        case 7:

            printf("\nEnter node key to delete : ");
            scanf(" %d", &old);
            printf("\nSelect Heap [1/2] : ");
            scanf(" %d", &heap);
            switch (heap)
            {
            case 1:
                h1 = delete_node(h1, old);
                break;
            case 2:
                h2 = delete_node(h2, old);
                break;
            }
            printf("\nNode deleted Successfully.");
            break;
        }
        printf("\n\nSelect Operation :");
        printf("\n  1. View Heap");
        printf("\n  2. Insert in Heap 1");
        printf("\n  3. Insert in Heap 2");
        printf("\n  4. Find minimum");
        printf("\n  5. Union");
        printf("\n  6. Decrease Key");
        printf("\n  7. Delete Key");
        printf("\n  8. Exit\n");
        scanf(" %d", &choice);
    }
}
