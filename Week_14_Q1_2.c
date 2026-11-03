
#include <stdio.h>

int main()
{
    int a[100][100];
    int n, i, j;
    int u, v;
    int found = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter friendship matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter two roll numbers: ");
    scanf("%d%d", &u, &v);

    if(u < 1 || u > n || v < 1 || v > n || u == v)
    {
        printf("Invalid roll numbers");
        return 0;
    }

    // Check friendship
    if(a[u][v] == 1)
        printf("They are friends\n");
    else
        printf("They are not friends\n");

    // Find mutual friends
    printf("Mutual friends: ");

    for(i = 1; i <= n; i++)
    {
        if(i != u && i != v &&
           a[u][i] == 1 && a[v][i] == 1)
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if(found == 0)
        printf("None");

    printf("\n");

    // Find students who are friends with neither
    printf("Students not friends with either: ");

    found = 0;

    for(i = 1; i <= n; i++)
    {
        if(i != u && i != v &&
           a[u][i] == 0 && a[v][i] == 0)
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if(found == 0)
        printf("None");

    return 0;
}
