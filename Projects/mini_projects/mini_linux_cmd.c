#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
int main() {

    bool running = true;
    while(running) {
        char input[64];

        printf(":");
        if(fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
                if(strcmp(input, "exit\n") == 0) {
                    running = false;
                    continue;
                }


        pid_t pid = fork();

        if(pid < 0) {
            perror("Fork failed");
            return 1;
        }else if(pid == 0) {

            char *cmds[64];
            int i = 0;

            char *token = strtok(input, " \n");
            while(token != NULL && i < 63) {
                cmds[i] = token;
                i++;
                token = strtok(NULL, " \n");
            }

            cmds[i] = NULL;

            if(cmds[0] == NULL) {
                exit(0);
            }
            execvp(cmds[0], cmds);

            perror("execvp");
            exit(1);
        } else {
            int status;

            if(waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                return 1;
            }
                if(WIFEXITED(status)) {
                    printf("Child executed with status : %d\n", WEXITSTATUS(status));
                }else if (WIFSIGNALED(status)) {
    printf("Terminated by signal: %d\n", WTERMSIG(status));
}

        }

    }
        return 0;
}
