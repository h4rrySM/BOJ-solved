#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int visit[200001] = {0, };
vector<int> two_way[200001];
int cycle_check(int a, int b){
    int c = 1;
    if(!visit[a]){
        c = 0;
        visit[a] = 1;
        for(int i = 0; i < (int)two_way[a].size(); i++){
            if(two_way[a][i] != b && cycle_check(two_way[a][i], a)){
                c = 1;
            }
        }
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, a, b, c;
    vector<int> graph[200001];
    vector<pair<int, int>> both;
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (int)graph[i].size(); j++){
            c = 0;
            for(int k = 0; k < (int)graph[graph[i][j]].size(); k++){
                if(graph[graph[i][j]][k] == i){
                    c = 1;
                }
            }
            if(c == 0){
                visit[graph[i][j]] = 1;
            }else{
                if(graph[i][j] < i){
                    both.push_back({i, graph[i][j]});
                }
            }
        }
    }
    
    for(int i = 0; i < (int)both.size(); i++){
        if((visit[both[i].first] ^ visit[both[i].second]) == 1){
            visit[both[i].first] = 1;
            visit[both[i].second] = 1;
        }else if((visit[both[i].first] | visit[both[i].second]) == 0){
            two_way[both[i].first].push_back(both[i].second);
            two_way[both[i].second].push_back(both[i].first);
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(!visit[i] && (two_way[i].empty() || !cycle_check(i, -1))){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}