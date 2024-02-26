#include <stdio.h>

int main() {
    int bsize[10], psize[10], allocation[10] = {-1}, bno, pno, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &bno);
    printf("Enter sizes of each block: ");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &pno);
    printf("Enter sizes of each process: ");
    for (i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    for (i = 0; i < pno; i++)
        for (j = 0; j < bno; j++)
            if (allocation[j] == -1 && bsize[j] >= psize[i]) {
                allocation[j] = i;
                break;
            }

    printf("\nBlock no.\tSize\t\tProcess no.\t\tSize");
    for (i = 0; i < bno; i++)
        printf("\n%d\t\t%d\t\t%s\t\t\t%d", i + 1, bsize[i], allocation[i] != -1 ? "P" : "Not allocated", allocation[i] != -1 ? psize[allocation[i]] : 0);

    return 0;
}

