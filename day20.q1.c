#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Hash map simulation using array
    // Offset used to handle negative sums
    int offset = MAX;
    int size = 2 * MAX + 1;

    int *freq = (int*)calloc(size, sizeof(int));

    int sum = 0, count = 0;

    // sum = 0 already seen once
    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0)
            count += freq[sum + offset];

        freq[sum + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}
