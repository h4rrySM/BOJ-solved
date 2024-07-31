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
    int N, K, M, start, end, left, right;
    long long c;
    cin >> N >> K;
    vector<int> a(N + 1), check(3000001);
    cin >> a[1];
    for(int i = 2; i <= N; i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    cin >> M;
    vector<ppiii> quary(M);
    vector<long long> count(M);
    for(int i = 0; i < M; i++){
        cin >> left >> right;
        quary[i] = {{left - 1, right}, i};
    }
    for(sq_N = 1; (sq_N + 1) * (sq_N + 1) <= N; sq_N++);
    sort(quary.begin(), quary.end(), compare);
    c = 0;
    left = quary[0].first.first;
    right = left - 1;
    for(int i = 0; i < (int)quary.size(); i++){
        start = quary[i].first.first;
        end = quary[i].first.second;
        for(;start < left;){
            c += check[a[--left] ^ K];
            check[a[left]]++;
        }
        for(;end > right;){
            c += check[a[++right] ^ K];
            check[a[right]]++;
        }
        for(;start > left;){
            check[a[left]]--;
            c -= check[a[left++] ^ K];
        }
        for(;end < right;){
            check[a[right]]--;
            c -= check[a[right--] ^ K];
        }
        count[quary[i].second] = c;
    }
    for(int i = 0; i < (int)quary.size(); i++){
        cout << count[i] << '\n';
    }
    return 0;
}