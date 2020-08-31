#include <iostream>
using namespace std;
int main()
{
    int arr[2000];
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    int end_pointer = 3;

    for (int i = 0; i >= 0; ++i)
    {
        int q;
        printf("1 insert an elemnet \n 2 Delete the eleemnet \n 3 search the element \n 4 display \n 5 minimum element \n 6 maximum element \n 7 exit teh program \n");
        scanf("%d", &q);
        if (q == 1)
        {
            int element;
            printf("ente element \n");
            scanf("%d", &element);
            if (end_pointer == 2000)
            {
                printf("size overflow \n");
            }
            else
            {
                int i;
                for (i = 0; i < (end_pointer && arr[i] <= element); ++i)

                    for (int j = end_pointer; j > i; j--)
                    {
                        arr[j] = arr[j - 1];
                    }
                arr[i] = element;
                end_pointer++;
            }
        }
        else if (q == 2)
        {
            int element;
            printf("ente element \n");
            scanf("%d", &element);
            if (end_pointer == 0)
            {
                printf("empty cannot delete \n");
            }
            else
            {
                int i = 0;
                while (i < end_pointer && arr[i] != element)
                    i++;
                while (i < end_pointer - 1)
                {
                    arr[i] = arr[i + 1];
                    i++;
                }
                end_pointer--;
                printf("deleted");
            }
        }
        else if (q == 3)
        {
            int element;
            printf("ente element \n");
            scanf("%d", &element);
            int s = 0;
            int e = end_pointer - 1;
            int mid = -1;
            while (s <= e)
            {
                mid = (s + e) / 2;
                if (arr[mid] == element)
                {
                    break;
                }
                else if (arr[mid] > element)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            printf(" %d", mid + 1);
            printf("\n");
        }
        else if (q == 4)
        {
            printf("the list is");
            for (int i = 0; i < end_pointer; ++i)
            {
                printf(" %d", arr[i]);
                printf(" ");
            }
            printf("\n");
        }
        else if (q == 5)
        {
            printf("%d", arr[0]);
            printf("\n");
        }
        else if (q == 6)
        {
            printf("%d ", arr[end_pointer - 1]);
            printf("\n");
        }
        else
            break;
    }
}