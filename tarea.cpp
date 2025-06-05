#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tarea{
    int beneficio;
    int p_limite;
    int indice;
};

bool comparar_beneficio(tarea &b1, tarea &b2) {
    return b1.beneficio > b2.beneficio;
}

void selec_tareas(vector<tarea> &conjunto, int tam) {
    sort(conjunto.begin(), conjunto.end(), comparar_beneficio);
    vector<tarea> res;
    vector<int> ocupado;
    
    for (int i = 0; i < tam; i++) {
        bool puede = true;
        for(int t = conjunto[i].p_limite; t >= 1; t--) {
            bool libre = true;
            for(int j = 0; j < ocupado.size(); j++) {
                if(ocupado[j] == t) {
                    libre = false;
                    break;
                }
            }
            if(libre) {
                res.push_back(conjunto[i]);
                ocupado.push_back(t);
                puede = false;
                break;
            }
        }
    }
    
    int b_total = 0;
    for (auto ele : res) {
        cout << ele.indice << " ";
        b_total += ele.beneficio;
    }
    cout << "\n" << b_total << "\n";
}

int main() {
    int n_tareas;
    cin >> n_tareas;
    vector<tarea> tareas(n_tareas);
    tarea my_t;
    int cont = 0;
    
    while (1) {
        cin >> my_t.beneficio;
        if (my_t.beneficio == 0) break;
        cin >> my_t.p_limite;
        tareas[cont] = my_t;
        tareas[cont].indice = cont+1;
        cont++;
    }
    
    selec_tareas(tareas, cont);
    return 0;
}
