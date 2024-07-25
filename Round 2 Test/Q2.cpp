// Write a function to find the shortest path from a source vertex to all other
// vertices in a graph using Dijkstra's algorithm.

#include <limits.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> dj(
    const unordered_map<int, unordered_map<int, int>>& graph, int source) {
    unordered_map<int, int> distance;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (const auto& node : graph) {
        distance[node.first] = INT_MAX;
    }

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distance[u])
            continue;

        for (auto& neighbor : graph.at(u)) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist + weight < distance[v]) {
                distance[v] = dist + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    // graph = {0: {1: 4, 2: 1}, 1: {3: 1}, 2: {1: 2, 3: 5}, 3: {}}, source = 0
    unordered_map<int, unordered_map<int, int>> graph = {
        {0, {{1, 4}, {2, 1}}}, {1, {{3, 1}}}, {2, {{1, 2}, {3, 5}}}, {3, {}}};

    int source = 0;

    unordered_map<int, int> result = dj(graph, source);

    for (const auto& ele : result) {
        cout << "Vertex : " << ele.first << " , Distance : " << ele.second
             << endl;
    }

    return 0;
}