#include <stdio.h>

int main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    int end = i - 1;
    int start = 0;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("Reversed: %s\n", str);

    return 0;
}
