#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define INF numeric_limits<int>::max()
using namespace std;

void bellman_ford(vector<vector<pair<int, int>>>& adjList, int source, int destination) {
    int v = adjList.size();
    vector<int> dist(v, INF);
    vector<int> path(v, -1);

    dist[source] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (int u = 0; u < v; u++) {
            for (auto edge : adjList[u]) {
                int vertex = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[vertex]) {
                    dist[vertex] = dist[u] + weight;
                    path[vertex] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < v; u++) {
        for (auto edge : adjList[u]) {
            int vertex = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[vertex]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return;
            }
        }
    }

    // Display the path
    if (dist[destination] == INF) {
        cout << "No path exists from source to destination." << endl;
        return;
    }
    vector<int> pathVector;
    for (int at = destination; at != -1; at = path[at]) {
        pathVector.push_back(at);
    }
    reverse(pathVector.begin(), pathVector.end());

    cout << "Optimal Path using Bellman-Ford: ";
    for (size_t i = 0; i < pathVector.size(); i++) {
        cout << pathVector[i];
        if (i < pathVector.size() - 1) cout << " -> ";
    }
    cout << "\nTotal Cost: " << dist[destination] << endl;
}

int main() {
    int v = 7;
    vector<vector<pair<int, int>>> adjList(v);

    adjList[0].push_back({1, 1});
    adjList[1].push_back({0, 1});
    adjList[1].push_back({2, 1});
    adjList[1].push_back({4, 1});
    adjList[2].push_back({1, 1});
    adjList[2].push_back({3, 1});
    adjList[2].push_back({6, 1});
    adjList[3].push_back({2, 1});
    adjList[3].push_back({6, 1});
    adjList[4].push_back({1, 1});
    adjList[4].push_back({5, 1});
    adjList[5].push_back({4, 1});
    adjList[5].push_back({6, 1});
    adjList[6].push_back({2, 1});
    adjList[6].push_back({3, 1});
    adjList[6].push_back({5, 1});

    int source = 0; // Industrial Area
    int destination = 3; // Hotels
    bellman_ford(adjList, source, destination);

    return 0;
}
