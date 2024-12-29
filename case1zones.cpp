#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

void bfs(int m[10][10], int v, int source, int destination, vector<int>& path, vector<string>& vertexNames) {
    int queue[20];
    int front = 0, rear = 0, u, i;
    int visited[10] = {0};
    int parent[10] = {-1};

    for (i = 0; i < v; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    queue[rear] = source;
    visited[source] = 1;

    while (front <= rear) {
        u = queue[front];
        front++;

        for (i = 0; i < v; i++) {
            if (m[u][i] == 1 && !visited[i]) {
                visited[i] = 1;
                parent[i] = u;
                rear++;
                queue[rear] = i;

                // If we reach the destination, reconstruct the path and return
                if (i == destination) {
                    int curr = i;
                    while (curr != -1) {
                        path.push_back(curr);
                        curr = parent[curr];
                    }
                    reverse(path.begin(), path.end());
                    return;
                }
            }
        }
    }
}

int main() {
    // First zone
    int v1 = 6;
    int m1[10][10] = {
        {0, 1, 0, 0, 1, 0}, // Tank2 to Bus Stand, Industrial Area
        {1, 0, 1, 0, 0, 0}, // Bus Stand to Industrial Area
        {0, 1, 0, 1, 0, 1}, // Industrial Area to Hospital
        {0, 0, 1, 0, 0, 0}, // Hospital to Industrial Area
        {1, 0, 0, 0, 0, 0}, // Tank2 to Industrial Area
        {0, 0, 1, 0, 0, 0}  // Industrial Area to Hospital
    };

    vector<string> vertexNames1 = {
        "Tank2", "Bus Stand", "Industrial Area", "Hospital", "Residential Area", "Water Tank 2"
    };

    vector<int> path1_1, path1_2;
    bfs(m1, v1, 0, 3, path1_1, vertexNames1);

    m1[0][4] = 1;
    m1[4][3] = 1;
    bfs(m1, v1, 0, 3, path1_2, vertexNames1);

    vector<int> optimalPath1 = (path1_1.size() <= path1_2.size()) ? path1_1 : path1_2;

    cout << "The optimal path for Zone 1 is: ";
    for (size_t i = 0; i < optimalPath1.size(); ++i) {
        cout << vertexNames1[optimalPath1[i]];
        if (i < optimalPath1.size() - 1) cout << " -> ";
    }
    cout << endl;

    // Second zone
    int v2 = 5;
    int m2_1[10][10] = {
        {0, 1, 1, 0, 0}, // Tank3 to Rural Area, Hotels
        {1, 0, 0, 0, 0}, // Rural Area (Destination)
        {1, 0, 0, 1, 0}, // Hotels to Rural Area
        {0, 0, 1, 0, 1}, // Hotels to Rural Area
        {0, 0, 0, 1, 0}  // Hi-Tech City to Rural Area
    };

    int m2_2[10][10] = {
        {0, 1, 0, 1, 0}, // Tank3 to Hotels
        {1, 0, 1, 0, 0}, // Hotels to Rural Area
        {0, 1, 0, 1, 0}, // Rural Area (Destination)
        {1, 0, 1, 0, 0}, // City Circle to Rural Area
        {0, 1, 1, 0, 0}  // Rural Area (Destination)
    };

    vector<string> vertexNames2 = {
        "Tank3", "Rural Area", "Hotels", "Hi-Tech City", "City Circle"
    };

    vector<int> path2_1, path2_2;
    bfs(m2_1, v2, 0, 1, path2_1, vertexNames2);
    bfs(m2_2, v2, 0, 1, path2_2, vertexNames2);

    vector<int> optimalPath2 = (path2_1.size() <= path2_2.size()) ? path2_1 : path2_2;

    cout << "The optimal path for Zone 2 is: ";
    for (size_t i = 0; i < optimalPath2.size(); ++i) {
        cout << vertexNames2[optimalPath2[i]];
        if (i < optimalPath2.size() - 1) cout << " -> ";
    }
    cout << endl;

    // Third zone
    int v3 = 4;
    int m3_1[10][10] = {
        {0, 1, 0, 0}, // Tank1 to IT Sector
        {1, 0, 1, 0}, // IT Sector (Destination)
        {0, 1, 0, 1}, // University to IT Sector
        {0, 0, 1, 0}  // University to IT Sector
    };

    int m3_2[10][10] = {
        {0, 0, 1, 0}, // Tank1 to University
        {0, 0, 1, 1}, // University to IT Sector
        {1, 1, 0, 0}, // IT Sector to University
        {0, 1, 0, 0}  // University to IT Sector
    };

    vector<string> vertexNames3 = {
        "Tank1", "IT Sector", "University", "Industrial Area"
    };

    vector<int> path3_1, path3_2;
    bfs(m3_1, v3, 0, 1, path3_1, vertexNames3);
    bfs(m3_2, v3, 0, 1, path3_2, vertexNames3);

    vector<int> optimalPath3 = (path3_1.size() <= path3_2.size()) ? path3_1 : path3_2;

    cout << "The optimal path for Zone 3 is: ";
    for (size_t i = 0; i < optimalPath3.size(); ++i) {
        cout << vertexNames3[optimalPath3[i]];
        if (i < optimalPath3.size() - 1) cout << " -> ";
    }
    cout << endl;

    return 0;
}
