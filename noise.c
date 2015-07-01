#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) {
    time_t t;
    int c, h;
    float p = -1, q = -1, r;
    while ((c = getopt(argc, argv, "p:q:")) != -1) {
        switch (c) {
            case 'p':
                p = atof(optarg);
                break;
            case 'q':
                q = atof(optarg);
                break;
        }
    }
    if (p == -1) {
        fprintf(stderr, "You must provide argument p");
        exit(1);
    }
    if (q == -1) q = p;
    srand((unsigned) time(&t));
    while ((h = getc(stdin)) != EOF) {
        r = (float)(rand() % 1000000) / 1000000;
        //printf("%f\n", r);
        //printf("%c\n", h);
        //printf("R %f, P %f, Q %f, H %c\n", r,p,q,h);
        switch (h) {
            case '1':
                if (p >= r) printf("0");
                else printf("1");
                break;
            case '0':
                if (q >= r) printf("1");
                else printf("0");
                break;
        }
    }
    exit(1);
}
