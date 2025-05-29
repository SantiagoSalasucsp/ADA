#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int n, W;
    int peso[MAX], valor[MAX];
    int dp[MAX + 1][MAX + 1];

    cout << "Cantidad de objetos: ";
    cin >> n;
    cout << "Peso maximo de la mochila: ";
    cin >> W;

    for (int i = 0; i < n; i++) {
        cout << "Peso del objeto " << i + 1 << ": ";
        cin >> peso[i];
        cout << "Valor del objeto " << i + 1 << ": ";
        cin >> valor[i];
    }

    // Programación dinámica
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (peso[i - 1] <= w) {
                dp[i][w] = max(valor[i - 1] + dp[i - 1][w - peso[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nValor maximo en la mochila: " << dp[n][W] << endl;

    // Mostrar qué objetos se usaron (opcional)
    cout << "Objetos incluidos (1 = sí, 0 = no): ";
    int res = dp[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            cout << "1 ";
            res -= valor[i - 1];
            w -= peso[i - 1];
        } else {
            cout << "0 ";
        }
    }
    cout << endl;

    return 0;
}
