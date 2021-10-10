#include <stdio.h>
int main()
{
    int i, n, total = 0, remain, counter = 0, time_quantum;
    int arrival_time[10], burst_time[10], remain_time[10], start_time[10], response_time[10], waiting_time[10], turnaround_time[10];
    float avg_wt = 0, avg_tt = 0;

    printf("\nEnter Total Number of Processes :- ");
    scanf("%d", &n);
    remain = n;

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the Arrival Time of procees P%d :- ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the Burst Time of procees P%d :- ", i + 1);
        scanf("%d", &burst_time[i]);
        remain_time[i] = burst_time[i];
        start_time[i] = 0;
    }

    printf("\nEnter Time Quantum :- ");
    scanf("%d", &time_quantum);

    printf("\nProcess ID \t Burst Time \t  Arrival time \t\t Turnaround Time \t Waiting Time \t Response Time\n");
    for (total = 0, i = 0; remain != 0;)
    {
        if (remain_time[i] <= time_quantum && remain_time[i] > 0)
        {
            if (start_time[i] == 0)
            {
                start_time[i] = total;
            }
            total = total + remain_time[i];
            remain_time[i] = 0;
            counter = 1;
        }

        else if (remain_time[i] > 0)
        {
            remain_time[i] = remain_time[i] - time_quantum;
            total = total + time_quantum;
        }

        if (remain_time[i] == 0 && counter == 1)
        {
            remain--;
            turnaround_time[i] = total - arrival_time[i];
            waiting_time[i] = turnaround_time[i] - burst_time[i];
            response_time[i] = start_time[i] - arrival_time[i];

            printf("\nP[%d] \t\t %d \t\t\t %d \t\t %d \t\t\t %d \t\t %d", i + 1, burst_time[i], arrival_time[i], turnaround_time[i], waiting_time[i], response_time[i]);
            avg_wt += total - arrival_time[i] - burst_time[i];
            avg_tt += total - arrival_time[i];

            counter = 0;
        }

        if (i == n - 1)
        {
            i = 0;
        }

        else if (arrival_time[i + 1] <= total)
        {
            i++;
        }

        else
        {
            i = 0;
        }
    }

    printf("\n\nAverage Waiting Time is :- %.2f", avg_wt * 1.0 / n);
    printf("\nAvg Turnaround Time is :- %.2f\n", avg_tt * 1.0 / n);

    return 0;
}

// #include <stdio.h>

// void swap(int *a, int *b)
// {
//     int remain_time = *a;
//     *a = *b;
//     *b = remain_time;
// }

// int main()
// {

// int n, current_time = 0, start_time[10], end_time, time_quantum;
// int burst_time[10], arrival_time[10], turnaround_time[10], waiting_time[10], remain_time[10], response_time[10], process[10];
// int count = 0;
// float avg_tt = 0, avg_wt = 0;
// int done_process[10];

// printf("Enter the Number of processes :- ");
// scanf("%d", &n);

// printf("\n");

// for (int i = 0; i < n; i++)
// {
//     printf("Enter the Arrival time for process P%d :- ", i + 1);
//     scanf("%d", &arrival_time[i]);
//     done_process[i] = 0;
//     start_time[i] = 0;
// }

// printf("\n");

// for (int i = 0; i < n; i++)
// {
//     printf("Enter the Burst time for process P%d :- ", i + 1);
//     scanf("%d", &burst_time[i]);
//     remain_time[i] = burst_time[i];
//     process[i] = i + 1;
// }

// for (int i = 0; i < n - 1; i++)
// {
//     for (int j = i + 1; j < n; j++)
//     {
//         if (arrival_time[i] > arrival_time[j])
//         {
//             swap(&arrival_time[i], &arrival_time[j]);
//             swap(&burst_time[i], &burst_time[j]);
//             swap(&process[i], &process[j]);
//             swap(&remain_time[i], &remain_time[j]);
//         }
//     }
// }

// printf("\nEnter Time Quantum :- ");
// scanf("%d", &time_quantum);

// printf("\n\nProcess \t Burst Time \t Arrival Time \t Turnaround Time \t Waiting Time\t\t Response Time\n");

// while (count != n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arrival_time[i] <= current_time && done_process[i] == 0 && remain_time[i] >= 0)
//         {
//             if (start_time[i] == 0)
//             {
//                 start_time[i] = current_time;
//             }

//             if (remain_time[i] >=time_quantum)
//             {
//                 current_time += time_quantum;
//                 remain_time[i] -= time_quantum;
//                 // continue;
//             }

//             else
//             {
//                 current_time += remain_time[i];
//                 remain_time[i] = 0;
//                 done_process[i] = 1;
//                 count++;
//                 end_time = current_time + 1;
//                 turnaround_time[i] = end_time - arrival_time[i];
//                 waiting_time[i] = turnaround_time[i] - burst_time[i];
//                 response_time[i] = start_time[i] - arrival_time[i];

//                 avg_tt += turnaround_time[i];
//                 avg_wt += waiting_time[i];

//                 printf("\nP%d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d", process[i], burst_time[i], arrival_time[i], turnaround_time[i], waiting_time[i], response_time[i]);
//             }
//         }
//     }
// }
//////////////////////////////////////////////////////////////////////////////
// int n,total_time,remain,count,time_quantum,remain_time[10],flag,burst_time[10],arrival_time[10];
// float waiting_time,turnaround_time;

// printf("Enter the Number of processes :- ");
// scanf("%d", &n);

// printf("\n");

// for (int i = 0; i < n; i++)
// {
//     printf("Enter the Arrival time for process P%d :- ", i + 1);
//     scanf("%d", &arrival_time[i]);
// }

// printf("\n");

// for (int i = 0; i < n; i++)
// {
//     printf("Enter the Burst time for process P%d :- ", i + 1);
//     scanf("%d", &burst_time[i]);
//     remain_time[i] = burst_time[i];
// }

// printf("\nEnter Time Quantum :- ");
// scanf("%d", &time_quantum);

// for (total_time = 0, count = 0; remain != 0;)
// {
//     if (remain_time[count] <= time_quantum && remain_time[count] > 0)
//     {
//         total_time += remain_time[count];
//         remain_time[count] = 0;
//         flag = 1;
//     }
//     else if (remain_time[count] > 0)
//     {
//         remain_time[count] -= time_quantum;
//         total_time += time_quantum;
//     }
//     if (remain_time[count] == 0 && flag == 1)
//     {
//         remain--;
//         printf("P[%d] \t\t %d \t\t %d \t\t %d \t\t\t %d \t \n", count + 1, burst_time[count], arrival_time[count], total_time - arrival_time[count], total_time - arrival_time[count] - burst_time[count]);
//         waiting_time += total_time - arrival_time[count] - burst_time[count];
//         turnaround_time += total_time - arrival_time[count];
//         flag = 0;
//     }
//     if (count == n - 1)
//         count = 0;
//     else if (arrival_time[count + 1] <= total_time)
//         count++;
//     else
//         count = 0;
// }

// printf("\nAverage Waiting Time :- %.2f\n", waiting_time * 1.0 / n);
// printf("\nAvg Turnaround Time :- %.2f\n", turnaround_time * 1.0 / n);

// return 0;
// }
