#include "pathfinder.h"

void mx_lines_check(t_pathfinder *path) {
    for (int line = 2; *path->string != '\0'; path->string++) {
        while (*path->string != '-') {
            if (!mx_isalpha(*path->string)) {
                write(2, "error: line ", mx_strlen("error: line "));
                write(2, mx_itoa(line), mx_strlen(mx_itoa(line))); 
                write(2, " is not valid\n", mx_strlen(" is not valid\n"));
                exit(1);
            }
            path->string++;
        }
                
        mx_check_line(path, line);
        
        while (*path->string != '\n') {
            if (!mx_isdigit(*path->string) || mx_atoi(path->string) > INT_MAX) {
                write(2, "error: line ", mx_strlen("error: line "));
                write(2, mx_itoa(line), mx_strlen(mx_itoa(line))); 
                write(2, " is not valid\n", mx_strlen(" is not valid\n"));
                exit(1);
            }
            line++;
            path->string++;
        }
    }
}

