#include "tsp_greedy.h"
#include <stdlib.h>
#include <float.h>

void tsp_greedy(double** dist, int n, int* path, double* total_cost) {
    int* visited = (int*)calloc(n, sizeof(int));
    *total_cost = 0.0;
    
    int current_node = 0;
    path[0] = 0;
    visited[0] = 1;

    for (int i = 1; i < n; i++) {
        int next_node = -1;
        double min_dist = DBL_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current_node][j] < min_dist) {
                min_dist = dist[current_node][j];
                next_node = j;
            }
        }

        path[i] = next_node;
        visited[next_node] = 1;
        *total_cost += min_dist;
        current_node = next_node;
    }

    *total_cost += dist[current_node][path[0]];

    free(visited);
}
