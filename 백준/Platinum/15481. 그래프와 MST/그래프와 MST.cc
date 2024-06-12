#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int p[200001]={0,},link[200001][18][3]={0,};
int find_p(int a){
    p[a] = p[a]==a ? a : find_p(p[a]);
    return p[a];
}
int lca_max(int a,int b){
    int l=0;
    int u,v = link[a][0][1] > link[b][0][1] ? a : b;
    b = a+b-v;
    a = v;
    u = link[a][0][1];
    v = link[b][0][1];
    for(int i=17;i>=0;i--){
        if(u-v >= (1<<i)){
            l = l > link[a][i][2] ? l : link[a][i][2];
            a = link[a][i][0];
            u = link[a][0][1];
        }
    }
    if(a == b){
        return l;
    }
    for(int i=17;i>=0;i--){
        if(link[a][i][0] != link[b][i][0]){
            l = l > link[a][i][2] ? l : link[a][i][2];
            l = l > link[b][i][2] ? l : link[b][i][2];
            a = link[a][i][0];
            b = link[b][i][0];
        }
    }
    l = l > link[a][0][2] ? l : link[a][0][2];
    l = l > link[b][0][2] ? l : link[b][0][2];
    return l;
}
int main(){
    int n,m,u,v,w,i,f,t,visit[200001]={0,};
    long long s,c;
    queue<pair<int,pair<int,int>>> q;
    queue<int> q1;
    vector<pair<int,pair<int,int>>> v1;
    vector<pair<int,int>> g[200001];
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        v1.push_back({w,{u,v}});
        q.push({w,{u,v}});
    }
    sort(v1.begin(),v1.end());
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=0;i<m;i++){
        u = v1[i].second.first;
        v = v1[i].second.second;
        if(find_p(u) != find_p(v)){
            g[u].push_back({v,v1[i].first});
            g[v].push_back({u,v1[i].first});
            p[find_p(u)] = find_p(v);
            s += v1[i].first;
        }
    }
    q1.push(1);
    visit[1]=1;
    for(;!q1.empty();){
        t = q1.front();
        q1.pop();
        for(int i=0;i<(int)g[t].size();i++){
            if(!visit[g[t][i].first]){
                q1.push(g[t][i].first);
                visit[g[t][i].first]=1;
                link[g[t][i].first][0][0]=t;
                link[g[t][i].first][0][1]=link[t][0][1]+1;
                link[g[t][i].first][0][2]=g[t][i].second;
            }
        }
    }
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++){
            link[j][i][0] = link[link[j][i-1][0]][i-1][0];
            link[j][i][2] = link[j][i-1][2] > link[link[j][i-1][0]][i-1][2] ? link[j][i-1][2] : link[link[j][i-1][0]][i-1][2];
        }
    }
    for(int j=0;j<m;j++){
        i = q.front().second.first;
        f = q.front().second.second;
        c = q.front().first + s;
        q.pop();
        printf("%lld\n",c-lca_max(i,f));
    }
    return 0;
}