#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
int c, n = 0, d = 0, i, l, t = 0, j = 0, k = 1;
char *g = 0;
int **a;
//int* binary(int t) {
    
void creatematrix() {
    int arrsize = sizeof(int) * n;
    a = malloc(arrsize);
    int ii = 0;
    for (i = strlen(g) - 1; i >= -1; i--) {
        if (i == -1 || g[i] == ',') {
            k++;
            if (t > (1 << n)) {
                printf("All rows in the generator matrix (g) must by shorter than the length (n) argument");
                exit(0);
            }
            //int *a = binary(t);
            int b[n];
            for (l = 0; l < n; l++) {
                if (t >= (1 << (n - l - 1))) {
                    b[l] = 1;
                    t -= (1 << (n - l - 1));
                } else b[l] = 0;
            }
            a = realloc(a, arrsize * (ii + 1));
            a[ii] = b;
            ii++;
            printf("%d\n", t);
            t = j = 0;
        } else {
            t += (g[i] - '0') * pow(10,j);
            j++;
        }
    }
}
void decode() {
}
void encode() {
    while ((c = getc(stdin)) != EOF) {
        
}
void main(int argc, char **argv) {
    while ((c = getopt(argc, argv, "n:g:d")) != -1) {
        switch (c) {
            case 'n':
                n = atoll(optarg);
                break;
            case 'd':
                d = 1;
                break;
            case 'g':
                g = optarg;
                break;
        }
    }
    if (n < 1) {
        printf("You must provide a length (n) argument");
        exit(0);
    }
    if (g == 0) {
        printf("You must provide a generator matrix (g) argument");
        exit(0);
    }
    creatematrix();
    if (d == 1) decode();
    else encode();
    free(a);
    exit(0);
}
