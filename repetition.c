#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int c, d = 0, l = 0, i, p, q, f;
void code(l) {
    while ((c = getc(stdin)) != EOF) for (i = 0; i < l; i++) printf("%c", c);
}
void decode(l) {
    i = p = q = 0;
    while ((c = getc(stdin)) != EOF) {
        if (i == 0) f = c;
        if (c == '1') p++;
        else q++;
        if (i == l) {
            if (p > q) printf("1");
            else if (q > p) printf("0");
            else printf("%c", f);
            i = p = q = 0;
        }
        i++;
    }
}
void main(int argc, char **argv) {
    while ((c = getopt(argc, argv, "l:d")) != -1) {
        switch (c) {
            case 'l':
                l = atoll(optarg);
                break;
            case 'd':
                d = 1;
                break;
        }
    }
    if (l < 1) {
        printf("The length argument (l) must be an integer greater than zero");
        exit(1);
    }
    if (d == 1) decode(l);
    else code(l);
}
