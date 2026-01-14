#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& v, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (v[mid] == x)
            return mid;

        if (v[mid] > x)
            return binarySearch(v, l, mid - 1, x);

        return binarySearch(v, mid + 1, r, x);
    }
    return -1;
}

int main() {
    vector<int> v = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int x = 23;

    int res = binarySearch(v, 0, v.size() - 1, x);

    if (res == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << res;

    return 0;
}