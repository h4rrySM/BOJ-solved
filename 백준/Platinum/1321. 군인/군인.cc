#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

vector<ll> a, segtree;
ll init_segtree(int i, int start, int end){
    int mid = (start + end) / 2;
    return segtree[i] = (start == end ? a[start] : init_segtree(i << 1, start, mid) + init_segtree((i << 1) + 1, mid + 1, end));
}
void update_segtree(int i, int start, int end, int update_index, ll update_value){
    int mid = (start + end) / 2;
    if(start <= update_index && update_index <= end){
        segtree[i] += update_value;
        if(start != end){
            update_segtree(i << 1, start, mid, update_index, update_value);
            update_segtree((i << 1) + 1, mid + 1, end, update_index, update_value);
        }
    }
    return;
}
ll find_segtree(int i, int start, int end, int find){
    int mid = (start + end) / 2;
    if(start == end){
        return start;
    }
    return (segtree[i << 1] >= find ? find_segtree(i << 1, start, mid, find) : find_segtree((i << 1) + 1, mid + 1, end, find - segtree[i << 1]));
}
int main(){ IO;
    int N, M, q, s;
    ll t;
    cin >> N;
    a.resize(N);
    segtree.resize(4 * N);
    for(ll &ai: a){
        cin >> ai;
    }
    init_segtree(1, 0, N - 1);
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> q;
        if(q == 1){
            cin >> s >> t;
            update_segtree(1, 0, N - 1, s - 1, t);
            a[s - 1] += t;
        }else{
            cin >> s;
            cout << find_segtree(1, 0, N - 1, s) + 1 << '\n';
        }
    }
    return 0;
}