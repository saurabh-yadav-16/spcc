#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int length = strlen(str) - 1; // Exclude the newline character
    int fr[length];
    int visited = -1;
    for (int i = 0; i < length; i++) {
        int count = 1;
        for (int j = i + 1; j < length; j++) {
            if (str[i] == str[j]) {
                count++;
                fr[j] = visited;
            } }
        if (fr[i] != visited)
            fr[i] = count;
    }
    printf("---------------------\n");
    printf(" Character | Frequency\n");
    printf("---------------------\n");
    for (int i = 0; i < length; i++) {
        if (fr[i] != visited) {
            printf("    %c", str[i]);
            printf("    |  ");
            printf("  %d\n", fr[i]);
        }}
    printf("---------------------\n");

    return 0;
}