#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;

    int characters = 0, words = 0, lines = 0;
    int in_word = 0;

    printf("Enter the filename (e.g., data.txt): ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != -1) {
        characters++;

        if (ch == '\n') {
            lines++;
        }
        if (isspace(ch)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    if (characters > 0) {
        lines++;
    }

    fclose(file);

    printf("\n--- File Info ---\n");
    printf("Total Characters: %d\n", characters);
    printf("Total Words:      %d\n", words);
    printf("Total Lines:      %d\n", lines);

    return 0;
}