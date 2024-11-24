#include <bits/stdc++.h>
#define MOD 10567201
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll power(ll a, ll b){
    ll o = 1;
    for(; b > 0; b >>= 1, a = a * a % MOD){
        o = b & 1 ? o * a % MOD : o;
    }
    return o;
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, m, v;
    ll twof[1001][1001], f[1001];
    twof[0][0] = 1;
    f[0] = 1;
    for(int i = 1; i <= 1000; i++){
        f[i] = f[i - 1] * i % MOD;
        twof[i][0] = twof[i - 1][0] * 2 % MOD;
        for(int j = 1; j <= 1000; j++){
            twof[i][j] = twof[i][j - 1] * (twof[i][0] - j + MOD) % MOD;
        }
    }
    for(;;){
        cin >> n >> m >> v;
        if(n == m && m == v && n == 0){
            break;
        }
        ll dp[1001];
        dp[0] = (v == 0 ? 1 : 0);
        dp[1] = 1;
        for(int i = 1; i <= m / 2; i++){
            int k = 2 * i + (m & 1);
            dp[k] = (twof[n][k - 2] * power(f[k - 1], MOD - 2) % MOD - dp[k - 2] * (twof[n][0] - k + 2 + MOD) % MOD + MOD) % MOD * power(k, MOD - 2) % MOD;
        }
        cout << dp[m] << '\n';
    }
    return 0;
}