#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void process_file(char *c_file);
void compile(char *c_file, char *binary);
char *get_binary_name(char *c_file);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        process_file(argv[arg]);
    }
    return 0;
}

// compile a C file
void process_file(char *c_file) {
    char *binary = get_binary_name(c_file);
    compile(c_file, binary);
    free(binary);
}


#define C_COMPILER "/usr/bin/gcc"

// compile a C file
void compile(char *c_file, char *binary) {
    // TODO: Complete this!
    // 1. Create/print compile command
    // 2. Run compile command
    // 3. Wait for command to complete
    // 4. Check the result of the compilation
    int pid;
    extern char **environ;
    char *spawn_argv[] = {C_COMPILER, c_file, "-o", binary, NULL};
    for (int i = 0; spawn_argv[i] != NULL; i++) {
        printf("%s ", spawn_argv[i]);
    }
    printf("\n");

    if (posix_spawn(&pid, C_COMPILER, NULL, NULL, spawn_argv, environ) != 0) {
        perror("posix_spawn");
        exit(1);
    }

    int exit_status;
    waitpid(pid, &exit_status, 0);

    if (exit_status != 0) {
        fprintf(stderr, "Compilation failed\n");
        exit(1);
    }
}


// give a string ending in .c
// return malloc-ed copy of string without .c

char *get_binary_name(char *c_file) {
    char *binary = strdup(c_file);
    if (binary == NULL) {
        perror("");
        exit(1);
    }

    // remove .c suffix
    char *last_dot = strrchr(binary, '.');
    if (last_dot == NULL || last_dot[1] != 'c' || last_dot[2] != '\0') {
        fprintf(stderr, "'%s' does not end in  .c\n", c_file);
        exit(1);
    }
    *last_dot = '\0';
    return binary;
}
