#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int fds[2];
    pipe(fds);

    pid_t pid = fork();
    if (pid == -1) {
        // error
    }

    if (pid == 0) {
        // In child, so run grep
        dup2(fds[1], 1);
        close(fds[0]);

        char *grep_args[] = {"/usr/bin/grep", "main", "file.txt", NULL};
        execve("/usr/bin/grep", grep_args, NULL);
    } else {
        // In parent, so run wc
        dup2(fds[0], 0);
        close(fds[1]);

        char *wc_args[] = {"/usr/bin/wc", NULL};
        execve("/usr/bin/wc", wc_args, NULL);
    }
}
