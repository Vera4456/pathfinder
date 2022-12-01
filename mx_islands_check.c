#include "pathfinder.h"

void mx_islands_check(t_pathfinder *path) {
    char *buff = mx_strdup(path->string);

    path->num_of_islands = mx_atoi(buff);
    if (path->num_of_islands < 2) {
        write(2, "error: invalid number of islands\n", mx_strlen("error: invalid number of islands\n"));
        exit(1);
    }
        
    for (int i = 0; buff[i] != '\0'; i++) {
        buff[i] == ',' || buff[i] == '\n' ? (buff[i] = '-') : buff[i];
    }
        
    path->all_names_count = mx_count_words(buff,'-');
    path->islands = mx_strsplit(buff,'-');
    mx_islands(path);
    int line = 2;
    for (int i = 1; i < path->all_names_count; i +=3) {
        if (!mx_strcmp(path->islands[i + 1], path->islands[i])) {
            char *number = mx_itoa(line);
            write(2, "error: line ", mx_strlen("error: line "));
            write(2, number, mx_strlen(number)); 
            write(2, " is not valid\n", mx_strlen(" is not valid\n"));
            exit(1);
        }
        line++;
    }
    for (int i = 1; i < path->all_names_count; i += 3) {
        for (int j = i + 3; j < path->all_names_count; j += 3) {
            if (!mx_strcmp(path->islands[i], path->islands[j]) 
                || !mx_strcmp(path->islands[i], path->islands[j + 1])) {
                if (!mx_strcmp(path->islands[i + 1], path->islands[j + 1]) 
                    || !mx_strcmp(path->islands[i + 1], path->islands[j])) {
                    write(2, "error: duplicate bridges\n", mx_strlen("error: duplicate bridges\n"));
                    exit(1);
                }
            }
        }
    }
    mx_get_sum_of_bridges(path);
    
    free(buff);
    free(path->string);
}

