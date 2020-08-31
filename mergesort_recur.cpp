#include <iostream>
using namespace std;
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
void mst(int arr[], int n, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mst(arr, n, s, mid);
    mst(arr, n, mid + 1, e);
    merge(arr, s, mid, e);
}
void mergeSort(int a[], int size)
{
    mst(a, size, 0, size - 1);
}

int main()
{
    int n;
    printf("enter size \n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, n);
    printf("enter numbers \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}