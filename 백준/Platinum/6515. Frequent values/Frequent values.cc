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
    int N, Q, start, end, left, right, c;
    vector<int> a, count, check(200001), check_max(200001);
    vector<ppiii> quary;
    for(;;){
        c = 0;
        a.clear();
        count.clear();
        quary.clear();
        check.clear();
        check_max.clear();
        check.resize(200001);
        check_max.resize(200001);
        cin >> N;
        if(N == 0){
            break;
        }
        cin >> Q;
        a.resize(N);
        for(int i = 0; i < N; i++){
            cin >> a[i];
            a[i] += 100000;
        }
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
        for(int i = 0; i < Q; i++){
            cout << count[i] << '\n';
        }
    }
    return 0;
}