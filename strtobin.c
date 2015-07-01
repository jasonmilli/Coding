#include <stdio.h>
int c, i = 0, t = 0;
void bintostr() {
    while ((c = getc(stdin)) != EOF) {
        //printf("|%d|", c - '0');
        t += (1 << ((6 - i) % 7)) * (c - '0');
        i++;
        if (i % 7 == 0) {
            printf("%c", t);
            t = 0;
            i = 0;
        }
    }
}
void strtobin() {}
int main(int argc, char **argv) {
    if (getopt(argc, argv, "d") == 'd') bintostr();
    else strtobin();
}
