#include <stdio.h>

int contiguous_allocation(char position) {
    return (position == 'b' || position == 'e') ? 1 :  (position == 'm') ? 51 : 0;
}

int linked_allocation(char position) {
    return 1;
}

int indexed_allocation(char position) {
    return (position == 'b' || position == 'e') ? 2 : 3;
}

int main() {
    char position;

    printf("Enter the position of the block to be added (b/m/e): ");
    scanf(" %c", &position);

    printf("For Contiguous Allocation: %d disk I/O operations required.\n", contiguous_allocation(position));
    printf("For Linked Allocation: %d disk I/O operations required.\n", linked_allocation(position));
    printf("For Indexed Allocation: %d disk I/O operations required.\n", indexed_allocation(position));

    return 0;
}

