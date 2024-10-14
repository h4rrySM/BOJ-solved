#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, barn_count, barn_number, max_cows = 0;
vector<vector<int>> barn_list;
vector<int> matching, visited;

int bipartite_matching(int cow){
    visited[cow] = 1;
    for(int i: barn_list[cow]){
        if(matching[i] == -1 || (!visited[matching[i]] && bipartite_matching(matching[i]))){
            matching[i] = cow;
            return 1;
        }
    }
    return 0;
}
int main(){ IO;
    cin >> N >> M;
    barn_list.resize(N + 1);
    visited.resize(N + 1);
    matching.resize(M + 1, -1);
    for(int i = 1; i <= N; i++){
        cin >> barn_count;
        for(int j = 1; j <= barn_count; j++){
            cin >> barn_number;
            barn_list[i].push_back(barn_number);
        }
    }
    for(int i = 1; i <= N; i++){
        visited.clear();
        visited.resize(N);
        max_cows += bipartite_matching(i);
    }
    cout << max_cows << '\n';
    return 0;
}