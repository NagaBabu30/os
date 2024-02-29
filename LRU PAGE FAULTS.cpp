#include <stdio.h>

#define MAX_FRAMES 3

int pageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int page_faults = 0;

    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == pages[i])
                break;
        }
        if (j == MAX_FRAMES) {
            int lruIndex = (i == 0) ? 0 : ((i - 1) % MAX_FRAMES);
            frames[lruIndex] = pages[i];
            ++page_faults;
        }
    }

    return page_faults;
}

int main() {
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_pages = sizeof(pages) / sizeof(pages[0]);

    int page_faults = pageReplacement(pages, num_pages);

    printf("Number of page faults using LRU algorithm: %d\n", page_faults);

    return 0;
}

