#include <stdio.h>
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
int main()
{
    int m,n;
    int blockSize[100],processSize[100];
    printf("Enter blocksize: ");
    scanf("%d",&m);
    printf("Enter Blocks: ");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&blockSize[i]);
    }
    printf("Enter processsize: ");
    scanf("%d",&n);
    printf("Enter Processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processSize[i]);
    }
    bestFit(blockSize, m, processSize, n);

    return 0;
}