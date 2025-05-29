#include <iostream>
#include <vector>

int coins(std::vector<int> &set, std::vector<int> &res) {
	int sum = 0;
	int cont = 0;
	for (int i = 0; i < set.size() - 1; i++) {
		if (sum + set[i] < set[i + 1]) {
			sum += set[i];
			cont++;
			res.push_back(set[i]);
		}
	}
	cont++;
	res.push_back(set.back());
	return cont;
}


int main() {
	std::vector<int> vec{ 2,6,8 };
	std::vector<int> res;

	std::cout << coins(vec, res) << ", los valores son : \n[";
	for (auto ele : res)
		std::cout << ele << " ";
	std::cout << "]";
}
