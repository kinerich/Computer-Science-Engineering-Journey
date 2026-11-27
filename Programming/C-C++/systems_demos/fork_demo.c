
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("first fork");
        return 1;
    }
    else if (pid == 0) {
        printf("Downloading...\n");
        exit(0);
    }
    else {
        int status2;
        int status;
        pid_t pid2 = fork();

        if (pid2 < 0) {
            perror("second fork");
            return 1;
        }
        else if (pid2 == 0) {
            printf("Processing...\n");
            exit(5);
        }
        else {
            if (waitpid(pid2, &status, 0) == -1) {
                perror("waitpid child 2");
                return 1;
            }

            if (waitpid(pid, &status2, 0) == -1) {
                perror("waitpid child 1");
                return 1;
            }

            if (WIFEXITED(status)) {
                printf("Child 2 exit code: %d\n", WEXITSTATUS(status));
            }

            if (WIFEXITED(status2)) {
                printf("Child 1 exit code: %d\n", WEXITSTATUS(status2));
            }
        }
    }

    return 0;
}

