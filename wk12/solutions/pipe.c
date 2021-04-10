#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[]) {

    // Array pipe will place its file descriptors
    int fds[2];

    // If there was an error with pipe
    if (pipe(fds)) {
        perror("pipe");
        exit(1);
    }

    int pid = fork();
    if (pid == 0) {
        // Make grep output to the writing end of the
        // pipe (replace stdout with the pipe)
        dup2(fds[1], 1);
        // close the read end of the pipe (grep
        // will not read from it)
        close(fds[0]);
        char *grep_argv[] = {"/usr/bin/grep", "main", "file.txt", NULL};
        execve("/usr/bin/grep", grep_argv, NULL);
    } else {
        // Make wc input from the reading end of the
        // pipe (replace stdin with the pipe)
        dup2(fds[0], 0);
        // close the write end of the pipe (wc
        // will not write to it)
        close(fds[1]);
        char *wc_argv[] = {"/usr/bin/wc", NULL};
        execve("/usr/bin/wc", wc_argv, NULL);
    }
}
