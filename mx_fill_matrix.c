#include "pathfinder.h"

void mx_fill_matrix(t_pathfinder *path) {
    int a;
    int b;
    
    path->arr = (int**)malloc(sizeof(int*) * path->num_of_islands);
    path->result_arr = (int**)malloc(sizeof(int*) * path->num_of_islands);
    for (int i = 0; i < path->num_of_islands; i++) {
        path->arr[i] = (int*)malloc(sizeof(int*) * path->num_of_islands);
        path->result_arr[i] = (int*)malloc(sizeof(int*) * path->num_of_islands);
        for (int j = 0; j < path->num_of_islands; j++) {
            if (i != j) {
                path->result_arr[i][j] = INT_MAX;
            }
            else {
                path->result_arr[i][j] = 0;
            }
        }
    }
    int i = 1;
    while (i != path->all_names_count) {
        a = mx_get_index_of_island(path, path->islands[i]);
        b = mx_get_index_of_island(path, path->islands[i + 1]);
        path->result_arr[a][b] = mx_atoi(path->islands[i + 2]);
        path->result_arr[b][a] = mx_atoi(path->islands[i + 2]);
        i+=3;
    }
    mx_del_strarr(&path->islands);
}

