#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile = fopen("san.txt", "r");
    FILE *destFile = fopen("nag.txt", "w");
    char c;

    if (sourceFile == NULL || destFile == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destFile);
    }
    return 0;
}

