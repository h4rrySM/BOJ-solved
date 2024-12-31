#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){ cin.tie(0)->sync_with_stdio(0);
    int m, ans = 0, l, r;
    vector<pii> v1;
    cin >> m;
    for(;;){
        cin >> l >> r;
        if(l == 0 && r == 0){
            break;
        }
        if(l > r){
            l += r;
            r = l - r;
            l -= r;
        }
        v1.push_back({l, r});
    }
    sort(v1.begin(), v1.end());
    int index = 0, lim = -1, point = 0;
    for(;;){
        lim = -1;
        for(; index < v1.size(); index++){
            if(v1[index].first <= point){
                lim = max(lim, v1[index].second);
            }else{
                break;
            }
        }
        ans++;
        if(lim >= m || lim == -1){
            cout << ans * (lim != -1) << '\n';
            break;
        }
        point = lim;
    }
    return 0;
}