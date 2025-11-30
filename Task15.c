#include<stdio.h>
#include<string.h>

int main() {
    FILE *file1, *file2, *file3;
    char filename1[100];
    char filename2[100];
    char inp[1000];

    printf("Enter the name of the first file: ");
    scanf("%s", filename1);
    printf("\nEnter the name of the second file: ");
    scanf("%s", filename2);

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    file3 = fopen("merged.txt", "w");

    if (file1 == NULL || file2 == NULL || file3 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fgets(inp, sizeof(inp), file1) != NULL) {
        fputs(inp, file3);
    }

    while (fgets(inp, sizeof(inp), file2) != NULL) {
        fputs(inp, file3);
    }

    printf("Files merged successfully\n");

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}