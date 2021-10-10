#include <stdio.h>

int main()
{
    int m, n, pos, count = 0, check = 0;
    int allocation[10][10], need[10][10], request[10], maximum[10][10], available[10];
    int finish[100], temp, flag = 1, k, c1 = 0;
    int safe[100];

    printf("\n");

    printf("Enter the Number of Process States :- ");
    scanf("%d", &n);

    printf("\n");

    printf("Enter the Number of Resource type :- ");
    scanf("%d", &m);

    printf("\n");

    printf("Enter the Allocation Matrix Entries :- ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nEnter the Allocation Value for Process P[%d] and Resource R[%d] :- ", i, j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\n");

    printf("Enter the Maximum Matrix Entries :- ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nEnter the Maximum Value for Process P[%d] and Resource R[%d] :- ", i, j + 1);
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("\n");

    printf("Enter the Available matrix entries :- \n");
    for (int i = 0; i < m; i++)
    {
        printf("Enter the Available value for Resource R[%d] :- ", i + 1);
        scanf("%d", &available[i]);
    }

    printf("\n");

    printf("Enter the Request Matrix Details : \n");
    printf("Which Process you want to Request :- ");
    scanf("%d", &pos);

    printf("\n");

    for (int i = 0; i < m; i++)
    {
        printf("Enter the Request value for Resource R[%d] :- ", i + 1);
        scanf("%d", &request[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (request[i] <= need[pos][i])
        {
            count++;
        }
        else
        {
            printf("Process has exceeded its Maximum Claim");
            check = 1;
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (request[i] <= available[i] && count == m)
        {
            available[i] -= request[i];
            allocation[pos][i] += request[i];
            need[pos][i] -= request[i];
        }
    }

    printf("\n");

    printf("Need Matrix after Requesting\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Allocation Matrix after Requesting\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    if (check == 0)
    {
        while (flag)
        {
            flag = 0;
            for (int i = 0; i < n; i++)
            {
                int c = 0;
                for (int j = 0; j < m; j++)
                {
                    if ((finish[i] == 0) && (need[i][j] <= available[j]))
                    {
                        c++;
                        if (c == m)
                        {
                            for (k = 0; k < m; k++)
                            {
                                available[k] += allocation[i][j];
                                finish[i] = 1;
                                flag = 1;
                            }

                            printf("P%d -> ", i);

                            if (finish[i] == 1)
                            {
                                i = n;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            c1++;
        }
        else
        {
            printf("P%d->", i);
        }
    }

    if (c1 == n)
    {
        printf("\n\nThe System is in Safe State");
    }

    else
    {
        printf("\n\nProcess is in Dead Lock");
        printf("\n\nSystem is in Unsafe State");
    }

    return 0;
}