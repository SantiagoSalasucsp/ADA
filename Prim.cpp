#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, vector<pair<int, int>>> grafo;

    grafo[0] = {{1, 7}, {2, 15}, {4, 10}};
    grafo[1] = {{3, 9}, {7, 12}, {6, 5}, {0, 7}};
    grafo[2] = {{0, 15}};
    grafo[3] = {{1, 9}};
    grafo[4] = {{0, 10}, {6, 8}, {5, 3}};
    grafo[5] = {{6, 14}, {4, 3}};
    grafo[6] = {{7, 6}, {1, 5}, {4, 8}, {5, 14}};
    grafo[7] = {{6, 6}, {1, 12}};

    set<int> visitados;
    set<pair<int, int>> cola;
    
    visitados.insert(0);
    for (auto& arista : grafo[0]) {
        cola.insert({arista.second, arista.first});
    }

    while (!cola.empty()) {
        auto minimo = *cola.begin();
        cola.erase(cola.begin());
        
        int peso = minimo.first;
        int vertice = minimo.second;
        
        if (visitados.count(vertice)) continue;
        
        cout << peso << "-> ";
        visitados.insert(vertice);
        
        for (auto& arista : grafo[vertice]) {
            int vecino = arista.first;
            int peso_arista = arista.second;
            
            if (!visitados.count(vecino)) {
                cola.insert({peso_arista, vecino});
            }
        }
    }

    return 0;
}


// Santiago Salas Sotillo
// Adrian Alvares MInaya 
