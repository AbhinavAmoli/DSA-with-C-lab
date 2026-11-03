
#include <stdio.h>

// Heapify function
void heapify(int a[], int n, int i)
{
    int largest, left, right, temp;

    largest = i;

    left = 2*i + 1;
    right = 2*i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

// Build Max Heap
void buildHeap(int a[], int n)
{
    int i;

    for(i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

// Find Kth largest element
int kthLargest(int a[], int n, int k)
{
    int i, temp;

    // Build Max Heap
    buildHeap(a, n);

    // Delete maximum k-1 times
    for(i = 1; i < k; i++)
    {
        temp = a[0];

        a[0] = a[n-1];
        a[n-1] = temp;

        n--;

        heapify(a, n, 0);
    }

    // Root contains Kth largest
    return a[0];
}

int main()
{
    int a[1000];
    int n, k, i, ans;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    if(k < 1 || k > n)
    {
        printf("Invalid K");
        return 0;
    }

    ans = kthLargest(a, n, k);

    printf("K = %d, largest element : %d", k, ans);

    return 0;
}
