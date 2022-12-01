#include "pathfinder.h"

void mx_get_sum_of_bridges(t_pathfinder *path) {
    long sum = 0;

    for (int i = 1; i < path->all_names_count; i++) {
        if (mx_isdigit(path->islands[i][0]))
            sum += mx_atoi(path->islands[i]);
            
        if (sum > INT_MAX) {
            write(2, "error: sum of bridges lengths is too big\n", mx_strlen("error: sum of bridges lengths is too big\n"));
            exit(1);
        }
    }
}

