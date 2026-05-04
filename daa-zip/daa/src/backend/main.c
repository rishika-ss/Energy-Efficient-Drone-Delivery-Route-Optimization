#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "graph.h"
#include "energy_model.h"
#include "tsp_exact.h"
#include "tsp_greedy.h"
#include "tsp_approx.h"

int main() {
    char algo[20];
    double payload_weight;
    int n;

    if (scanf("%19s", algo) != 1) return 1;
    if (scanf("%lf", &payload_weight) != 1) return 1;
    if (scanf("%d", &n) != 1) return 1;

    if (n < 2) {
        printf("{\"error\": \"Need at least 2 points\"}\n");
        return 1;
    }

    Point* points = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        if (scanf("%lf %lf", &points[i].x, &points[i].y) != 2) return 1;
    }

    double** dist = create_distance_matrix(points, n);

    int* path = (int*)malloc(n * sizeof(int));
    double cost = 0.0;

    LARGE_INTEGER start_time, end_time, freq;
QueryPerformanceFrequency(&freq);
QueryPerformanceCounter(&start_time);

    if (strcmp(algo, "exact") == 0) {
        if (n > 12) {
            printf("{\"error\": \"Exact algorithm is too slow for n > 12\"}\n");
            return 1;
        }
        tsp_exact(dist, n, path, &cost);
    } else if (strcmp(algo, "approx") == 0) {
        tsp_approx(dist, n, path, &cost);
    } else { 
        tsp_greedy(dist, n, path, &cost);
    }

   QueryPerformanceCounter(&end_time);
double time_taken = (double)(end_time.QuadPart - start_time.QuadPart) * 1000.0 / freq.QuadPart;

    double energy = calculate_total_energy(cost, payload_weight);

    printf("{\n");
    printf("  \"algorithm\": \"%s\",\n", algo);
    printf("  \"distance\": %f,\n", cost);
    printf("  \"energy\": %f,\n", energy);
    printf("  \"time_ms\": %f,\n", time_taken);
    printf("  \"path\": [");
    for (int i = 0; i < n; i++) {
        printf("%d", path[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    printf("}\n");

    free_distance_matrix(dist, n);
    free(points);
    free(path);

    return 0;
}
