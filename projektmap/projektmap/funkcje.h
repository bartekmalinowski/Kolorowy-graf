/**

@file funkcje.h
@brief Plik nagłówkowy zawierający deklaracje funkcji dla kolorowania grafów.
*/

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <fstream>
#include <string>
#include <map>
#include <vector>

/**

@brief Reprezentuje graf jako mapę, w której klucze to wierzchołki, a wartości to listy sąsiedztwa.
*/
typedef std::map<int, std::vector<int>> Graph;
/**

@brief Wczytuje graf z pliku i zapisuje go w postaci mapy.
@param infile strumień wejściowy do pliku.
@param graph mapa reprezentująca graf.
@return true, jeśli udało się poprawnie wczytać graf, false w przeciwnym razie.
*/
bool read_graph(std::ifstream& infile, Graph& graph);
/**

@brief Koloruje graf i zapisuje wynik w postaci mapy, w której klucze to wierzchołki, a wartości to kolory.
@param graph mapa reprezentująca graf.
@param coloring mapa reprezentująca kolorowanie grafu.
@return true, jeśli udało się poprawnie pokolorować graf, false w przeciwnym razie.
*/
bool color_graph(const Graph& graph, std::map<int, int>& coloring);
/**

@brief Zapisuje kolorowanie grafu do pliku.
@param outfile strumień wyjściowy do pliku.
@param coloring mapa reprezentująca kolorowanie grafu.
@return true, jeśli udało się poprawnie zapisać kolorowanie grafu do pliku, false w przeciwnym razie.
*/
bool write_coloring(std::ofstream& outfile, const std::map<int, int>& coloring);

#endif