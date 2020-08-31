#include<stdio.h>
#define sz 100
struct stack
{
    char c[sz];
    int top;
};
void push(struct stack *s,char ch)
{
    s->c[s->top]=ch;
    s->top=s->top+1;
}
void pop(struct stack *s)
{
    s->top=s->top-1;
}
int main()
{
    struct stack s;
    s.top=0;
    char ch;
    scanf("%c",&ch);
    while(ch!='\n')
    {
        if(ch=='(')
        {
            push(&s,'(');
        }
        else
        {
            if(s.top==0)
            {
                printf("NO");
                return 0;
            }
            else
                pop(&s);
        }
        scanf("%c",&ch);
    }
    if(s.top==0)
        printf("YES");
    else
        printf("NO");
}