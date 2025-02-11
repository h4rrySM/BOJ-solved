#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if(n < 2 * k){
        cout << "NIE\n";
        return 0;
    }
    vi result;
    if(n & 1){
        for(int i = 1; i <= n / 2; i++){
            result.push_back(n / 2 + i);
            result.push_back(i);
        }
        result.push_back(n);
    }else{
        for(int i = 1; i <= n / 2; i++){
            result.push_back(n / 2 + i);
            result.push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    return 0;
}

