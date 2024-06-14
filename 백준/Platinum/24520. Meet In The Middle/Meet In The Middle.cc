#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int link[100001][18] = {0,};
long long len[100001][18] = {0,};
int depth[100001] = {0,};
int lca(int a, int b){
    int t = depth[a] > depth[b] ? a : b;
    int s = a + b - t;
    a = t;
    b = s;
    int u = depth[a], v = depth[b], ans = -1;
    long long l = 0, l1 = 0, l2 = 0;
    for(int i = 17; i >= 0; i--){
        if(u - v >= (1<<i)){
            l += len[a][i];
            a = link[a][i];
            u = depth[a];
        }
    }
    if(a != b){
        for(int i = 17; i >= 0; i--){
            if(link[a][i] != link[b][i]){
                l += len[a][i] + len[b][i];
                a = link[a][i];
                b = link[b][i];
            }
        }
        l += len[a][0] + len[b][0];
        a = link[a][0];
    }
    if(l == 0){
        ans = t;
    }else if(l % 2 == 0){
        l /= 2;
        u = depth[t];
        v = depth[s];
        for(int i = 17; i >= 0; i--){
            if(u - depth[a] >= (1<<i) && l1 + len[t][i] <= l){
                l1 += len[t][i];
                t = link[t][i];
                u = depth[t];
                if(l1 == l){
                    ans = t;
                    break;
                }
            }
            if(v - depth[a] >= (1<<i) && l2 + len[s][i] <= l){
                l2 += len[s][i];
                s = link[s][i];
                v = depth[s];
                if(l2 == l){
                    ans = s;
                    break;
                }
            }
        }
    }
    return ans;
}
int main(){
    int n, k;
    int u, v, w;
    vector<pair<int, int>> g[100001];
    
    int q_item, visited_bfs[100001] = {0,};
    queue<int> q_bfs;
    
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < n-1; i++){
        scanf("%d %d %d", &u, &v ,&w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    q_bfs.push(1);
    visited_bfs[1] = 1;
    for(; !q_bfs.empty(); ){
        q_item = q_bfs.front();
        q_bfs.pop();
        for(int i = 0; i < (int)g[q_item].size(); i++){
            if(!visited_bfs[g[q_item][i].first]){
                q_bfs.push(g[q_item][i].first);
                visited_bfs[g[q_item][i].first] = 1;
                link[g[q_item][i].first][0] = q_item;
                len[g[q_item][i].first][0] = g[q_item][i].second;
                depth[g[q_item][i].first] = depth[q_item] + 1;
            }
        }
    }
    
    for(int i = 1; i <= 17; i++){
        for(int j = 1; j <= n; j++){
            link[j][i] = link[link[j][i-1]][i-1];
            len[j][i] = len[link[j][i-1]][i-1] + len[j][i-1];
        }
    }
    
    for(int i = 0; i < k; i++){
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u,v));
    }
    return 0;
}