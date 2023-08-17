#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDirectoriesFromPath() {
    char *path = getenv("PATH");
    
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return;
    }
    
    char *token = strtok(path, ":");
    
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main() {
    printDirectoriesFromPath();
    return 0;
}
