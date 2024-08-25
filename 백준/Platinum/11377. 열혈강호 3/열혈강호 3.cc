#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, K, t = 0, work_count, work_number, max_works = 0;
int work_list[1001][1001], matching[1001], visited[1001];

int bipartite_matching(int worker){
    visited[worker] = 1;
    for(int i: work_list[worker]){
        if(i != 0 && (matching[i] == -1 || (!visited[matching[i]] && bipartite_matching(matching[i])))){
            matching[i] = worker;
            return 1;
        }
    }
    return 0;
}
int main(){ IO;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        cin >> work_count;
        for(int j = 0; j < work_count; j++){
            cin >> work_list[i][j];
        }
    }
    memset(matching, -1, sizeof(visited));
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        max_works += bipartite_matching(i);
    }
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        if(bipartite_matching(i)){
            max_works++;
            t++;
        }
        if(t == K){
            break;
        }
    }
    cout << max_works << '\n';
    return 0;
}