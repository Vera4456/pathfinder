#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_pathfinder *path = (t_pathfinder*)malloc(sizeof(t_pathfinder));
    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", mx_strlen("usage: ./pathfinder [filename]\n"));
        exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "error: file ", mx_strlen("error: file "));
        write(2, argv[1], mx_strlen(argv[1]));
        write(2, " does not exist\n", mx_strlen(" does not exist\n"));
        free(path);
        exit(1);
    }
    char *buffer = mx_strnew(1);
    if (read(fd, buffer, 1) < 1) {
        write(2, "error: file ", mx_strlen("error: file "));
        write(2, argv[1], mx_strlen(argv[1]));
        write(2, " is empty\n", mx_strlen(" is empty\n"));
        free(path);
        exit(1);
        close(fd);
    }
    
    mx_strdel(&buffer);
    path->string = mx_file_to_str(argv[1]);
    close(fd);
    mx_errors(path);
    mx_fill_matrix(path);
    mx_print_result(path);
    mx_del_strarr(&path->island);
        for (int i = 0; i < path->num_of_islands; i++) {
            free(path->arr[i]);
    }
    free(path->arr);
    for (int i = 0; i < path->num_of_islands; i++){
            free(path->result_arr[i]);
    }
    free(path->result_arr);
    free(path);
}

