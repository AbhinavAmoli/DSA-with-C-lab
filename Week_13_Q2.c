
#include <stdio.h>

int checkHeap(int a[], int n)
{
    int i, left, right;
    int nullFound = 0;

    // Check Complete Binary Tree
    for(i = 0; i < n; i++)
    {
        if(a[i] == -1)
            nullFound = 1;

        else if(nullFound == 1)
            return 0;
    }

    // Check Max Heap property
    for(i = 0; i < n; i++)
    {
        if(a[i] == -1)
            continue;

        left = 2*i + 1;
        right = 2*i + 2;

        if(left < n && a[left] != -1)
        {
            if(a[i] < a[left])
                return 0;
        }

        if(right < n && a[right] != -1)
        {
            if(a[i] < a[right])
                return 0;
        }
    }

    return 1;
}

int main()
{
    int t, n, i;
    int a[1000];

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        if(checkHeap(a, n))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
