#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

#define INT_MAX 2147483647

typedef struct s_pathfinder {
    int num_of_islands;
    int all_names_count;
    char *string;
    char **islands;
    char **island;
    int **arr;
    int **result_arr;
}              t_pathfinder;

int main(int argc, char *argv[]);
void mx_errors(t_pathfinder *path);
void mx_check_line(t_pathfinder *path, int line);
void mx_lines_check(t_pathfinder *path);
void mx_islands_check(t_pathfinder *path);
void mx_get_sum_of_bridges(t_pathfinder *path);
void mx_islands(t_pathfinder *path);
int mx_get_index_of_island(t_pathfinder *path, char *island);
void mx_fill_matrix(t_pathfinder *path);
void mx_pathfinder(t_pathfinder *path);
void mx_shortest_route(t_pathfinder *path, int* route, int distance);
void mx_print_result(t_pathfinder *path);

#endif
