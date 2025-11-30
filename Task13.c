#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;

    printf("Enter the filename (e.g., data.txt): ");
    scanf("%s", filename);

    printf("Deleting contents of %s...\n", filename);

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fclose(file);
    printf("Contents deleted successfully.\n");

    printf("Verifying if file is empty...\n");

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File cant be opened.\n");
        return 1;
    }

    ch = fgetc(file);

    if (ch == -1) {
        printf("File is empty.\n");
    } else {
        printf("File is not empty.\n");
    }

    fclose(file);
    return 0;
}