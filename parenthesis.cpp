#include<iostream>
#define size 50
struct stack
{
    char a[size];
    int top;
};
void push(struct stack *s,char ch)
{
    s->a[s->top]=ch;
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
    char ch[50];
    printf("Enter the string : ");
    gets(ch);
    int i=0;
    while(ch[i]!='\0')
    {
        if(ch[i]=='(')
        {
            push(&s,'(');
        }
        else if(ch[i]==')')
        {
            if(s.top==0)
            {
                printf("\nNOT BALANCED");
                return 0;
            }
            else
                pop(&s);
        }
        else{
        	printf("\nWRONG CHARACTER ENTERED.");
        	return 0;
		}
       i++;
    }
    if(s.top==0)
        printf("\nBALANCED");
    else
        printf("\nNOT BALANCED");
}
