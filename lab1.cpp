#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    int inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inversionCount;
}

int preferences(vector<int>& vec, int ini, int end) {
    if (ini >= end)
        return 0;

    int mid = (ini + end) / 2;
    int a = preferences(vec, ini, mid);
    int b = preferences(vec, mid + 1, end);
    int res = merge(vec, ini, mid, end);
    return a + b + res;
}

int main() {
    vector<int> wenas1{1,5,4,8,10,2,6,9,12,11,3,7};
    cout<<preferences(wenas1,0,wenas1.size()-1)<<endl;

    vector<int> wenas2{3,7,10,14,18,19,2,11,16,17,23,25};
    cout<<preferences(wenas2,0,wenas2.size()-1)<<endl;

}
