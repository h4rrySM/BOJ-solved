#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int h, w, s = 0;
    vector<int> a;
    cin >> h >> w;
    a.resize(w);
    for(int &i: a){
        cin >> i;
    }
    for(int i = 1; i < w - 1; i++){
        int l = 0, r = 0;
        for(int j = i - 1; j >= 0; j--){
            l = l > a[j] ? l : a[j];
        }
        for(int j = i + 1; j < w; j++){
            r = r > a[j] ? r : a[j];
        }
        l = l < r ? l : r;
        s += (l - a[i]) * (l > a[i]);
    }
    cout << s;
    return 0;
}