#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || value == NULL) {
        return -1; // Invalid arguments
    }

    size_t name_length = strlen(name);
    size_t value_length = strlen(value);
    
    // Check if the environment variable exists
    for (int i = 0; environ[i] != NULL; i++) {
        if (strncmp(name, environ[i], name_length) == 0 && environ[i][name_length] == '=') {
            if (!overwrite) {
                return 0; // Variable already exists, no overwrite
            }

            // Overwrite the existing variable
            char *new_var = (char *)malloc(name_length + value_length + 2); // 1 for '=', 1 for '\0'
            if (new_var == NULL) {
                perror("Memory allocation error");
                return -1;
            }
            
            sprintf(new_var, "%s=%s", name, value);
            free(environ[i]);
            environ[i] = new_var;
            return 0;
        }
    }

    // Variable does not exist, create a new one
    char *new_var = (char *)malloc(name_length + value_length + 2); // 1 for '=', 1 for '\0'
    if (new_var == NULL) {
        perror("Memory allocation error");
        return -1;
    }
    
    sprintf(new_var, "%s=%s", name, value);
    
    // Count the number of existing environment variables
    int env_count = 0;
    while (environ[env_count] != NULL) {
        env_count++;
    }

    // Allocate memory for the new environment array
    char **new_environ = (char **)malloc((env_count + 2) * sizeof(char *));
    if (new_environ == NULL) {
        perror("Memory allocation error");
        free(new_var);
        return -1;
    }
    
    // Copy existing environment variables to the new array
    for (int i = 0; i < env_count; i++) {
        new_environ[i] = environ[i];
    }
    
    // Add the new variable to the new array
    new_environ[env_count] = new_var;
    new_environ[env_count + 1] = NULL;

    // Replace the old environment array with the new one
    environ = new_environ;

    return 0;
}

int main() {
    // Example usage of _setenv
    int result = _setenv("MY_VARIABLE", "my_value", 1); // Overwrite if exists
    if (result == 0) {
        printf("Environment variable set or changed successfully.\n");
    } else {
        printf("Failed to set or change environment variable.\n");
    }

    return 0;
}

