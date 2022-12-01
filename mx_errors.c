#include "pathfinder.h"

void mx_errors(t_pathfinder *path) {
    char *str = path->string;
    while (*path->string != '\n') {
        if (!mx_isdigit(*path->string)) {
            write(2, "error: line ", mx_strlen("error: line "));
            write(2, mx_itoa(1), mx_strlen(mx_itoa(1))); 
            write(2, " is not valid\n", mx_strlen(" is not valid\n"));
            exit(1);
        }
        path->string++;
    }
    path->string++;
    mx_lines_check(path);
    path->string = str;
    mx_islands_check(path);
}

