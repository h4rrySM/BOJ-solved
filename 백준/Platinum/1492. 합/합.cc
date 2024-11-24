#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;

LL power(LL a, LL b){
    LL o = 1;
    for(; b > 0; b >>= 1, a = a * a % MOD){
        o = b & 1 ? o * a % MOD : o;
    }
    return o;
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    ll N, K;
    LL f[52], dp[52];
    cin >> N >> K;
    f[0] = 1;
    for(LL i = 1; i <= 51; i++){
        f[i] = f[i - 1] * i % MOD;
    }
    dp[0] = N % MOD;
    for(LL i = 1; i <= K; i++){
        LL t = 0;
        for(LL j = 0; j < i; j++){
            t += f[i + 1] * power(f[i + 1 - j] * f[j] % MOD, MOD - 2) % MOD * dp[j];
            t %= MOD;
        }
        t = (power(N + 1, i + 1) - 1 - t + MOD) * power(i + 1, MOD - 2) % MOD;
        dp[i] = t;
    }
    cout << (ll)dp[K];
    return 0;
}