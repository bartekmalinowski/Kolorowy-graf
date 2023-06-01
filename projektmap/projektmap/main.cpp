#include <iostream>
#include <fstream>
#include "funkcje.h"

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " -g input_file -k output_file" << std::endl;
        return 1;
    }

    std::string input_file = "";
    std::string output_file = "";

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-g") {
            input_file = argv[i + 1];
            i++;
        }
        else if (std::string(argv[i]) == "-k") {
            output_file = argv[i + 1];
            i++;
        }
    }

    std::ifstream infile(input_file);
    if (!infile) {
        std::cout << "Error podczas otwierania pliku wejściowego: " << input_file << std::endl;
        return 1;
    }

    std::ofstream outfile(output_file);
    if (!outfile) {
        std::cout << "Error podczas otwierania pliku wyjściowego: " << output_file << std::endl;
        return 1;
    }

    Graph graph;

    if (!read_graph(infile, graph)) {
        std::cout << "Error przy czytaniu grafu z pliku wejsciowego!" << std::endl;
        return 1;
    }

    std::map<int, int> coloring;
    if (!color_graph(graph, coloring)) {
        std::cout << "Error przy kolorowaniu grafu!" << std::endl;
        return 1;
    }

    if (!write_coloring(outfile, coloring)) {
        std::cout << "Error wypisywania do pliku wyjsciowego!" << std::endl;
        return 1;
    }

    return 0;
}
