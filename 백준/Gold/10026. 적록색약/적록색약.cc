#include <cstdio>
#include <vector>
using namespace std;
int visit[102][102] = {0, }, visit2[102][102] = {0, };
char p[102][102] = {0, };
vector<int> v1, v2;
int dfs(int a, int b){
    int c = 0;
    if(!visit[a][b]){
        c = 1;
    }
    visit[a][b] = 1;
    if(p[a][b] == p[a + 1][b] && !visit[a + 1][b]){
        c = 1;
        dfs(a + 1, b);
    }
    if(p[a][b] == p[a - 1][b] && !visit[a - 1][b]){
        c = 1;
        dfs(a - 1, b);
    }
    if(p[a][b] == p[a][b + 1] && !visit[a][b + 1]){
        c = 1;
        dfs(a, b + 1);
    }
    if(p[a][b] == p[a][b - 1] && !visit[a][b - 1]){
        c = 1;
        dfs(a, b - 1);
    }
    return c;
}
int dfs2(int a, int b){
    int c = 0;
    if(!visit2[a][b]){
        c = 1;
    }
    visit2[a][b] = 1;
    if((p[a][b] == p[a + 1][b] || ((p[a][b] == 'R' || p[a][b] == 'G') && (p[a + 1][b] == 'R' || p[a + 1][b] == 'G'))) && !visit2[a + 1][b]){
        c = 1;
        dfs2(a + 1, b);
    }
    if((p[a][b] == p[a - 1][b] || ((p[a][b] == 'R' || p[a][b] == 'G') && (p[a - 1][b] == 'R' || p[a - 1][b] == 'G'))) && !visit2[a - 1][b]){
        c = 1;
        dfs2(a - 1, b);
    }
    if((p[a][b] == p[a][b + 1] || ((p[a][b] == 'R' || p[a][b] == 'G') && (p[a][b + 1] == 'R' || p[a][b + 1] == 'G'))) && !visit2[a][b + 1]){
        c = 1;
        dfs2(a, b + 1);
    }
    if((p[a][b] == p[a][b - 1] || ((p[a][b] == 'R' || p[a][b] == 'G') && (p[a][b - 1] == 'R' || p[a][b - 1] == 'G'))) && !visit2[a][b - 1]){
        c = 1;
        dfs2(a, b - 1);
    }
    return c;
}
int main(){
    int n;
    int c1 = 0, c2 = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", p[i] + 1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            c1 += dfs(i, j);
            c2 += dfs2(i, j);
        }
    }
    printf("%d %d", c1, c2);
    return 0;
}