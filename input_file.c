// Single-line comment before include
#include "sample_header.h"

/* Multi-line comment
   spanning multiple lines */
#define MAX_COUNT 10
#define MAX_VALUE 100

int main(void) {
    int count = MAX_COUNT; // should expand MAX_COUNT, not touch MAX_VALUE
    int total = add_bonus(count);

    // Simple print call to verify expansion
    printf("%s: %d\n", GREETING, total);
    return 0;
}
