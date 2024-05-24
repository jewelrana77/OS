#include <stdio.h>
int n,r;
#define P 5
#define R 4
void calculateNeed(int need[n][r], int maxm[n][r],int allot[n][r])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}
int isSafe(int processes[], int avail[], int maxm[][r], int allot[][r])
{
    int need[n][r];
    calculateNeed(need, maxm, allot);
    int finish[P] = {0};
    int safeSeq[n];
    int work[r];
    for (int i = 0; i < r; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < n)
    {
        int found = 0;
        for (int p = 0; p < n; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < r; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == r)
                {
                    for (int k = 0 ; k < r ; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0)
        {
            printf("System is not in safe state");
            return 0;
        }
    }
    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", safeSeq[i]);

    return 1;
}
int main()
{
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int processes[n];
    printf("Enter the processes:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processes[i]);
    }
    printf("Enter number of resources: ");
    scanf("%d",&r);
    int avail[r];
    int maxm[n][r];
    int allot[n][r];
    printf("Enter the available instances of resources:\n");
    for (int i = 0; i < r; i++)
        scanf("%d", &avail[i]);
    printf("Enter the maximum resources that can be allocated to processes:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &maxm[i][j]);
    printf("Enter the resources allocated to processes:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &allot[i][j]);
    isSafe(processes, avail, maxm, allot);
    return 0;
}