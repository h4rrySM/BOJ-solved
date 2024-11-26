#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
int link[40001][17][3] = {0,}, visited[40001] = {0,};
vector<pii> g[40001];
int dfs(int a){
    int l = g[a].size();
    visited[a] = 1;
    for(int i = 0; i < l; i++){
        if(!visited[g[a][i].first]){
            link[g[a][i].first][0][0] = a;
            link[g[a][i].first][0][1] = link[a][0][1] + 1;
            link[g[a][i].first][0][2] = g[a][i].second;
            dfs(g[a][i].first);
        }
    }
    return 0;
}
int lca(int a, int b){
    int u, v, d = 0;
    u = link[a][0][1] < link[b][0][1] ? b : a;
    b = a + b - u;
    a = u;
    u = link[a][0][1];
    v = link[b][0][1];
    for(int i = 16; i >= 0; i--){
        if(u - v >= (1<<i)){
            d += link[a][i][2];
            a = link[a][i][0];
            u = link[a][0][1];
        }
    }
    for(int i = 16; i >= 0; i--){
        if(link[a][i][0] != link[b][i][0]){
            d += (link[a][i][2] + link[b][i][2]);
            a = link[a][i][0];
            b = link[b][i][0];
        }
    }
    return a == b ? d : d + link[a][0][2] + link[b][0][2];
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, m, a, b, c;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfs(1);
    for(int i = 1; i <= 16; i++){
        for(int j = 1; j <= n; j++){
            link[j][i][0] = link[link[j][i-1][0]][i-1][0];
            link[j][i][2] = link[j][i-1][2] + link[link[j][i-1][0]][i-1][2];
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}