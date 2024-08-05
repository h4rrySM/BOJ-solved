#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

vector<int> sticks, v1, v2, visited, connect;

bool check(ll a, ll b){
    ll t = a * a + b * b, c = sqrt(t);
    for(; b > 0;){
        a = a % b + b;
        b = a - b;
        a -= b;
    }
    return t == c * c && a == 1;
}
bool bipartite_matching(int a){
    visited[a] = 1;
    for(int i: v2){
        if(check(sticks[a], sticks[i])){
            if(connect[i] == -1 || !visited[connect[i]] && bipartite_matching(connect[i])){
                connect[i] = a;
                connect[a] = i;
                return 1;
            }
        }
    }
    return 0;
}
int main(){ IO;
    int N, max = 0;
    cin >> N;
    sticks.resize(N);
    for(int i = 0; i < N; i++){
        cin >> sticks[i];
        if(sticks[i] % 2){
            v1.push_back(i);
        }else{
            v2.push_back(i);
        }
    }
    visited.resize(N);
    connect.resize(N, -1);
    for(int i: v1){
        if(connect[i] == -1){
            visited.clear();
            visited.resize(N);
            max += bipartite_matching(i);
        }
    }
    cout << max << '\n';
    return 0;
}