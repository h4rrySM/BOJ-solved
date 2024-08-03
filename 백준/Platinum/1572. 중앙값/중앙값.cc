#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

vector<int> segtree, a;

void update_segtree(int update_index, int update_value){
    update_index += 65537;
    segtree[update_index] += update_value;
    for(; update_index > 1; update_index >>= 1){
        segtree[update_index >> 1] = segtree[update_index] + segtree[update_index ^ 1];
    }
}
int find_segtree(int find){
    for(int i = 65537; i < 2 * 65537; ){
        if(segtree[i] >= find){
            if(i << 1 >= 2 * 65537){
                return find == 0 ? i - 1 : i;
            }else{
                i <<= 1;
            }
        }else{
            if((~i & 1) && segtree[i >> 1] < find){
                i >>= 1;
            }else{
                find -= segtree[i];
                i++;
            }
        }
    }
    return 2 * 65537 - 1;
}
int main(){ IO;
    int N, K;
    ll median_sum = 0;
    cin >> N >> K;
    a.resize(N);
    segtree.resize(2 * 65537);
    for(int &ai: a){
        cin >> ai;
    }
    for(int i = 0; i < K - 1; i++){
        update_segtree(a[i], 1);
    }
    for(int i = K - 1; i < N; i++){
        update_segtree(a[i], 1);
        median_sum += find_segtree((K + 1) / 2) - 65537;
        update_segtree(a[i - K + 1], -1);
    }
    cout << median_sum << '\n';
    return 0;
}