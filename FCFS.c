#include <stdio.h>
#include <stdlib.h>

int calc_waiting_time(int n, int wt[], int bt_2[], int at[],int bt[])
{
    wt[0] = 0;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt_2[i - 1] - at[i];
    }

    printf("Process \t Burst_Time \t Arrival_Time \t Waiting_Time");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d \t\t  %d \t\t %d \t\t %d",i+1,bt[i],at[i],wt[i]);
        sum = sum + wt[i];
    }

    float average = sum / ((1.0)*n);
    printf("\nAverage Waiting Time is : %.2f", average);
}

int calc_turnaround_time(int n, int tt[], int bt_2[], int at[],int bt[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        tt[i] = bt_2[i] - at[i];
    }

    printf("Process \t Burst_Time \t Arrival_Time \t Turnaround_Time");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d \t\t  %d \t\t %d \t\t %d",i+1,bt[i],at[i],tt[i]);
        sum = sum + tt[i];
    }
    float average = sum / ((1.0)*n);
    printf("\nAverage Turnaround Time is : %.2f", average);
}

int main()
{
    int n;
    
    printf("Enter the Number of processes :- ");
    scanf("%d",&n);
    
    int *burst_time = (int *)malloc(n * sizeof(int));
    int *arrival_time = (int *)malloc(n * sizeof(int));
    
    printf("\nEnter the Burst Time for Each Process :-\n");
    for(int i=0;i<n;i++)
    {
        printf("Burst time for Process P%d is :- ",i+1);
        scanf("%d",&burst_time[i]);
    }
    
    printf("\nEnter the Arrival Time for Each Process :-\n");
    for(int i=0;i<n;i++)
    {
        printf("Arrival time for Process P%d is :- ",i+1);
        scanf("%d",&arrival_time[i]);
    }
    
    printf("\n");
    
    int *bt_2 = (int *)malloc(n * sizeof(int));
    bt_2[0] = burst_time[0];
    for (int i = 1; i < n; i++)
    {
        bt_2[i] = bt_2[i - 1] + burst_time[i];
    }

    int *waiting_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    calc_waiting_time(n, waiting_time, bt_2, arrival_time,burst_time);
    printf("\n\n");
    calc_turnaround_time(n, turnaround_time, bt_2, arrival_time,burst_time);

    return 0;
}