#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);

char *_getenv(const char *name)
{
    extern char **environ; // Declare the global environ variable
    for (int i = 0; environ[i] != NULL; i++) // Iterate through the environment variables
    {
        char *env_var = environ[i];
        if (strncmp(name, env_var, strlen(name)) == 0 && env_var[strlen(name)] == '=') // Check if the name matches and is followed by '='
        {
            return &env_var[strlen(name) + 1]; // Return the value part of the environment variable
        }
    }
    return NULL; // Environment variable not found
}

int main()
{
    char *value = _getenv("PATH");
    if (value != NULL)
    {
        printf("PATH value is: %s\n", value);
    }
    else
    {
        printf("PATH value not found\n");
    }
    return 0;
}

