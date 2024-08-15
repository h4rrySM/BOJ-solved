#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int n, a, dp[1000001] = {0,}, ans, k = 0;
    for(int i = 0; i <= 1000000;){
        for(int j = 0; j < k + 1; j++){
            dp[i] = k;
            i++;
            if(i > 1000000){
                break;
            }
        }
        k++;
    }
    ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans ^= dp[a];
    }
    cout << (ans == 0 ? "cubelover" : "koosaga") << '\n';
    return 0;
}