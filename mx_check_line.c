#include "pathfinder.h"

void mx_check_line(t_pathfinder *path, int line) {
    char * number = mx_itoa(line);
    if (*path->string == '-' && !mx_isalpha(*(path->string - 1)) 
        && !mx_isalpha(*(path->string + 1))) {
            write(2, "error: line ", mx_strlen("error: line "));
            write(2, number, mx_strlen(number)); 
            write(2, " is not valid\n", mx_strlen(" is not valid\n"));
            exit(1);
        }
    path->string++;
    
    while (*path->string != ',') {
        if (!mx_isalpha(*path->string)) {
            write(2, "error: line ", mx_strlen("error: line "));
            write(2, number, mx_strlen(number)); 
            write(2, " is not valid\n", mx_strlen(" is not valid\n"));
            exit(1);
        }
        path->string++;
    }
            
    if (*path->string == ',' && !mx_isalpha(*(path->string - 1))
        && !mx_isdigit(*(path->string + 1))) {
            write(2, "error: line ", mx_strlen("error: line "));
            write(2, number, mx_strlen(number)); 
            write(2, " is not valid\n", mx_strlen(" is not valid\n"));
            exit(1);
    }
    path->string++;
}

