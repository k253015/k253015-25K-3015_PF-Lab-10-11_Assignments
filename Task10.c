#include<stdio.h>
#include<string.h>

void checkPalindrome(char str[][20]) {
    for(int a = 0; a < 5; a++) {
        int isPalindrome = 1;
        int len = strlen(str[a]);
        for(int i=0, j=len-1; i<j; i++, j--) {
            if(str[a][i] != str[a][j]) {
                isPalindrome = 0;
                break;
            }
        }
        if(isPalindrome == 1) {
            printf("\nThe string %s is a palindrome.", str[a]);
        } else {
            printf("\nThe string %s is not a palindrome.", str[a]);
        }
    }
}
int main() {
    char str[5][20];

    printf("Enter 5 strings:");
    for(int i = 0; i < 5; i++) {
        printf("\nEnter string %d: ", i+1);
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = 0;
    }

    checkPalindrome(str);
    return 0;
}