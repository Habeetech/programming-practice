#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) {
    if (name == NULL) {
        return -1; // Invalid argument
    }

    size_t name_length = strlen(name);
    
    for (int i = 0; environ[i] != NULL; i++) {
        if (strncmp(name, environ[i], name_length) == 0 && environ[i][name_length] == '=') {
            // Move the pointers after the deleted variable
            int j = i;
            while (environ[j + 1] != NULL) {
                environ[j] = environ[j + 1];
                j++;
            }
            
            // Set the last pointer to NULL to indicate the end of the environment
            environ[j] = NULL;
            return 0;
        }
    }

    return 0; // Variable not found, but return success as per unsetenv
}

int main() {
    // Example usage of _unsetenv
    int result = _unsetenv("MY_VARIABLE");
    if (result == 0) {
        printf("Environment variable deleted successfully.\n");
    } else {
        printf("Failed to delete environment variable.\n");
    }

    return 0;
}

