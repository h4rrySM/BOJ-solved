#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ppiii = pair<pair<int, int>, int>;

int sq_N;
bool compare(ppiii p1, ppiii p2){
    return p1.first.first / sq_N == p2.first.first / sq_N ? p1.first.second < p2.first.second : p1.first.first < p2.first.first; 
}
int main(){ IO;
    int N, C, M, start, end, left, right;
    vector<int> a, count, check(10001);
    vector<ppiii> quary;

    cin >> N >> C;
    a.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cin >> M;
    count.resize(M);
    quary.resize(M);
    for(int i = 0; i < M; i++){
        cin >> start >> end;
        quary[i] = {{start - 1, end - 1}, i};
    }
    for(sq_N = 1; (sq_N + 1) * (sq_N + 1) <= N; sq_N++);
    sort(quary.begin(), quary.end(), compare);
    left = quary[0].first.first;
    right = left - 1;
    for(int i = 0; i < M; i++){
        start = quary[i].first.first;
        end = quary[i].first.second;
        for(;start < left;){
            check[a[--left]]++;
        }
        for(;end > right;){
            check[a[++right]]++;
        }
        for(;start > left;){
            check[a[left++]]--;
        }
        for(;end < right;){
            check[a[right--]]--;
        }
        for(int j = 1; j <= C; j++){
            if(check[j] > (end - start + 1) / 2){
                count[quary[i].second] = j;
                break;
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(count[i] == 0){
            cout << "no" << '\n';
        }else{
            cout << "yes " << count[i] << '\n';
        }
    }
    return 0;
}