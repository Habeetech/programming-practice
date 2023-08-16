#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *splitword(char *str, const char *delim) {
    char *word;
    word = strtok(str, delim); // Get the first word
    
    while (word != NULL) {
        printf("%s\n", word); // Print the word (you can modify this as needed)
        word = strtok(NULL, delim); // Get the next word
    }
    
    return str; // Return the original string (modified string can be returned if needed)
}

int main() {
    char input[] = "Hello world this is a test";
    const char *delimiter = " ";

    splitword(input, delimiter);

    return 0;
}

