/*
 * Yousaf Khan
 * CSC431 High Performance Computing
 * collatz_max_climb.c
 *
 * Given any positive integer n, display the number of steps required to reach 1 along
 * with the highest number reach while iterating through the sequence
 *
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[] ) {
    
    if (argc != 2) {
        fprintf(stderr, "ERROR: Needs one INT parameter to compute steps\n");
        exit(-1);
    }

    int pos_int = atoi(argv[1]); 
    int count = 0;
    // because no known sequence excludes 1, we can assume there will always be min of 1 step to get back to 1
    int max = 1;
    
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

    printf("%d,%d\n",count, max);
    return 0;
}
