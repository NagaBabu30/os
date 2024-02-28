#include <stdio.h>

#define DISK_BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4 // bytes

long long max_file_size(int direct_blocks) {
    long long max_size = 0;
    max_size += direct_blocks * DISK_BLOCK_SIZE;
    max_size += (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;
    max_size += (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;
    max_size += (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;
    return max_size;
}

int main() {
    int direct_blocks;

    printf("Enter the number of direct blocks: ");
    scanf("%d", &direct_blocks);

    long long max_size = max_file_size(direct_blocks);
    printf("Maximum size of a file: %lld bytes\n", max_size);

    return 0;
}


