#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *str, const char *delim) {
    int i;
    char **word = NULL;
    char *token;

    // Calculate the number of words
    int num_words = 1;
    for (i = 0; str[i]; i++) {
        if (str[i] == delim[0]) {
            num_words++;
        }
    }

    // Allocate memory for word array
    word = (char **)malloc(num_words * sizeof(char *));
    if (word == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    i = 0;
    token = strtok(str, delim);
    while (token != NULL) {
        word[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    
    return word;
}

int main() {
    char input[] = "Hello world this is a test";
    const char *delimiter = " ";

    char **words = split(input, delimiter);
    if (words != NULL) {
        int i;
        for (i = 0; words[i] != NULL; i++) {
            printf("%s\n", words[i]);
            free(words[i]); // Free allocated memory for each word
        }
        free(words); // Free the array of word pointers
    }

    return 0;
}

