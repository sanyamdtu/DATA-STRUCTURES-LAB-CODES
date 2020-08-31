#include <iostream>
using namespace std;
int stak[20];
int top;
void push(int n)
{
    if (top == 19)
    {
        printf(" size overflow \n");
    }
    top++;
    stak[top] = n;
}

void pop()
{
    top--;
}

void Print()
{
    for (int i = (top); i >= 0; i--)
        cout << stak[i] << " ";
    cout << endl;
}

int main()
{
    top = -1;
    int q, temp;
    for (int i = 0; i >= 0; ++i)
    {
        printf("0 quit  \n");
        printf("1 Push elements. \n");
        printf("2 Pop elements. \n");
        printf("3 Display elementss  \n enter chice \n");
        cin >> q;
        if (q == 0)
            break;
        else if (q == 1)
        {
            int n;
            scanf("%d", &n);
            printf("enter number \n");
            push(n);
            printf("inserted \n");
        }
        else if (q == 2)
        {

            if (top == -1)
                printf("empty cannot be deleted \n");
            else
            {
                pop();
                printf("deleted \n");
            }
        }
        else
        {
            Print();
        }
    }

    return 0;
}
