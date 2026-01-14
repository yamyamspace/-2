#include <stdio.h>
#include <ctype.h>  // isspace()

int main(void) {
    int c;
    long bytes = 0, words = 0, lines = 0;
    int in_word = 0;

    while ((c = getchar()) != EOF) {
        bytes++;  // ¸ð¹®À ÆÇ (space, tab, newline)

        if (c == '\n')
            lines++;

        if (isspace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        }
    }

    printf(" %ld %ld %ld\n", lines, words, bytes);
    return 0;
}

