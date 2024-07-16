#include <iostream>
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    io;
    int n, dp[1001] = {0, 0, 1}, j, check[1001];
    cin >> n;
    for(int i = 3; i <= n; i++){
        fill_n(check, 1001, 0);
        for(j = 0; j < i / 2; j++){
            check[dp[j] ^ dp[i - j - 2]] = 1;
        }
        for(j = 0; check[j]; j++){}
        dp[i] = j;
    }
    cout << (dp[n] ? 1 : 2) << endl;
    return 0;
}