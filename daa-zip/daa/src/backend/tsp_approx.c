#include "tsp_approx.h"
#include "tsp_greedy.h"
#include <stdlib.h>

void tsp_approx(double** dist, int n, int* path, double* total_cost) {
    tsp_greedy(dist, n, path, total_cost);

    int improved = 1;
    while (improved) {
        improved = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int next_j = (j + 1) % n;
                
                double d1 = dist[path[i - 1]][path[i]] + dist[path[j]][path[next_j]];
                double d2 = dist[path[i - 1]][path[j]] + dist[path[i]][path[next_j]];

                if (d2 < d1 - 1e-9) { 
                    for (int k = 0; k <= (j - i) / 2; k++) {
                        int temp = path[i + k];
                        path[i + k] = path[j - k];
                        path[j - k] = temp;
                    }
                    improved = 1;
                }
            }
        }
    }

    *total_cost = 0.0;
    for (int i = 0; i < n - 1; i++) {
        *total_cost += dist[path[i]][path[i + 1]];
    }
    *total_cost += dist[path[n - 1]][path[0]];
}
