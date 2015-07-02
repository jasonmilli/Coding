#include <stdio.h>
int c, i = 0, t = 0;
void bintostr() {
    while ((c = getc(stdin)) != EOF) {
        t += (1 << ((6 - i) % 7)) * (c - '0');
        i++;
        if (i % 7 == 0) {
            printf("%c", t);
            t = 0;
            i = 0;
        }
    }
}
void strtobin() {
    while ((c = getc(stdin)) != EOF) {
        //printf("%d\n", c);
        for (i = 6; i >= 0; i--) {
            //printf("%d %d %d, ", c, 1 << i, i);
            if (c >= (1 << i)) {
                printf("%c", '1');
                c -= (1 << i);
            } else printf("%c", '0');
        }
    }
}
int main(int argc, char **argv) {
    if (getopt(argc, argv, "d") == 'd') bintostr();
    else strtobin();
}
