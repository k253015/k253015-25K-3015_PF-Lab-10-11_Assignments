#include<stdio.h>

int search(int arr[], int size, int target, int i) {
    if (arr[i] == target) {
        return i;
    }
    else if (i < size - 1) {
        i++;
    }
    search(arr, size, target, i);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    printf("Target is at index: %d",search(arr,size,target,0));
    return 0;
}