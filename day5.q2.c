#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;        // last index of valid nums1
    int j = n - 1;        // last index of nums2
    int k = m + n - 1;    // last index of nums1 total size

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining nums2 elements
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    // Print merged array
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
