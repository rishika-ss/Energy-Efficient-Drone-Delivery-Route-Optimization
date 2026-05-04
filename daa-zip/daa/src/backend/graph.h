#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    double x;
    double y;
} Point;

double calculate_distance(Point a, Point b);
double** create_distance_matrix(Point* points, int num_points);
void free_distance_matrix(double** matrix, int num_points);

#endif
