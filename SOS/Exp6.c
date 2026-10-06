#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10], finish[10];
    int safe[10], count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;

        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if (possible)
                {
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    printf("\nNeed Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    if (count == n)
    {
        printf("\nSystem is in a SAFE state.\n");
        printf("Safe Sequence: ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", safe[i]);

            if (i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is in an UNSAFE state.\n");
        printf("No safe sequence exists.\n");
    }

    return 0;
}
