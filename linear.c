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
                free(a);
                exit(0);
            }
            int b[n];
            for (l = 0; l < n; l++) {
                if (t >= (1 << (n - l - 1))) {
                    b[l] = 1;
                    t -= (1 << (n - l - 1));
                } else b[l] = 0;
            }
            /*int mmm;
            for (mmm = 0; mmm < sizeof(n); mmm++) printf("b%d: %d", ii, b[mmm]);
            printf("\n");*/
            a = realloc(a, arrsize * (ii + 1));
            a[ii] = b;
            ii++;
            //printf("%d\n", t);
            t = j = 0;
        } else {
            t += (g[i] - '0') * pow(10,j);
            j++;
        }
    }
    int m,mm;
    for (m = 0; m < sizeof(a) / sizeof(a[0]); m++) {
        for (mm = 0; mm < sizeof(a[m]); mm++) printf("%d ", a[m][mm]);
        printf("\n");
    }
}
void decode() {
}
void encode() {
    int iii = 0, tt, jjj;
    while ((c = getc(stdin)) != EOF) {
        if (iii % k == 0) {
            tt = 0;
            if (iii != 0) printf("%d", (tt & 1));
        }
        //for (jjj = 0; jjj < n; jjj++) tt += a[iii % k][jjj];
        iii++;
    }
    printf("%d", (tt & 1));
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
