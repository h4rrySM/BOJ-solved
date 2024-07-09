#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long dp[65][11] = {0, };
    int t, n;
    fill_n(dp[1], 10, 1);
    dp[1][10] = 10;
    for(int i = 2; i <= 64; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i-1][k];
            }
            dp[i][10] += dp[i][j];
        }
    }
    scanf("%d", &t);
    for(;t > 0; t--){
        scanf("%d", &n);
        printf("%lld\n", dp[n][10]);
    }
    return 0;
}