#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Quary2{
    int k, left, right, index;
};
int N;
vector<ll> segtree, a;

void init_segtree(){
    for(int i = 0; i < N; i++){
        segtree[i + N] = a[i]; 
    }
    for(int i = N - 1; i > 0; i--){
        segtree[i] = segtree[i << 1] + segtree[i << 1 ^ 1];
    }
}
void update_segtree(int update_index, int update_value){
    update_index += N;
    segtree[update_index] += update_value;
    for(update_index >>= 1; update_index > 0; update_index >>= 1){
        segtree[update_index] = segtree[update_index << 1] + segtree[update_index << 1 ^ 1];
    }
}
ll sum_segtree(int left, int right){
    ll sum = 0;
    left += N;
    right += N;
    for(; left < right; left >>= 1, right >>= 1){
        if(left & 1){
            sum += segtree[left++];
        }
        if(!(right & 1)){
            sum += segtree[right--];
        }
    }
    if(left == right){
        sum += segtree[left];
    }
    return sum;
}
int main(){ IO;
    int M, k, i1, i2, q2_index = 0;
    vector<ll> ans;
    vector<pii> quary1;
    vector<Quary2> quary2;
    cin >> N;
    a.resize(N);
    segtree.resize(2 * N);
    for(ll &ai: a){
        cin >> ai;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> i1;
        if(i1 == 1){
            cin >> i1 >> i2;
            quary1.push_back({i1 - 1, i2});
        }else{
            cin >> k >> i1 >> i2;
            quary2.push_back({k, i1 - 1, i2 - 1, q2_index++});
        }
    }
    ans.resize(quary2.size());
    sort(quary2.begin(), quary2.end(), 
        [](Quary2 a, Quary2 b) -> bool {
            return a.k < b.k;
        }
    );
    init_segtree();
    int j = 0;
    for(int i = 0; i < (int)quary1.size(); i++){
        for(; quary2[j].k == i; j++){
            ans[quary2[j].index] = sum_segtree(quary2[j].left, quary2[j].right);
        }
        update_segtree(quary1[i].first, quary1[i].second - a[quary1[i].first]);
        a[quary1[i].first] = quary1[i].second;
    }
    for(int i = j; i < (int)quary2.size(); i++){
        ans[quary2[i].index] = sum_segtree(quary2[i].left, quary2[i].right);
    }
    for(ll s: ans){
        cout << s << '\n';
    }
    return 0;
}