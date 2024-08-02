#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int N, M, R, u, v, order = 1;
    vector<int> visited, visit_order;
    vector<vector<int>> graph;
    queue<int> bfs_queue;
    cin >> N >> M >> R;
    R--;
    graph.resize(N);
    visited.resize(N);
    visit_order.resize(N);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited[R] = 1;
    bfs_queue.push(R);
    for(;!bfs_queue.empty();){
        u = bfs_queue.front();
        bfs_queue.pop();
        visit_order[u] = order++;
        sort(graph[u].begin(), graph[u].end());
        for(int v: graph[u]){
            if(visited[v] == 0){
                visited[v] = 1;
                bfs_queue.push(v);
            }
        }
    }
    for(int vo: visit_order){
        cout << vo << '\n';
    }
    return 0;
}