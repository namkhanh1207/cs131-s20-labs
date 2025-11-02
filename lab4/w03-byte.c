#include "iobench.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f = fopen("data", "w");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    size_t size = 5120000;
    const char ch = '6';
    double start = tstamp();

    size_t n = 0;
    while (n < size) {
        if (fwrite(&ch, 1, 1, f) != 1) {
            perror("fwrite");
            exit(1);
        }
        n++;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    fclose(f);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
