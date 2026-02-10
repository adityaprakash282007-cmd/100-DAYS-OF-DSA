#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    printf("Enter string: ");
    scanf("%s", str);   // reads string without spaces

    int i = 0, j = strlen(str) - 1;
    char temp;

    // Reverse using two-pointer method
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}