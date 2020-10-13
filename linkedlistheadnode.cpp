#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
};
struct node *first(struct node *s, int x)
{
    struct node *q;
    q = (struct node *)malloc(100 * sizeof(struct node));
    q->value = x;
    q->next = s;
    s = q;
    return s;
}
struct node *insert_at_end(struct node *s, int x)
{
    struct node *p, *q;
    q = (struct node *)malloc(100 * sizeof(struct node));
    q->value = x;
    q->next = NULL;
    p = s;
    if (s == NULL)
    {
        s = q;
        return s;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    return s;
}
struct node *insert_after(struct node *s, int x, int y)
{
    struct node *p, *q;
    q = (struct node *)malloc(100 * sizeof(struct node));
    q->value = x;
    p = s;
    if (s == NULL)
    {
        q->next = NULL;
        s = q;
        return s;
    }
    while (p->value != y)
    {
        /*if(p->next==NULL){
			break;
		} */
        p = p->next;
    }
    if (p->next == NULL && p->value != y)
    {
        printf("\n %d doesn't exist.", y);
        return s;
    }
    q->next = p->next;
    p->next = q;
    return s;
}
struct node *delete_(struct node *s, int x)
{
    if (s == NULL)
    {
        printf("Linked list is empty.");
        return s;
    }
    struct node *p, *q;
    q = s;
    p = NULL;
    while (q != NULL && q->value != x)
    {
        p = q;
        q = q->next;
    }
    if (q != NULL)
    {
        if (q == s)
        {
            s = s->next;
        }
        else
        {
            p->next = q->next;
            free(q);
        }
    }
    else
    {
        printf("Element not found.");
    }
    return s;
}
void search(struct node *s, int x)
{
    struct node *p = s;
    int flag = 0;
    if (s == NULL)
    {
        printf("Linked list is empty.");
        return;
    }
    while (p != NULL)
    {
        if (p->value == x)
        {
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("Element not found.");
    }
    else
    {
        printf("Element found. ");
    }
}
void display(struct node *s)
{
    struct node *p = s;
    if (p == NULL)
    {
        printf("Linked list is empty.");
        return;
    }
    while (p->next != NULL)
    {
        printf("%d-> ", p->value);
        p = p->next;
    }
    printf("%d", p->value);
}
int count(struct node *s)
{
    struct node *p = s;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
int main()
{
    int x, ch, y;
    struct node *s = NULL;
    while (1)
    {
        printf("\n\n1. Insert at beginning \n2. Insert at end \n3. Insert after \n4. Delete \n5. Search \n6. Count \n7. Display \n8. Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted : ");
            scanf("%d", &x);
            s = first(s, x);
            break;
        case 2:
            printf("Enter the number to be inserted : ");
            scanf("%d", &x);
            s = insert_at_end(s, x);
            break;
        case 3:
            printf("Enter the number after which you want to insert : ");
            scanf("%d", &y);
            printf("Enter the number you want to insert : ");
            scanf("%d", &x);
            s = insert_after(s, x, y);
            break;
        case 4:
            printf("Enter the number to be deleted : ");
            scanf("%d", &x);
            s = delete_(s, x);
            break;
        case 5:
            printf("Enter the number to be searched : ");
            scanf("%d", &x);
            search(s, x);
            break;
        case 6:
            y = count(s);
            printf("The number of elements in linked list are : %d", y);
            break;
        case 7:
            display(s);
            break;
        case 8:
            exit(0);
            break;
        }
    }
    return 0;
}