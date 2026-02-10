#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};

    for(int i = 0; i < nums1Size; i++)
        freq[nums1[i]]++;

    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));

    int k = 0;
    for(int i = 0; i < nums2Size; i++) {
        if(freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int n, m;

    printf("Enter size of nums1: ");
    scanf("%d", &n);
    int nums1[n];

    printf("Enter nums1 elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);

    printf("Enter size of nums2: ");
    scanf("%d", &m);
    int nums2[m];

    printf("Enter nums2 elements: ");
    for(int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);

    int returnSize;
    int* result = intersect(nums1, n, nums2, m, &returnSize);

    printf("Intersection: ");
    for(int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}
