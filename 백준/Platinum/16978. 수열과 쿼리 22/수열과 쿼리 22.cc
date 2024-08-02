#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;
using pil = pair<int, long long>;

struct Q2{
    int k, left, right, index;
};
vector<ll> segtree, a;
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
ll sum_segtree(int i, int start, int end, int left, int right){
    int mid = (start + end) / 2;
    if(end < left || right < start){
        return 0;
    }
    return left <= start && end <= right ? segtree[i] : sum_segtree(i << 1, start, mid, left, right) + sum_segtree((i << 1) + 1, mid + 1, end, left, right);
}
bool compare(Q2 a, Q2 b){
    return a.k < b.k;
}
int main(){ IO;
    int N, M, q, k, s, t, q2_index = 0;
    ll v;
    vector<ll> ans;
    vector<pil> quary1;
    vector<Q2> quary2;
    cin >> N;
    a.resize(N);
    segtree.resize(4 * N);
    for(ll &ai: a){
        cin >> ai;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> q;
        if(q == 1){
            cin >> s >> v;
            quary1.push_back({s - 1, v});
        }else{
            cin >> k >> s >> t;
            quary2.push_back({k, s - 1, t - 1, q2_index++});
        }
    }
    ans.resize(quary2.size());
    sort(quary2.begin(), quary2.end(), compare);
    init_segtree(1, 0, N - 1);
    int j = 0;
    for(int i = 0; i < (int)quary1.size(); i++){
        for(; quary2[j].k == i; j++){
            ans[quary2[j].index] = sum_segtree(1, 0, N - 1, quary2[j].left, quary2[j].right);
        }
        update_segtree(1, 0, N - 1, quary1[i].first, quary1[i].second - a[quary1[i].first]);
        a[quary1[i].first] = quary1[i].second;
    }
    for(int i = j; i < (int)quary2.size(); i++){
        ans[quary2[i].index] = sum_segtree(1, 0, N - 1, quary2[i].left, quary2[i].right);
    }
    for(ll s: ans){
        cout << s << '\n';
    }
    return 0;
}