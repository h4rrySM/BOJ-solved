#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, k, s = 0;
    vector<int> v;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    v.resize(n);
    for(int &i: v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    k = n * 0.15 + 0.5;
    for(int i = k; i < n - k; i++){
        s += v[i];
    }
    s = s / (double)(n - 2*k) + 0.5;
    cout << s;
    return 0;
}