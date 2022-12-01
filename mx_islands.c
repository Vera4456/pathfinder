#include "pathfinder.h"

void mx_islands(t_pathfinder *path) {
    int counter = 1;

    path->island = (char**)malloc(sizeof(char*) * path->all_names_count);
    path->island[0] = mx_strdup(path->islands[1]);
    
    for (int i = 1; i < path->all_names_count; i++) {
        if (mx_isdigit(path->islands[i][0])) {
            continue;
        }
            
        for (int j = 0; j < counter; j++) {
            if (!mx_strcmp(path->island[j], path->islands[i]))
                break;
            if (j == counter - 1) {
                path->island[counter++] = mx_strdup(path->islands[i]);
            }
        }
    }
    if (counter != path->num_of_islands) {
        write(2, "error: invalid number of islands\n", mx_strlen("error: invalid number of islands\n"));
        exit(1);
    }
}

