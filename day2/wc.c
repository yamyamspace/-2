#include <stdio.h>
#include <ctype.h>   // isspace()
#include <stdlib.h>  // exit()

void count_stream(FILE *fp, const char *name) {
    int c;
    size_t bytes = 0, words = 0, lines = 0;
    int in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        bytes++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        }
    }

    if (name)
        printf("%zu %zu %zu %s\n", lines, words, bytes, name);
    else
        printf("%zu %zu %zu\n", lines, words, bytes);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // ǥÁ À·Âó¸®
        count_stream(stdin, NULL);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (!fp) {
                perror(argv[i]);
                exit(EXIT_FAILURE);
            }
            count_stream(fp, argv[i]);
            fclose(fp);
        }
    }
    return 0;
}
