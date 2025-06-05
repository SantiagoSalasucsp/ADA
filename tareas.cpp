#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct tarea{
	int beneficio;
	int p_limite;
	int indice;
};


struct xd{
	int promedio;
	vector <int> id;

};


bool comparar_beneficio(tarea &b1, tarea &b2) {
	return b1.beneficio > b2.beneficio;
}


void selec_tareas(vector<tarea> &conjunto) {
	sort(conjunto.begin(), conjunto.end(), comparar_beneficio);
	vector<tarea> res;
	set <int> descartar;
	for (int i = 0; i < conjunto.size(); i++) {
		if (descartar.count(conjunto[i].p_limite) == 0) {
			res.push_back(conjunto[i]);
			descartar.insert(conjunto[i].p_limite);
		}
	}

	int b_total = 0;
	cout << "las tareas seleccionadas fueron: ";
	for (auto ele : res) {
		cout << ele.indice<<" ";
		b_total += ele.beneficio;
	}
	cout << "\nel beneficio total es:" << b_total<<"\n";
}

int main() {
	cout << "n: ";
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
	system("cls");
	cont = 1;


	for (auto ele : tareas)
		cout <<"t"<<cont++<<": " << ele.beneficio << ", " << ele.p_limite << "\n";
	
	selec_tareas(tareas);

}

