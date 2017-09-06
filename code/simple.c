#include <stdio.h>
#include <stdlib.h>
#define ITER_MAX 10000
#define RAND_SEED 68111

int
main(int argc, char** argv) {
    int i, pi; 
    double x, y, area;
    srand48(RAND_SEED);

    pi = 0;
    for (i=1; i<=ITER_MAX; i++) {
        x = drand48() * 2 - 1;
        y = drand48() * 2 - 1;
        if (( x*x + y*y ) < 1) {
            pi++;
        }
        area = 4 * (double) pi / i;
        printf("%i\t%f\n", i, area);
    }

    return 0;
}
