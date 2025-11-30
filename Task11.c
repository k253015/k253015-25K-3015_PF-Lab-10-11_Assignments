#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char random[5][20]={
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry"
    };
    char input[20];
    int found = 0;

    printf("Enter a fruit name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        input[i] = tolower(input[i]);
    }
    
    
    for(int i=0; i<5; i++) {
        if(strcmp( random[i], input ) == 0) {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Found\n");
    } else{
        printf("Not Found\n");
    }
    
    return 0;
}