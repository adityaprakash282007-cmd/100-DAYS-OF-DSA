#include <stdio.h>

void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    char temp;

    while(i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int n;
    printf("Enter length: ");
    scanf("%d", &n);

    char s[n + 1];

    printf("Enter string: ");
    scanf("%s", s);

    reverseString(s, n);

    printf("Reversed string: %s\n", s);

    return 0;
}