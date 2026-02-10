#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int j = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    while(j < numsSize) {
        nums[j] = 0;
        j++;
    }
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    moveZeroes(arr, n);

    printf("Output: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}