#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t, k, p, n;
    int dp[10001] = {0, };
    dp[0] = 1;
    cin >> t >> k;
    for(int i = 0; i < k; i++){
        cin >> p >> n;
        for(int j = t; j >= 0; j--){
            for(int k = 1; k <= n; k++){
                if(j >= p * k){
                    dp[j] += dp[j - p * k];
                }
            }
        }
    }
    cout << dp[t] << endl;
    return 0;
}