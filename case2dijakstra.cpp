#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 9999
using namespace std;

class dijkstra {
public:
    int dist[50];
    int path[50];
    int visited[50] = {0};
    int v;
    int src;
    vector<string> vertexNames;

    void initialize(int cost[50][50]);
    void calculate(int cost[50][50]);
    void displayPath(int destination);
    void displayNames();
};

void dijkstra::initialize(int cost[50][50]) {
    for (int i = 0; i < v; i++) {
        path[i] = src;
        dist[i] = cost[src][i];
        visited[i] = 0;
    }
    visited[src] = 1;
}

void dijkstra::calculate(int cost[50][50]) {
    for (int i = 1; i < v; i++) {
        int min_dist = MAX;
        int u = -1;
        // Find the unvisited vertex with the minimum distance
        for (int j = 0; j < v; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // If no vertex is left to process
        visited[u] = 1;

        // Update the distances of adjacent vertices
        for (int k = 0; k < v; k++) {
            if (!visited[k] && cost[u][k] != MAX && dist[u] + cost[u][k] < dist[k]) {
                dist[k] = dist[u] + cost[u][k];
                path[k] = u;
            }
        }
    }
}

void dijkstra::displayPath(int destination) {
    if (dist[destination] == MAX) {
        cout << "No path exists from source to destination." << endl;
        return;
    }
    cout << "Shortest Path from " << vertexNames[src] << " to " << vertexNames[destination] << ": ";
    int curr = destination;

    vector<int> pathVector;
    while (curr != src) {
        pathVector.push_back(curr);
        curr = path[curr];
    }
    pathVector.push_back(src);
    reverse(pathVector.begin(), pathVector.end());

    for (int node : pathVector) {
        cout << vertexNames[node] << " ->";
    }
    cout << "\nTotal Cost: " << dist[destination] << endl;
}

void dijkstra::displayNames() {
    vertexNames = {
        "Industrial Area",
        "City Circle",
        "Rural Area",
        "Hotels",
        "Bus Stand",
        "Police Station",
        "Police Headquarters"
    };

    // Print out the names of the vertices for reference
    cout << "Vertex Information:" << endl;
    for (int i = 0; i < vertexNames.size(); i++) {
        cout << i << " -> " << vertexNames[i] << endl;
    }
}

int main()
{
    int cost[50][50] = {
        {0, 50, MAX, MAX, MAX, MAX, MAX},  // Industrial Area to City Circle
        {50, 0, 20, MAX, 40, MAX, MAX},   // City Circle to Rural Area, Bus Stand
        {MAX, 20, 0, 30, MAX, MAX, 40},   // Rural Area to Hotels, Police Headquarters
        {MAX, MAX, 30, 0, MAX, MAX, 25},  // Hotels to Police Headquarters
        {MAX, 40, MAX, MAX, 0, 60, MAX},  // Bus Stand to Police Station
        {MAX, MAX, MAX, MAX, 60, 0, 20},  // Police Station to Hotels
        {MAX, MAX, 40, 25, MAX, 20, 0}    // Police Headquarters to Hotels
    };
    dijkstra d;
    d.v = 7;

    d.displayNames();

    cout << "Enter the source vertex (0-indexed): ";
    cin >> d.src;

    d.initialize(cost);
    d.calculate(cost);

    int destination;
    cout << "Enter the destination vertex (0-indexed): ";
    cin >> destination;

    d.displayPath(destination);

    return 0;
}
