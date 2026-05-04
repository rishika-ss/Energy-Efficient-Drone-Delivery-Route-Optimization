#include "graph.h"
#include <math.h>
#include <stdlib.h>

double calculate_distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double** create_distance_matrix(Point* points, int num_points) {
    double** matrix = (double**)malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        matrix[i] = (double*)malloc(num_points * sizeof(double));
        for (int j = 0; j < num_points; j++) {
            if (i == j) {
                matrix[i][j] = 0.0;
            } else {
                matrix[i][j] = calculate_distance(points[i], points[j]);
            }
        }
    }
    return matrix;
}

void free_distance_matrix(double** matrix, int num_points) {
    for (int i = 0; i < num_points; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
