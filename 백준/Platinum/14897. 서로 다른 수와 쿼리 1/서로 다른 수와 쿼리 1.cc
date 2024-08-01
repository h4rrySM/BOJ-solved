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
    int N, Q, start, end, left, right, c = 0, t = 0;
    vector<int> a, count, check(1000001);
    vector<pair<int, int>> comp;
    vector<ppiii> quary;
    cin >> N;
    a.resize(N);
    comp.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        comp[i] = {a[i], i};
    }
    sort(comp.begin(), comp.end());
    a[comp[0].second] = t;
    for(int i = 1; i < N; i++){
        t += (comp[i].first != comp[i - 1].first);
        a[comp[i].second] = t;
    }
    cin >> Q;
    count.resize(Q);
    quary.resize(Q);
    for(int i = 0; i < Q; i++){
        cin >> start >> end;
        quary[i] = {{start - 1, end - 1}, i};
    }
    for(sq_N = 1; (sq_N + 1) * (sq_N + 1) <= N; sq_N++);
    sort(quary.begin(), quary.end(), compare);
    left = quary[0].first.first;
    right = left - 1;
    for(int i = 0; i < Q; i++){
        start = quary[i].first.first;
        end = quary[i].first.second;
        for(;start < left;){
            c += (0 == check[a[--left]]++);
        }
        for(;end > right;){
            c += (0 == check[a[++right]]++);
        }
        for(;start > left;){
            c -= (0 == --check[a[left++]]);
        }
        for(;end < right;){
            c -= (0 == --check[a[right--]]);
        }
        count[quary[i].second] = c;
    }
    for(int i = 0; i < Q; i++){
        cout << count[i] << '\n';
    }
    return 0;
}