#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];
    int sum = 0;

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int n = size + 1;
    int expectedSum = n * (n + 1) / 2;

    int missing = expectedSum - sum;

    printf("%d\n", missing);

    return 0;
}
