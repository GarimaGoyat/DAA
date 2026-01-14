#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}
void print(vector<int>& v) {
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
int main() {
    vector<int> v1 = {12, 11, 13, 5, 6, 7};
    vector<int> v2 = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(v1, 0, v1.size() - 1);
    cout << "Sorted array 1: ";
    print(v1);
    mergeSort(v2, 0, v2.size() - 1);
    cout << "Sorted array 2: ";
    print(v2);

    return 0;
}