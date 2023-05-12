#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <vector>

#include "djikstra.h"
#include "floyd.h"

using namespace std;

void functions(void (*f)(int), int target) {
    auto start_timer = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    f(target);

    auto end_timer = chrono::high_resolution_clock::now();

    double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

    time_taken *= 1e-9;
    cout << " " << time_taken << setprecision(4) << endl;
}

int main() {
    {
        auto start_timer = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        auto end_timer = chrono::high_resolution_clock::now();

        double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

        time_taken *= 1e-9;
    }

    int graph[V][V] = { {0, 4, 9},
                        {4, 0, 5},
                        {9, 5, 0} };



    cout << "Dijkstra" << endl;
    {
        auto start_timer = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        dijkstra(graph, 0);

        auto end_timer = chrono::high_resolution_clock::now();

        double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

        time_taken *= 1e-9;
        cout << " " << time_taken << setprecision(4) << endl;
    }

    cout << "Floyd" << endl;
    {
        auto start_timer = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        floydWarshall(graph);

        auto end_timer = chrono::high_resolution_clock::now();

        double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

        time_taken *= 1e-9;
        cout << " " << time_taken << setprecision(4) << endl;
    }
}