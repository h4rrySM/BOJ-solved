#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<ll> seg;

void init_seg(){
    for(int i = 0; i < N; i++){
        seg[i + N] = 1; 
    }
    for(int i = N - 1; i > 0; i--){
        seg[i] = seg[i << 1] + seg[i << 1 ^ 1];
    }
}
void upd_seg(int upd_index, int upd_value){
    upd_index += N;
    seg[upd_index] += upd_value;
    for(upd_index >>= 1; upd_index > 0; upd_index >>= 1){
        seg[upd_index] = seg[upd_index << 1] + seg[upd_index << 1 ^ 1];
    }
}
ll query_seg(int left, int right){
    ll sum = 0;
    left += N;
    right += N;
    for(; left < right; left >>= 1, right >>= 1){
        if(left & 1){
            sum += seg[left++];
        }
        if(!(right & 1)){
            sum += seg[right--];
        }
    }
    if(left == right){
        sum += seg[left];
    }
    return sum;
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    ll s = 0;
    vector<pii> a;
    cin >> N;
    seg.resize(2 * N);
    a.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    init_seg();
    sort(a.begin(), a.end());
    for(pii &ai: a){
        s += query_seg(0, ai.second) - 1;
        upd_seg(ai.second, -1);
    }
    cout << s;
    return 0;
}