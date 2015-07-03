#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
int c, n = 0, d = 0, i, l, t = 0, j = 0, k = 0;
char *g = 0;
int **a;
void creatematrix() {
    int arrsize = sizeof(int) * n;
    a = malloc(sizeof(int *));
    int ii = 0;
    int m,mm;
    for (i = strlen(g) - 1; i >= -1; i--) {
        if (i == -1 || g[i] == ',') {
            k++;
            if (t > (1 << n)) {
                printf("All rows in the generator matrix (g) must by shorter than the length (n) argument");
                free(a);
                exit(0);
            }
            a = realloc(a, (ii + 1) * sizeof(int *));
            a[ii] = malloc(n * sizeof(int));
            for (l = 0; l < n; l++) {
                if (t >= (1 << (n - l - 1))) {
                    a[ii][l] = 1;
                    t -= (1 << (n - l - 1));
                } else a[ii][l] = 0;
            }
            ii++;
            t = j = 0;
        } else {
            t += (g[i] - '0') * pow(10,j);
            j++;
        }
    }
    /*for (m = 0; m < k; m++) {
        for (mm = 0; mm < n; mm++) printf("%d ", a[m][mm]);
        printf("\n");
    }*/
}
void decode() {
    
}
void normalform() {
    int nn = n;
    int kk = k;
    int nfi;
    for (nfi = 0; nfi < k; nfi++) {
        
}
void encode() {
    normalform();
    int iii = 0, jjj;
    int col[n];
    int ci;
    for (ci = 0; ci < n; ci++) col[ci] = 0;
    while ((c = getc(stdin)) != EOF) {
        if (iii % k == 0) {
            for (ci = 0; ci < n; ci++) {
                if (iii != 0) printf("%d", (col[ci] & 1));
                col[ci] = 0;
            }
        }
        for (ci = 0; ci < n; ci++) col[ci] += c * a[iii % k][ci];
        iii++;
    }
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
