#include "tsp_exact.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void solve_exact(double** dist, int n, int* current_path, int* visited, int pos, double current_cost, int* best_path, double* min_cost) {
    if (pos == n) {
        double total_cost = current_cost + dist[current_path[pos - 1]][current_path[0]];
        if (total_cost < *min_cost) {
            *min_cost = total_cost;
            for (int i = 0; i < n; i++) {
                best_path[i] = current_path[i];
            }
        }
        return;
    }

    if (current_cost >= *min_cost) return;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            current_path[pos] = i;
            solve_exact(dist, n, current_path, visited, pos + 1, current_cost + dist[current_path[pos - 1]][i], best_path, min_cost);
            visited[i] = 0;
        }
    }
}

void tsp_exact(double** dist, int n, int* best_path, double* min_cost) {
    int* current_path = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    *min_cost = DBL_MAX;
    
    current_path[0] = 0;
    visited[0] = 1;

    solve_exact(dist, n, current_path, visited, 1, 0.0, best_path, min_cost);

    free(current_path);
    free(visited);
}
