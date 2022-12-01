#include "pathfinder.h"

void mx_pathfinder(t_pathfinder *path) {
    for (int i = 0; i < path->num_of_islands; i++) {
        for (int j = 0; j < path->num_of_islands; j++) {
            path->arr[i][j] = path->result_arr[i][j];
        }
    }
    for (int i = 1; i < path->num_of_islands + 1; i++) {
        for (int j = 0; j < path->num_of_islands; j++) {
            for (int k = 0; k < path->num_of_islands; k++) {
                if (path->result_arr[j][k] > path->result_arr[j][i - 1] + path->result_arr[i - 1][k] 
                && path->result_arr[j][i - 1] != INT_MAX && path->result_arr[i - 1][k] != INT_MAX) {
                    path->result_arr[j][k] = path->result_arr[j][i - 1] + path->result_arr[i - 1][k];
                }
            }
        }
    }
}

