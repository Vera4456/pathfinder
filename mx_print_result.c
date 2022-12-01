#include "pathfinder.h"

void mx_print_result(t_pathfinder *path) {
    mx_pathfinder(path);
    int distance;
    int* route =(int*)malloc(sizeof(int) * (path->num_of_islands + 1));
    
    for (int i = 0; i < path->num_of_islands; i++) {
        for (int j = i + 1; j < path->num_of_islands; j++) {
            distance = 1;
            route[0] = j;
            route[1] = i;
            mx_shortest_route(path, route, distance);
        }
    }
    free(route);
}

