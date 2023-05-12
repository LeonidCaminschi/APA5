#pragma once

#define V 5

void floydWarshall(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != 0
                        && dist[i][k] != 0))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}