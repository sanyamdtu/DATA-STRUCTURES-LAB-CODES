#include <iostream>
using namespace std;
int b[100];
void merge(int a[], int s, int m, int e)
{
    int t[e - s + 1], c = 0, mid_t = m + 1, start = s;
    while (s <= m && e >= mid_t)
    {
        if (a[s] > a[mid_t])
        {
            t[c] = a[mid_t];
            mid_t++;
            c++;
        }
        else
        {
            t[c] = a[s];
            s++;
            c++;
        }
    }
    if (s <= m)
    {
        while (s <= m)
        {
            t[c] = a[s];
            s++;
            c++;
        }
    }
    else
    {
        while (e >= mid_t)
        {
            t[c] = a[mid_t];
            mid_t++;
            c++;
        }
    }
    for (int i = 0; i < e - start + 1; i++)
    {
        a[start + i] = t[i];
    }
}
void mergesort(int *a, int n)
{
    int k = 1, i, mid, e;
    while (k < n)
    {
        i = 0;
        while (i < n - 1)
        {
            mid = min(n - 1, i + k - 1);
            e = min(n - 1, i + k + k - 1);
            merge(a, i, mid, e);
            i = e + 1;
        }
        k *= 2;
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("enter size \n");
    scanf("%d", &n);
    int arr[n];
    printf("enter numbesr \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
