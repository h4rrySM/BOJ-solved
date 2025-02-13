#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ppiii = pair<pair<int, int>, int>;
int sq_N;
bool compare(ppiii p1, ppiii p2){
    if(p1.first.first / sq_N == p2.first.first / sq_N){
        return p1.first.second < p2.first.second;
    }else{
        return p1.first.first < p2.first.first;
    }
}
int main(){ IO;
    int N, M, start, end, left, right, c;
    cin >> N;
    vector<int> a(N), check(1000001), check_max(1000001);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cin >> M;
    vector<ppiii> quary(M);
    vector<int> count(M);
    for(int i = 0; i < M; i++){
        cin >> left >> right;
        quary[i] = {{left - 1, right - 1}, i};
    }
    for(sq_N = 1; (sq_N + 1) * (sq_N + 1) <= N; sq_N++);
    sort(quary.begin(), quary.end(), compare);
    c = 0;
    check_max[0] = N;
    for(int i = quary[0].first.first; i <= quary[0].first.second; i++){
        check_max[check[a[i]]]--;
        check_max[++check[a[i]]]++;
        c = c > check[a[i]] ? c : check[a[i]];
    }
    count[quary[0].second] = c;
    left = quary[0].first.first;
    right = quary[0].first.second;
    for(int i = 1; i < (int)quary.size(); i++){
        start = quary[i].first.first;
        end = quary[i].first.second;
        for(;start < left;){
            check_max[check[a[--left]]]--;
            check_max[++check[a[left]]]++;
            c = c > check[a[left]] ? c : check[a[left]];
        }
        for(;end > right;){
            check_max[check[a[++right]]]--;
            check_max[++check[a[right]]]++;
            c = c > check[a[right]] ? c : check[a[right]];
        }
        for(;start > left;){
            check_max[check[a[left]]]--;
            check_max[--check[a[left++]]]++;
            c -= check_max[c] == 0;
        }
        for(;end < right;){
            check_max[check[a[right]]]--;
            check_max[--check[a[right--]]]++;
            c -= check_max[c] == 0;
        }
        count[quary[i].second] = c;
    }
    for(int i = 0; i < (int)quary.size(); i++){
        cout << count[i] << '\n';
    }
    return 0;
}