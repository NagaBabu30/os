#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void fibonacci(int n) {
    int a = 0, b = 1;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    if (pid == 0) {
        fibonacci(10);
    } else {
        wait(NULL);
        printf("Prime Numbers: ");
        for (int i = 2; i <= 30; i++)
            if (is_prime(i)) printf("%d ", i);
        printf("\n");
    }
    return 0;
}

