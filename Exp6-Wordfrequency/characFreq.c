#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Split the input into words
    char* word = strtok(str, " \n");
    int count = 0;
    char words[100][100];

    while (word != NULL) {
        strcpy(words[count], word);
        count++;
        word = strtok(NULL, " \n");
    }

    // Count the frequency of each word
    int frequency[count];
    int visited = -1;

    for (int i = 0; i < count; i++) {
        int wordCount = 1;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCount++;
                frequency[j] = visited;
            }
        }
        if (frequency[i] != visited)
            frequency[i] = wordCount;
    }

    // Print the word and its frequency
    printf("---------------------\n");
    printf("   Word    | Frequency\n");
    printf("---------------------\n");

    for (int i = 0; i < count; i++) {
        if (frequency[i] != visited) {
            printf("%-10s | %d\n", words[i], frequency[i]);
        }
    }

    printf("---------------------\n");

    return 0;
}