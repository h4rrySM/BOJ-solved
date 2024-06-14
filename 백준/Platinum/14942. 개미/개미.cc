#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int link[100001][18] = {0,};
long long len[100001][18] = {0,};
int depth[100001] = {0,};
int energy[100001] = {0,};
int room(int a){
    int t = a;
    int u = depth[a];
    long long l = 0, l1 = 0, l2 = 0;
    for(int i = 17; i >= 0; i--){
        if(u >= (1<<i) && l + len[a][i] <= energy[t]){
            l += len[a][i];
            a = link[a][i];
            u = depth[a];
        }
    }
    return a;
}
int main(){
    int n, k;
    int u, v, w;
    vector<pair<int, int>> g[100001];
    
    int q_item, visited_bfs[100001] = {0,};
    queue<int> q_bfs;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &energy[i]);
    }
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
        for(int i = 0; i < g[q_item].size(); i++){
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
    
    for(int i = 1; i <= n; i++){
        printf("%d\n", room(i));
    }
    return 0;
}