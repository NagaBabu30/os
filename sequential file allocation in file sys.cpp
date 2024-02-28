#include <stdio.h>

#define TOTAL_BLOCKS 16
#define MIN_FILE_SIZE 1024

int blocks[TOTAL_BLOCKS] = {0}; // 0: free, 1: allocated

int find_contiguous_blocks(int num_blocks) {
    int start_block = -1, count = 0;

    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        if (blocks[i] == 0) {
            if (start_block == -1)
                start_block = i;
            count++;
            if (count == num_blocks)
                return start_block;
        } else {
            start_block = -1; // Reset if contiguous sequence breaks
            count = 0;
        }
    }
    return -1; // Not enough contiguous blocks available
}

int main() {
    int file_size_kb;
    printf("Enter file size in KB: ");
    scanf("%d", &file_size_kb);

    if (file_size_kb < MIN_FILE_SIZE) {
        printf("Minimum file size is 1 KB.\n");
        return 1;
    }

    int num_blocks = (file_size_kb + 1023) / 1024; // Round up to nearest block
    int start_block = find_contiguous_blocks(num_blocks);

    if (start_block != -1) {
        for (int i = start_block; i < start_block + num_blocks; i++)
            blocks[i] = 1; // Allocate blocks
        printf("File allocated. Start block: %d\n", start_block);
    } else {
        printf("Not enough contiguous blocks available.\n");
        return 1;
    }

    return 0;
}

