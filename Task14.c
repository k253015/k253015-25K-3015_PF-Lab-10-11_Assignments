#include <stdio.h>
#include <time.h>

int main() {
    FILE *file;
    char filename[] = "log.txt";

    time_t current_time;
    time(&current_time);

    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error: File can not be opened\n");
        return 1;
    }

    fprintf(file, "Program executed at: %s", ctime(&current_time));

    printf("Log entry added to %s successfully.\n", filename);

    fclose(file);

    return 0;
}