#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void max_cont(int max_k, vector<int> &containers,vector<int>& res) {
    sort(containers.begin(), containers.end());
    int sum = 0;
    for (int i = 0; sum + containers[i] <= max_k; i++) {
            res.push_back(i);
            sum += containers[i];
    }
}

int main(){
    vector<int> containers{13,41,15,61,20,21};
    vector<int> res;
    int k = 100;
    max_cont(100, containers, res);

    cout << "se eligieron: ";
    for (int i = 0; i < res.size(); i++)
        cout << "( C" << res[i] << ":" << containers[res[i]]<<") ";
    
}

