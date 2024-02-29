#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3

int pageReplacement(int pages[], int n) {
    int frame[NUM_FRAMES] = {-1, -1, -1};
    int page_faults = 0;

    for (int i = 0; i < n; ++i) {
        bool page_found = false;
        for (int j = 0; j < NUM_FRAMES; ++j) {
            if (frame[j] == pages[i]) {
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            int farthest = -1, replace_index;
            for (int j = 0; j < NUM_FRAMES; ++j) {
                int k;
                for (k = i + 1; k < n; ++k) {
                    if (frame[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            replace_index = j;
                        }
                        break;
                    }
                }
                if (k == n) {
                    replace_index = j;
                    break;
                }
            }
            frame[replace_index] = pages[i];
            ++page_faults;
        }
    }

    return page_faults;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int num_pages = sizeof(pages) / sizeof(pages[0]);

    int page_faults = pageReplacement(pages, num_pages);

    printf("Number of page faults using Optimal algorithm: %d\n", page_faults);

    return 0;
}

