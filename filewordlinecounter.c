#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *file;
    char ch;
    int lines = 0, words = 0;
    bool inWord = false;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
        
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (inWord) {
                words++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        words++;  
    }

    fclose(file);

    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);

    return 0;
}
