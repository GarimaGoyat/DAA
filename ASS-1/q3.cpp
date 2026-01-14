#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& v,int l,int h) {
    int pivot = v[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[h]);
    return (i + 1);
}

void quickSort(vector<int>& v,int l,int h) {
    if (l < h) {
        int pi = partition(v,l,h);
        quickSort(v,l,pi - 1);
        quickSort(v,pi+1,h);
    }
}

int main() {
    vector<int> v = {4,2,6,9,2};

    quickSort(v,0,v.size()- 1);

    cout << "Sorted array: ";
    for (int x : v)
        cout << x << " ";
    
    return 0;
}