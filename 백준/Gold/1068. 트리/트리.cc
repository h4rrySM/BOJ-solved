#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g_down[50];
int g_leaf[50] = {0, }, g_up[50];
int leafs_update(int a){
    g_leaf[a]++;
    if(g_up[a] != -1){
        leafs_update(g_up[a]);
    }
    return 0;
}
int main(){
    int n, k, root, r;
    fill_n(g_up, 50, -1);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if(k == -1){
            root = i;
        }else{
            g_down[k].push_back(i);
            g_up[i] = k;
        }
    }
    scanf("%d", &r);
    for(int i = 0; i < n; i++){
        if(g_down[i].size() == 0){
            leafs_update(i);
        }
    }
    printf("%d", g_leaf[root] - g_leaf[r] + (g_down[g_up[r]].size() == 1));
    return 0;
}