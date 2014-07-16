#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

size_t get_argv_size(int argc, char **argv);
char *get_expression(int argc, char **argv);
char *get_exec_cmd(char *expression);

size_t get_argv_size(int argc, char **argv) {
    size_t expression_size = strlen(argv[1]);
    for (int i = 2; i < argc; i++) {
        expression_size += strlen(argv[i]);
    }
    return expression_size;
}

char *get_expression(int argc, char **argv) {
    char *cmd = malloc(get_argv_size(argc, argv));
    for (int i = 1; i < argc; ++i) {
        if (!strlen(cmd)) {
            strcpy(cmd, argv[i]);
        } else {
            strcat(cmd, argv[i]);
        }
    }
    return cmd;
}

char *get_exec_cmd(char *expression) {
    char *format = "printf '0x%%x\n' $[%s]";
    char *exec_cmd = malloc(strlen(expression) + strlen(format));
    sprintf(exec_cmd, format, expression);
    return exec_cmd;
}

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Usage - `hexcalc {expression}`\n");
        return 0;
    }
    
    FILE *fp;
    int status;
    char path[1024];
    
    char *expression = get_expression(argc, argv);
    printf("evaling: %s\n", expression);
    
    char *exec_cmd = get_exec_cmd(expression);
    fp = popen(exec_cmd, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        return 1;
    }
    
    while (fgets(path, sizeof(path) - 1, fp) != NULL) {
        printf("result : %s", path);
    }
    
    free(expression);
    free(exec_cmd);
    
    pclose(fp);
    return 0;
}