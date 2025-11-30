#include<stdio.h>

int sum(int num);

int main() {
    int num;

    printf("Enter the Number: ");
    scanf("%d", &num);

    printf("Sum of Digits of Number is: %d", sum(num));
    return 0;
}

int sum(int num) {
    if (num == 0) {
        return 0;
    }

    int result = (num % 10) + sum(num / 10);

    return result;
}