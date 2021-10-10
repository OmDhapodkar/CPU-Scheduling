#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort_burst(int n, int *bt, int *process, int *at)
{
    int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
            {
                swap(&bt[j], &bt[pos]);
                swap(&process[j], &process[pos]);
                swap(&at[j], &at[pos]);
            }
        }
    }
}

int first_process(int n, int *bt, int *process, int *at)
{
    int idx;
    for (int i = 0; i < n; i++)
    {
        idx = i;
        if (at[i] == 0)
        {
            for (int j = idx; j > 0; j--)
            {
                swap(&at[j], &at[j - 1]);
                swap(&bt[j], &bt[j - 1]);
                swap(&process[j], &process[j - 1]);
            }
        }
    }
}

int check_bt(int n, int *bt, int *process, int *at)
{
    for (int i = 0; i < n; i++)
    {
        if (bt[i] == bt[i + 1])
        {
            if (at[i] > at[i + 1])
            {
                swap(&at[i], &at[i + 1]);
                swap(&bt[i], &bt[i + 1]);
                swap(&process[i], &process[i + 1]);
            }
        }
    }
}

int calc_time(int n, int tt[], int bt_2[], int at[], int bt[], int wt[], int p[])
{
    bt_2[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        bt_2[i] = bt_2[i - 1] + bt[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        tt[i] = bt_2[i] - at[i];
    }

    int sum2 = 0;
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = tt[i] - bt[i];
    }   

    printf("Process \t Burst_Time \t Arrival_Time \t Turnaround_Time \t Waiting_Time");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d \t\t  %d \t\t %d \t\t %d \t\t\t %d", p[i], bt[i], at[i], tt[i], wt[i]);
        sum = sum + tt[i];
        sum2 = sum2 + wt[i];
    }
    float average = sum / ((1.0) * n);
    float average2 = sum2 / ((1.0) * n);

    printf("\n\nAverage Turnaround Time is : %.2f", average);
    printf("\n\nAverage Waiting Time is : %.2f", average2);
}

int main()
{
    int n;

    printf("Enter the Number of processes :- ");
    scanf("%d", &n);

    int *burst_time = (int *)malloc(n * sizeof(int));
    int *arrival_time = (int *)malloc(n * sizeof(int));
    int *process = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
    }

    printf("\nEnter the Burst Time for Each Process :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst time for Process P%d is :- ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("\nEnter the Arrival Time for Each Process :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Arrival time for Process P%d is :- ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    int *bt_2 = (int *)malloc(n * sizeof(int));
    int *waiting_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    printf("\n");

    sort_burst(n, burst_time, process, arrival_time);

    first_process(n, burst_time, process, arrival_time);

    check_bt(n, burst_time, process, arrival_time);

    calc_time(n, turnaround_time, bt_2, arrival_time, burst_time, waiting_time, process);

    return 0;
}
