#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
ll A, H, X, Y;
int check(){
    return (Y + A - 1) / A < (H + X - 1) / X;
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    ll r = 0;
    int N, s, e;
    cin >> N >> X >> Y;
    vi cards(N);
    for(int &i: cards){
        cin >> i;
    }
    vector<ll> prefix_sum(N + 1);
    for(int i = 0; i < N; i++){
        prefix_sum[i + 1] = prefix_sum[i] + cards[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++) {
            for(A=prefix_sum[j + 1]-prefix_sum[i],s=!i*(j+1),e=!i*s,H=0;s<N;s++){    
                for(s = s-i?s:j+1;!check()&&e<N;){
                    H += cards[e++];
                    e=(e-i?e:j+1);
                }
                if(check()){
                    r += e > j ? (N - e + 1) : (N - e + i - j);
                }
                H -= cards[s];
            }
        }
    }
    cout << (r > 0 ? to_string(r) : "IMPOSSIBLE");
    return 0;
}