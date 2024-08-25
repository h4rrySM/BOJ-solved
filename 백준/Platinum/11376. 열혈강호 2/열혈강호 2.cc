#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, work_count, work_number, max_works = 0;
vector<vector<int>> work_list;
vector<int> matching, visited;

int bipartite_matching(int worker){
    visited[worker] = 1;
    for(int i: work_list[worker]){
        if(matching[i] == -1 || (!visited[matching[i]] && bipartite_matching(matching[i]))){
            matching[i] = worker;
            return 1;
        }
    }
    return 0;
}
int main(){ IO;
    cin >> N >> M;
    work_list.resize(N + 1);
    visited.resize(N + 1);
    matching.resize(M + 1, -1);
    for(int i = 1; i <= N; i++){
        cin >> work_count;
        for(int j = 1; j <= work_count; j++){
            cin >> work_number;
            work_list[i].push_back(work_number);
        }
    }
    for(int i = 1; i <= N; i++){
        fill(visited.begin(), visited.end(), 0);
        max_works += bipartite_matching(i);
        fill(visited.begin(), visited.end(), 0);
        max_works += bipartite_matching(i);
    }
    cout << max_works << '\n';
    return 0;
}