#include <stdio.h>
#include <unistd.h>

void printNumbers(char *name, int start, int end, int step) {
    printf("%s numbers: ", name);
    for (int i = start; i <= end; i += step) printf("%d ", i);
    printf("\n");
}

int main() {
    for (int i = 1; i <= 4; i++) {
        if (fork() == 0) {
            switch (i) {
                case 1:
                    printNumbers("Odd", 1, 10, 2);
                    break;
                case 2:
                    printNumbers("Even", 2, 10, 2);
                    break;
                case 3:
                    printNumbers("Multiples of 3", 3, 9, 3);
                    break;
                case 4:
                    printNumbers("Multiples of 5", 5, 10, 5);
                    break;
            }
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) wait(NULL);
    return 0;
}


