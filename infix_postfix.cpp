#include <stdio.h>
#define sz 100
struct stack
{
    char a[sz];
    int top;
};
void push(struct stack *s, char ch)
{
    s->top = s->top + 1;
    s->a[s->top] = ch;
}
void pop(struct stack *s)
{
    s->top = s->top - 1;
}

int f(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
int main()
{
    struct stack s;
    s.top = -1;
    char c[] = "a+b*(c/d-e)+(f+g*h)-i";
    int i = 0;
    int n = sizeof(c) / sizeof(char);
    i = 0;
    char out[sz];
    int j = 0;
    while (i < n)
    {
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            out[j++] = c[i];
        }
        else if (c[i] == ')')
        {
            while (s.a[s.top] != '(')
            {
                out[j++] = s.a[s.top];
                pop(&s);
            }
            pop(&s);
        }
        else if (c[i] == '(')
        {
            push(&s, '(');
        }
        else
        {
            while (s.top > -1 && (f(s.a[s.top]) >= f(c[i])))
            {
                out[j++] = s.a[s.top];
                pop(&s);
            }
            push(&s, c[i]);
        }
        i++;
    }
    while (s.top != -1)
    {
        if (s.a[s.top] != '(')
            out[j++] = s.a[s.top];
        pop(&s);
    }
    i = 0;
    while (i < j)
    {
        printf("%c ", out[i]);
        i++;
    }
}