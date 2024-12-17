#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, k, r = 0;
    cin >> k >> n;
    if(k <= 2){
        r = n - 1;
    }else{
        for(int i = 1; i <= n; i++){
            r += gcd(i, k) < 3;
        }
    }
    cout << r;
    return 0;
}