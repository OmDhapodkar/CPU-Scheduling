#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, pos = 0, current_time, start_time[10], smallest, end_time;
    int burst_time[10], arrival_time[10], turnaround_time[10], waiting_time[10], remain_time[10], response_time[10], process[10];
    int count = 0;
    float avg_tt = 0, avg_wt = 0;
    int done_process[10];

    printf("Enter the Number of processes :- ");
    scanf("%d", &n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Arrival time for process P%d :- ", i + 1);
        scanf("%d", &arrival_time[i]);
        done_process[i] = 0;
        start_time[i] = 0;
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Burst time for process P%d :- ", i + 1);
        scanf("%d", &burst_time[i]);
        remain_time[i] = burst_time[i];
        process[i] = i + 1;
    }

    int inc;

    for (int i = 1; i < n; i++)
    {
        if (arrival_time[i] < arrival_time[pos])
        {
            pos = i;
        }
    }

    if (pos != 0)
    {
        swap(&arrival_time[0], &arrival_time[pos]);
        swap(&burst_time[0], &burst_time[pos]);
        swap(&remain_time[0], &remain_time[pos]);
        swap(&process[0], &process[pos]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        inc = i;
        for (int j = i + 1; j < n; j++)
        {
            if (burst_time[j] < burst_time[inc])
            {
                swap(&arrival_time[j], &arrival_time[inc]);
                swap(&burst_time[j], &burst_time[inc]);
                swap(&remain_time[j], &remain_time[inc]);
                swap(&process[j], &process[inc]);
            }
        }
    }

    printf("\nProcess \t Arrival Time \t\t Burst Time \t\t Turnaround Time \t\t Waiting Time \t\t Response Time\n");

    remain_time[10] = 9999;

    for (current_time = 0; count != n; current_time++)
    {
        smallest = 10;
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= current_time && done_process[i] == 0 && remain_time[i] > 0 && remain_time[i] < remain_time[smallest])
            {
                smallest = i;
                if (start_time[smallest] == 0)
                {
                    start_time[smallest] = current_time;
                }
            }
        }

        remain_time[smallest]--;

        if (remain_time[smallest] == 0 && done_process[smallest] == 0)
        {
            count++;
            done_process[smallest] = 1;
            end_time = current_time + 1;
            turnaround_time[smallest] = end_time - arrival_time[smallest];
            waiting_time[smallest] = turnaround_time[smallest] - burst_time[smallest];
            response_time[smallest] = start_time[smallest] - arrival_time[smallest];

            avg_tt += turnaround_time[smallest];
            avg_wt += waiting_time[smallest];

            printf("\nP%d \t\t %d \t\t\t %d \t\t\t %d \t\t\t\t %d \t\t\t %d", process[smallest], arrival_time[smallest], burst_time[smallest], turnaround_time[smallest], waiting_time[smallest], response_time[smallest]);
        }
    }

    printf("\n");
    printf("\nAverage TurnAround Time is :- %.2f", 1.0 * avg_tt / n);
    printf("\nAverage Waiting Time is :- %.2f", 1.0 * avg_wt / n);

    return 0;
}
