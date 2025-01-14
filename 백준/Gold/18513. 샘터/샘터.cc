#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int a, n, k, dx[2] = {-1, 1};
    ll res = 0, sad = 1;
    queue<int> q;
    unordered_map<int, bool> um;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        q.push(a);
        um[a] = true;
    }
    for(; !q.empty(); ){
        int t = q.size();
        for(int i = 0; i < t; i++){
            int f = q.front();
            q.pop();
            for(int d: dx){
                int x = d + f;
                if(um[x]){
                    continue;
                }
                um[x] = true;
                q.push(x);
                res += sad;
                k--;
                if(k == 0){
                    cout << res;
                    return 0;
                }
            }
        }
        sad++;
    }
    cout << res;
    return 0;
}