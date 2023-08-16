#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024

void run_command(char *command) {
    char *args[] = {command, NULL};
    execvp(command, args);
    perror("Command execution failed");
}

int main() {
    char user_input[MAX_INPUT_SIZE];

    while (1) {
        printf("shell> ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline character

        if (strcmp(user_input, "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            run_command(user_input);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("Fork failed");
        } else {
            wait(NULL);
        }
    }

    return 0;
}

