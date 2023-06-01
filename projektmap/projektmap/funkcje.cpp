#include "funkcje.h"

bool read_graph(std::ifstream& infile, Graph& graph) {
    char c;
    int u, v;
    while (infile >> c >> u >> c >> v >> c) {
        graph[u].push_back(v);
        graph[v].push_back(u);
        infile >> c;
    }
    return true;
}

bool color_graph(const Graph& graph, std::map<int, int>& coloring) {
    for (auto it = graph.begin(); it != graph.end(); it++) { 
        int node = it->first;
        int color = 1;
        while (true) {
            bool can_color = true;
            for (int neighbor : it->second) {
                if (coloring[neighbor] == color) {
                    can_color = false;
                    break;
                }
            }
            if (can_color) {
                coloring[node] = color;
                break;
            }
            color++;
        }
    }
    return true;
}

bool write_coloring(std::ofstream& outfile, const std::map<int, int>& coloring) {
    for (auto it = coloring.begin(); it != coloring.end(); it++) {
        outfile << "Wierzcholek " << it->first << " jest pokolorowany na kolor: " << it->second << std::endl;
    }
    return true;
}
