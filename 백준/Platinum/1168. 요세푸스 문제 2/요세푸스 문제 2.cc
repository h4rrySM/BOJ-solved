#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

vector<int> segtree;
int N, segtree_size;
void init_segtree(){
    for(int i = N; i < segtree_size; i++){
        segtree[i] = 1;
    }
    for(int i = N - 1; i > 0; i--){
        segtree[i] = segtree[i << 1] + segtree[i << 1 ^ 1];
    }
}
void update_segtree(int update_index){
    update_index += N;
    segtree[update_index]--;
    for(; update_index > 1; update_index >>= 1){
        segtree[update_index >> 1] = segtree[update_index] + segtree[update_index ^ 1];
    }
}
int find_segtree(int find){
    for(int i = N; i < segtree_size; ){
        if(segtree[i] >= find){
            if(i >= N){
                return i - (find == 0) - N;
            }else{
                i <<= 1;
            }
        }else{
            if((~i & 1) && segtree[i >> 1] < find){
                i >>= 1;
            }else{
                find -= segtree[i++];
            }
        }
    }
    return segtree_size - N;
}
int main(){ IO;
    int K, t;
    cin >> N >> K;

    segtree_size = 2 * N;
    segtree.resize(segtree_size);

    init_segtree();
    t = find_segtree(K);
    cout << "<" << t + 1;
    update_segtree(t);
    for(int i = 1, j = K; i < N; i++){
        j = (j + K - 2) % (N - i) + 1;
        t = find_segtree(j);
        cout << ", " << t + 1;
        update_segtree(t);
    }
    cout << '>' << '\n';
    return 0;
}