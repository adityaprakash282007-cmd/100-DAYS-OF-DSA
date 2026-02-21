#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));

    int prefix = 1;
    for(int i = 0; i < numsSize; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int* ans = productExceptSelf(nums, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);
    return 0;
}
