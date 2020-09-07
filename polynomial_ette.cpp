#include<iostream>
using namespace std;

struct poly
{
    int coef;
    int exp;
};

void print(struct poly *p, int x)
{
    int i = 0;
    while(i<x)
	{
        if(i==0)
		{
            printf("%dx^%d", p[i].coef, p[i].exp);
        }
		else
		{
            if(p[i].coef>0)
                printf(" + %dx^%d", p[i].coef, p[i].exp);
            else
                printf(" - %dx^%d", -p[i].coef, p[i].exp); 
        }
        i = i+1;
    }
    printf("\n");
}
void add(struct poly *p1, struct poly *p2, int n1, int n2)
{
    struct poly a[n1+n2];
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2)
	{
        if(p1[i].exp == p2[j].exp)
		{
            a[k].exp = p1[i].exp;
            a[k].coef = (p1[i].coef+p2[j].coef);
            i = i+1;
            j = j+1;
        }
		else if(p1[i].exp > p2[j].exp)
		{
            a[k] = p1[i];
            i=i+1;
        }
		else
		{
            a[k] = p2[j];
            j=j+1;
        }
        k=k+1;
    }
    printf("Sum : ");
    print(a,k);
}

void multiply(struct poly * p1, struct poly * p2, int n1, int n2)
{
    struct poly a[n1*n2];
    int i = 0, j = 0, k = 0;
    while(j<n2)
	{
        a[k].coef = p1[i].coef*p2[j].coef;
        a[k].exp = p1[i].exp + p2[j].exp;
        if(i == n1-1)
		{
            i=-1;
            j = j+1;
        }
        i = i+1;
        k =k + 1;
    }
    printf("\nProduct : ");
    print(a,k);
}

int main()
{
    struct poly p1[4], p2[3];
    p1[0].coef=2;
    p1[0].exp=5;
    p1[1].coef=6;
    p1[1].exp=4;
    p1[2].coef=9;
    p1[2].exp=3;
    p1[3].coef=1;
    p1[3].exp=0;
    p2[0].coef = 3;
    p2[0].exp = 7;
    p2[1].coef = 2;
    p2[1].exp = 2;
    p2[2].coef = 5;
    p2[2].exp = 0;
    add(p1, p2, 4, 3);
    multiply(p1, p2, 4, 3);
}
