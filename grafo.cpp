#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct arista;
struct nodo{
    int val;
    
    nodo(int v){
        val = v;
    }
    vector<arista*> arr;
};

struct arista{
    int val;
    nodo* ptr;
    
    arista(int v, nodo* p){
        val = v;
        ptr = p;
    }
};

struct grafo{
    vector<nodo*> vec;
    
    void addnodo(int val){
        nodo* ptr = new nodo(val);
        vec.push_back(ptr);
    }
    
    void addarista(int val, nodo* a, nodo* b){
        arista* y = new arista(val, b);
        a->arr.push_back(y);
    }
    
    // Búsqueda BFS para encontrar camino entre dos nodos
    bool busqueda(nodo* inicio, nodo* destino){
        if(inicio == destino) return true;
        
        queue<nodo*> cola;
        unordered_set<nodo*> visitados;
        
        cola.push(inicio);
        visitados.insert(inicio);
        
        while(!cola.empty()){
            nodo* actual = cola.front();
            cola.pop();
            
            // Explorar todos los vecinos
            for(arista* arista_actual : actual->arr){
                nodo* vecino = arista_actual->ptr;
                
                if(vecino == destino){
                    return true;
                }
                
                if(visitados.find(vecino) == visitados.end()){
                    visitados.insert(vecino);
                    cola.push(vecino);
                }
            }
        }
        return false;
    }
    
    // Imprimir el grafo
    void imprimir(){
        for(int i = 0; i < vec.size(); i++){
            cout << "Nodo " << vec[i]->val << " -> ";
            for(arista* a : vec[i]->arr){
                cout << "[" << a->val << "]-> " << a->ptr->val << " ";
            }
            cout << endl;
        }
    }
    
    // Buscar nodo por valor
    nodo* buscarNodo(int valor){
        for(nodo* n : vec){
            if(n->val == valor) return n;
        }
        return nullptr;
    }
    
    // Destructor para liberar memoria
    ~grafo(){
        for(nodo* n : vec){
            for(arista* a : n->arr){
                delete a;
            }
            delete n;
        }
    }
};

int main(){
    grafo x;
    x.addnodo(1);
    x.addnodo(2);
    x.addnodo(3);
    x.addnodo(4);
    
    x.addarista(10, x.vec[0], x.vec[1]); // 1 -> 2 (peso 10)
    x.addarista(20, x.vec[0], x.vec[2]); // 1 -> 3 (peso 20)
    x.addarista(40, x.vec[2], x.vec[3]); // 3 -> 4 (peso 40)
    
    cout << "Estructura del grafo:" << endl;
    x.imprimir();
    
    cout << "\nBúsquedas:" << endl;
    cout << "¿Existe camino de 1 a 4? " << (x.busqueda(x.vec[0], x.vec[3]) ? "Sí" : "No") << endl;
    cout << "¿Existe camino de 2 a 4? " << (x.busqueda(x.vec[1], x.vec[3]) ? "Sí" : "No") << endl;
    cout << "¿Existe camino de 4 a 1? " << (x.busqueda(x.vec[3], x.vec[0]) ? "Sí" : "No") << endl;
    
    return 0;
}
