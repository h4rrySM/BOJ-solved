#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int p[50001]={0,},link[50001][18][4]={0,};
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
int lca_max2(int a,int b,int c){
    int l=-1;
    int u,v = link[a][0][1] > link[b][0][1] ? a : b;
    b = a+b-v;
    a = v;
    u = link[a][0][1];
    v = link[b][0][1];
    for(int i=0;i<u-v;i++){
        if(link[a][0][2]<c){
            l = l > link[a][0][2] ? l : link[a][0][2];
        }
        a = link[a][i][0];
    }
    if(a == b){
        return l;
    }
    for(int i=u-v;i<v;i++){
        if(link[a][i][0] != link[b][i][0]){
            if(link[a][0][2]<c){
                l = l > link[a][0][2] ? l : link[a][0][2];
            }
            if(link[b][0][2]<c){
                l = l > link[b][0][2] ? l : link[b][0][2];
            }
            a = link[a][i][0];
            b = link[b][i][0];
        }
    }
    if(link[a][0][2]<c){
        l = l > link[a][0][2] ? l : link[a][0][2];
    }
    if(link[b][0][2]<c){
        l = l > link[b][0][2] ? l : link[b][0][2];
    }
    return l;
}
int main(){
    int v,e,a,b,c,i,f,t,visit[50001]={0,},x=0,sec=2147483647,s=0,k,lca;
    queue<pair<int,pair<int,int>>> q;
    queue<int> q1;
    vector<pair<int,pair<int,int>>> v1;
    vector<pair<int,int>> g[50001];
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&a,&b,&c);
        v1.push_back({c,{a,b}});
        q.push({c,{a,b}});
    }
    sort(v1.begin(),v1.end());
    for(int i=1;i<=v;i++){
        p[i]=i;
    }
    for(int i=0;i<e;i++){
        a = v1[i].second.first;
        b = v1[i].second.second;
        if(find_p(a) != find_p(b)){
            g[a].push_back({b,v1[i].first});
            g[b].push_back({a,v1[i].first});
            p[find_p(a)] = find_p(b);
            s += v1[i].first;
            x++;
        }
    }
    if(x!=v-1){
        printf("-1");
        return 0;
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
                link[g[t][i].first][0][2]=g[t][i].second;
            }
        }
    }
    for(int i=1;i<=17;i++){
        for(int j=1;j<=v;j++){
            link[j][i][0] = link[link[j][i-1][0]][i-1][0];
            link[j][i][2] = link[j][i-1][2] > link[link[j][i-1][0]][i-1][2] ? link[j][i-1][2] : link[link[j][i-1][0]][i-1][2];
        }
    }
    for(int j=0;j<e;j++){
        i = q.front().second.first;
        f = q.front().second.second;
        k = q.front().first + s;
        lca = lca_max(i,f);
        q.pop();
        if(k-lca!=s){
            sec = sec < k-lca ? sec : k-lca;
        }else{
            lca = lca_max2(i,f,lca);
            if(lca != -1){
                sec = sec < k-lca ? sec : k-lca;
            }
        }
    }
    printf("%d",sec == 2147483647 ? -1 : sec);
    return 0;
}