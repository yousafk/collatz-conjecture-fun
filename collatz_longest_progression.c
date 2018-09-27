/*
 * Yousaf Khan
 * CSC431 High Performance Computing
 * collatz_longest_progression.c
 *
 * Given any positive integer n, display the positive integer k, where 1 <= k <= n, that has the most 
 * number of steps. Display the number of steps for k along with the number milliseconds needed to
 * determine the answer
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int steps(int v) {
    int count = 0; 
    int pos_int = v;
    int max = pos_int; 
    while (pos_int != 1) {
        // bitwise odd check -- seemed a healthier route for speedup using bits known already
        if (pos_int & 1) {
            pos_int = 3*pos_int + 1;
        } else {
            pos_int = pos_int / 2;
        }

        if (pos_int > max) {
            max = pos_int;
        }

        count++;
    }
    return count;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "ERROR: Needs one INT parameter to compute steps\n");
        exit(-1);
    }

    int n = atoi(argv[1]);
    // because no known sequence excludes 1, we can assume there will always be min of 1 step to get back to 1
    int max = 1;
    int count = 0;

     // start timing
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    for (int i = 1; i <= n; i++) {
        int val = steps(i);

        if (max < val) {
            max = val;
            count = i;
        }
    }

    // stop timing
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    // compute elapsed time (ms)
    unsigned long long delta_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

    printf("%d,%d\n", count, max);
    printf("%llu\n", delta_ms);

    return 0;
}
