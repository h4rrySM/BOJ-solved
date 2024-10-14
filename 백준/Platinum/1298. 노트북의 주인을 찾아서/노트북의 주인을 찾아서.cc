#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, a, b, max_laptops = 0;
vector<vector<int>> laptop_list;
vector<int> matching, visited;

int bipartite_matching(int person){
    visited[person] = 1;
    for(int i: laptop_list[person]){
        if(matching[i] == -1 || (!visited[matching[i]] && bipartite_matching(matching[i]))){
            matching[i] = person;
            return 1;
        }
    }
    return 0;
}
int main(){ IO;
    cin >> N >> M;
    laptop_list.resize(N + 1);
    visited.resize(N + 1);
    matching.resize(N + 1, -1);
    for(int i = 1; i <= M; i++){
        cin >> a >> b;
        laptop_list[a].push_back(b);    
    }
    for(int i = 1; i <= N; i++){
        visited.clear();
        visited.resize(N);
        max_laptops += bipartite_matching(i);
    }
    cout << max_laptops << '\n';
    return 0;
}