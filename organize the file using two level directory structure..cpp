#include <stdio.h>

int main() {
    struct Directory {
        char dname[10], sdname[10][10], fname[10][10][10];
        int ds, sds[10];
    } dir[10];

    int n;
    printf("Enter number of directories: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter directory %d name and size: ", i + 1);
        scanf("%s %d", dir[i].dname, &dir[i].ds);

        for (int j = 0; j < dir[i].ds; j++) {
            printf("Enter subdirectory name and size: ");
            scanf("%s %d", dir[i].sdname[j], &dir[i].sds[j]);

            for (int k = 0; k < dir[i].sds[j]; k++) {
                printf("Enter file name: ");
                scanf("%s", dir[i].fname[j][k]);
            }
        }
    }

    printf("\nDirname\t\tSize\tSubdirname\tSize\tFiles\n");
    printf("******************************************************\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d", dir[i].dname, dir[i].ds);
        for (int j = 0; j < dir[i].ds; j++) {
            printf("\t%s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);
            for (int k = 0; k < dir[i].sds[j]; k++)
                printf("%s\t", dir[i].fname[j][k]);
            printf("\n\t\t");
        }
        printf("\n");
    }

    return 0;
}



