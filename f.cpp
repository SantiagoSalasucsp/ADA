#include <iostream>
using namespace std;
#include <vector>


int suma(vector<int> y, int pos) {
    int suma = 0;


    for (int x = 0; x <= pos; x++) {
        suma += y[x];
    }
    return suma;

}

int main() {
    vector<int> numero = { 1, 3, 6, 8 };
       /* while (true) {
            int x;
            cin >> x;
            if (x == -1)
                break;
            numero.push_back(x);
        }*/
        vector<int> resultado;

        int ini = 0;
        int segun = 1;
        resultado.push_back(numero[ini]);
        while (true) {
            
            if (suma(numero, ini) < numero[segun]) {
                resultado.push_back(numero[segun]);
            }
            else {
                resultado[resultado.size() - 1] = numero[segun];
            }
            ini++;
            segun++;
            if (segun >= numero.size() ) {
                break;
            }
            
        }
        cout << endl;
        for (int f = 0; f < resultado.size() ;f++) {
            cout << resultado[f] << endl;
        }
}
