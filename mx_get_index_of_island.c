#include "pathfinder.h"

int mx_get_index_of_island(t_pathfinder *path, char *island) {
    for (int i = 0; i < path->num_of_islands; i++)
        if (mx_strcmp(island, path->island[i]) == 0)
            return i;
    
    return 0;
}

