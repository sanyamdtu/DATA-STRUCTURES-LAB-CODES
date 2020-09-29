#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct elem
{
    int row, column, val;
};

struct sparse
{
    int m, n, num;
    struct elem *ele;
};

int arr[2][100][100];

// functions on sparsed matrix
void print(struct sparse *);
struct sparse *transpose(struct sparse);
void create(struct sparse *, int, int, int, int);
struct sparse *add(struct sparse *, struct sparse *);
struct sparse *multiply(struct sparse *, struct sparse *);

//-----Main Function------/
int main(int argc, char *argv[])
{
    int counter;
    printf("\nProgram Name Is: %s", argv[0]);
    if (argc == 1)
        printf("\nNo Command Line Argument Passed \n");
    if (argc >= 2)
    {
        for (counter = 1; counter < argc; counter++)
            printf("\nargv[%d]: %s \n", counter, argv[counter]);
        FILE *f;
        f = fopen(argv[1], "r+"); // file opened
        char ch[80];
        int i = 0, j = 0, k = 0;
        if (f != NULL)
        {
            while (fgets(ch, 80, f) != NULL)
            {
                if (ch[0] != '\n')
                {
                    j = 0;

                    char delim[] = " ";

                    char *p = strtok(ch, delim); // splitting each line on the basis of spaces

                    while (p != NULL)
                    {
                        sscanf(p, "%d", &arr[k][i][j]); // converting string into decimal number
                        j++;
                        p = strtok(NULL, delim);
                    }
                    i++;
                }
                else
                {
                    k += 1;
                    i = 0;
                    j = 0;
                }
            }
            fclose(f); // file closed
        }
        else
        {
            printf("...Can't Open file...");
        }
        int count1 = 0, count2 = 0;
        for (int m = 0; m < i; m++) // counting number of non-zero elems in each array
        {
            for (int n = 0; n < j; n++)
            {
                if (arr[0][m][n] != 0)
                {
                    count1++;
                }
                if (arr[1][m][n] != 0)
                {
                    count2++;
                }
            }
        }
        struct sparse c1, c2, *c3, *c4, *c5;
        create(&c1, i, j, count1, 0);
        create(&c2, i, j, count2, 1);
        printf("-----MATRIX 1-----");
        print(&c1);
        printf("-----MATRIX 2-----");
        print(&c2);
        c3 = add(&c1, &c2);
        print(c3);
        printf("-----TRANSPOSE-----");
        c4 = transpose(c1);
        print(c4);
        c5 = multiply(&c1, &c2);
        if (c5 != NULL)
            print(c5);
    }

    return 0;
}

//------Function Definitions------/

void print(struct sparse *s) // printing of sparsed matrix
{
    printf("\nSparse Matrix: \nRow\tColumn\tValue\n");
    
    for (int i = 0; i < s->num; i++)
    {
        if (s->ele[i].val == INT_MIN)
            continue;
        printf("%d\t%d\t%d\n", s->ele[i].row, s->ele[i].column, s->ele[i].val);
    }
    printf("\n");
    
}

void create(struct sparse *s, int i, int j, int count, int z) //creating sparsed matrix
{
    s->m = i;
    s->n = j;
    s->num = count;
    int p = 0;
    s->ele = (struct elem *)malloc((s->num) * sizeof(struct elem));
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            if (arr[z][m][n] != 0)
            {
                s->ele[p].row = m;
                s->ele[p].column = n;
                s->ele[p].val = arr[z][m][n];
                p++;
            }
        }
    }
}

struct sparse *add(struct sparse *c1, struct sparse *c2) // adding 2 sparsed matrix
{
    printf("-----ADDITION-----");
    struct sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if (c1->n != c2->n && c1->m != c2->m)
        return NULL;
    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->ele = (struct elem *)malloc((c1->num + c2->num) * sizeof(struct elem));
    while (i < c1->num && j < c2->num)
    {
        if (c1->ele[i].row < c2->ele[j].row)
            sum->ele[k++] = c1->ele[i++];
        else if (c1->ele[i].row > c2->ele[j].row)
            sum->ele[k++] = c2->ele[j++];
        else
        {
            if (c1->ele[i].column < c2->ele[j].column)
                sum->ele[k++] = c1->ele[i++];
            else if (c1->ele[i].column > c2->ele[j].column)
                sum->ele[k++] = c2->ele[j++];
            else
            {
                sum->ele[k] = c1->ele[i];
                sum->ele[k++].val = c1->ele[i++].val + c2->ele[j++].val;
            }
        }
    }
    for (; i < c1->num; i++)
        sum->ele[k++] = c1->ele[i];
    for (; j < c2->num; j++)
        sum->ele[k++] = c2->ele[j];
    sum->m = c1->m;
    sum->n = c1->n;
    sum->num = k;

    return sum;
}

struct sparse *transpose(struct sparse c1) //transposing sparsed  matrix
{
    
    int flag = 0;
    struct sparse *s = (struct sparse *)malloc(sizeof(struct sparse));
    s->ele = (struct elem *)malloc(c1.num * sizeof(struct elem));
    s->num = c1.num;
    s->m = c1.n;
    s->n = c1.m;
    for (int i = 0; i < c1.num; i++)
    {
        for (int j = 0; j < (c1.num) - i - 1; j++)
        {
            if (c1.ele[j].column > c1.ele[j + 1].column)
            {
                struct elem temp = c1.ele[j];
                c1.ele[j] = c1.ele[j + 1];
                c1.ele[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    for (int i = 0; i < c1.num; i++)
    {
        s->ele[i].row = c1.ele[i].column;
        s->ele[i].column = c1.ele[i].row;
        s->ele[i].val = c1.ele[i].val;
    }
    return s;
}

struct sparse *multiply(struct sparse *c1, struct sparse *c4) // multiply two sparsed  matrix
{
    printf("-----MULTIPLICATION-----");
    struct sparse *s = (struct sparse *)malloc(sizeof(struct sparse));
    s->ele = (struct elem *)malloc((c1->m * c4->n) * sizeof(struct elem));
    s->m = c1->m;
    s->n = c4->n;
    struct sparse *c2 = transpose(*c4);
    if (c1->n != c4->m)
    {
        printf("\n...Can't Multiply Matrices...\n");
        return NULL;
    }
    else
    {
        int k = 0;
        int count = 0, flag = 0;
        for (int i = 0; i < c1->num; i++)
        {
            for (int j = 0; j < c2->num; j++)
            {
                if (c1->ele[i].column == c2->ele[j].column)
                {
                    s->ele[k].row = c1->ele[i].row;
                    s->ele[k].column = c2->ele[j].row;
                    s->ele[k++].val = c1->ele[i].val * c2->ele[j].val;
                    count++;
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (s->ele[j].row == s->ele[i].row)
                {
                    if (s->ele[j].column == s->ele[i].column)
                    {
                        s->ele[i].val += s->ele[j].val;
                        s->ele[j].val = INT_MIN;
                    }
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (s->ele[j].row > s->ele[j + 1].row)
                {
                    struct elem temp = s->ele[j];
                    s->ele[j] = s->ele[j + 1];
                    s->ele[j + 1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
        s->num = count;
    }
    return s;
}