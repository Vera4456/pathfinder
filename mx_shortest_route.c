#include "pathfinder.h"

void mx_shortest_route(t_pathfinder *path, int* route, int distance) {

    for (int i = 0; i < path->num_of_islands; i++) {
        if (i != route[distance]
            && (path->arr[route[distance]][i] == path->result_arr[route[distance]][route[0]] 
            - path->result_arr[i][route[0]])) {
            distance++;
            route[distance] = i;
            mx_shortest_route(path, route, distance);
            distance--;
        }
    }
    
    if (route[distance] != route[0]) {
        return;
    }
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path->island[route[1]]);
    mx_printstr(" -> ");
    mx_printstr(path->island[route[0]]);
    mx_printstr("\n");
    
    mx_printstr("Route: ");    
    for (int i = 1; i < distance + 1; i++) {
        mx_printstr(path->island[route[i]]);
        
        if (i + 1 < distance + 1) 
            mx_printstr(" -> ");
    }
    mx_printstr("\n");
        int sum = 0;
    
    mx_printstr("Distance: ");
    for (int i = 1; i < distance; i++) {
        mx_printint(path->arr[route[i]][route[i + 1]]);
        sum += path->arr[route[i]][route[i + 1]];
        
        if (i < distance - 1) 
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_printstr("========================================\n");
}

