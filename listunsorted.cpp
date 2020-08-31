#include <iostream>
using namespace std;
int main()
{

    int arr[2000];
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 3;
    int end_pointer = 3;
    int q;
    for (int i = 0; i >= 0; ++i)
    {
        printf("1 insert an elemnet \n 2 Delete the eleemnet \n 3 search the element \n 4 display \n 5 minimum element \n 6 maximum element \n 7 exit teh program  \n ente choice");
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
                arr[end_pointer] = element;
                end_pointer++;
            }
            //the element inserted in the array
        }
        else if (q == 2)
        {
            printf("ente element \n");
            int element;
            scanf("%d", &element);
            if (end_pointer == 0)
            {
                printf("empty cannot delete \n");
            }
            else
            {
                int c = 0;
                for (; (c < end_pointer && arr[c] != element);)
                    c++;
                for (; (c < end_pointer - 1); ++c)
                {
                    arr[c] = arr[c + 1];
                }
                end_pointer--;
            }
        }
        else if (q == 3)
        {
            int element;
            printf("ente element \n");
            scanf("%d", &element);
            i = 0;
            while (i < end_pointer && arr[i] != element)
                i++;
            printf("%d \n", i);
        }
        else if (q == 4)
        {
            printf(" the list is");
            for (int i = 0; i < end_pointer; ++i)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (q == 5)
        {
            int mini = arr[0];
            for (int i = 1; i < end_pointer; ++i)
            {
                mini = min(mini, arr[i]);
            }
            printf("%d \n", mini);
        }
        else if (q == 6)
        {
            int maxi = arr[0];
            for (int i = 1; i < end_pointer; ++i)
            {
                maxi = max(maxi, arr[i]);
            }
            printf("%d \n", maxi);
        }
        else
            break;
    }
}
