#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

vector<ll> segtree;
int N, segtree_size;
void init_segtree(){
    for(int i = N - 1; i > 0; i--){
        segtree[i] = segtree[i << 1] + segtree[i << 1 ^ 1];
    }
}
void update_segtree(int update_index, int update_value){
    update_index += N - 1;
    segtree[update_index] = update_value;
    for(; update_index > 1; update_index >>= 1){
        segtree[update_index >> 1] = segtree[update_index] + segtree[update_index ^ 1];
    }
}
ll sum_segtree(int left, int right){
    ll sum = 0;
    for(left += N - 1, right += N - 1; left < right; left >>= 1, right >>= 1){
        if(left & 1){
            sum += segtree[left++];
        }
        if(!(right & 1)){
            sum += segtree[right--];
        }
    }
    return sum + (left == right) * segtree[left];
}
int main(){ IO;
    int Q, x, y, a, b;
    cin >> N >> Q;
    segtree_size = 2 * N;
    segtree.resize(segtree_size);
    for(int i = N; i < segtree_size; i++){
        cin >> segtree[i];
    }
    init_segtree();
    for(int i = 0; i < Q; i++){
        cin >> x >> y >> a >> b;
        cout << sum_segtree(x > y ? y : x, x > y ? x : y) << '\n';
        update_segtree(a, b);
    }
    return 0;
}