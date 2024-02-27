#include <stdio.h>
#include <string.h>

int main() {
    char mdname[10], fname[10][10], name[10];
    int nf = 0, i, ch;

    printf("Enter directory name: ");
    scanf("%s", mdname);
    printf("Enter number of files: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++) {
        printf("Enter file name: ");
        scanf("%s", name);
        if (!strcmp(name, fname[i]))
            printf("File already exists\n");
        else
            strcpy(fname[i], name);
        printf("Enter another file (yes - 1 or no - 0): ");
        scanf("%d", &ch);
        if (ch != 1)
            break;
    }

    printf("Directory name: %s\nFiles:", mdname);
    for (i = 0; i < nf; i++)
        printf("\n%s", fname[i]);

    return 0;
}

