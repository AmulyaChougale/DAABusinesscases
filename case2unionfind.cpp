#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct subset {
    int parent;
    int rank;
};

int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void KruskalMST(Graph& graph) {
    vector<Edge> result;
    int V = graph.V;
    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    int e = 0;
    int i = 0;

    while (e < V - 1 && i < graph.edges.size()) {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    cout << "Edges in the MST:\n";
    for (i = 0; i < result.size(); ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
}

int main() {
    Graph graph;
    graph.V = 7;
    graph.E = 9;

    graph.edges.push_back({0, 1, 50});
    graph.edges.push_back({1, 2, 20});
    graph.edges.push_back({2, 3, 30});
    graph.edges.push_back({0, 4, 40});
    graph.edges.push_back({1, 4, 40});
    graph.edges.push_back({4, 5, 60});
    graph.edges.push_back({5, 3, 20});
    graph.edges.push_back({2, 6, 40});
    graph.edges.push_back({6, 3, 25});

    KruskalMST(graph);

    return 0;
}
