#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 
using namespace std;

int maxcr(vector<int>& v,int l,int m,int h) {
    int sum = 0;
    int ls = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + v[i];
        if (sum > ls)
            ls = sum;
    }
    sum = 0;
    int rs = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + v[i];
        if (sum > rs)
            rs = sum;
    }
    return max(ls + rs, max(ls, rs));
}

int maxsubarr(vector<int>& v,int l,int h) {
    if (l == h)
        return v[l];
    int m = (l + h) / 2;
    return max(max(maxsubarr(v,l,m),
                   maxsubarr(v,m + 1,h)),
               maxcr(v,l,m,h));
}

int main() {
    vector<int> v = {-2,-5,6,-2,-3,1,5,-6};
    int max_sum = maxsubarr(v,0,v.size()- 1);
    cout <<"Max sum is : "<< max_sum;

    return 0;
}