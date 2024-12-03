#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int MOD = 1000000007;
int main(){ cin.tie(0)->sync_with_stdio(0);
    string S;
    cin >> S;
    int n = S.length();
    ll dp[301][301] = {0, };
    for(int i = 0; i < 301; i++){
        dp[i][i - 1] = 1;
    }
    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            for(int k = i + 1; k <= j; k++){
                if(S[i] != S[k]){
                    dp[i][j] = (dp[i][j] + (dp[i + 1][k - 1] * dp[k + 1][j]) % MOD) % MOD;
                }
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}