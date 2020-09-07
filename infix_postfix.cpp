#include <stdio.h>
#define sz 30
struct stack
{
    int a[sz];
    int top;
};
void push(struct stack *s, int d)
{
    if (s->top == sz - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    s->top++;
    s->a[s->top] = d;
    return;
}
int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    int x = s->a[s->top];
    s->top--;
    return x;
}
void show(struct stack s)
{
    while (s.top > -1)
    {
        printf("%d ", s.a[s.top]);
        s.top--;
    }
    printf("\n");
}
int main()
{
    struct stack s;
    s.top = -1;
    int c, d;
    while (1)
    {
        printf("1.push\n2.pop\n3display\n4exit\n");
        scanf("%d", &c);
        if (c == 1)
        {
            scanf("%d", &d);
            push(&s, d);
        }
        else if (c == 2)
        {
            printf("deleted number is :%d\n", pop(&s));
        }
        else if (c == 3)
        {
            show(s);
        }
        else
            break;
    }
}