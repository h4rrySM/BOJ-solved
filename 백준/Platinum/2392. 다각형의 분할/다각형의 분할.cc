#include <iostream>
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000000
using namespace std;
int main(){
    io;
    int n;
    long long dp_tri[1001] = {0, }, dp_quad[1001] = {0, };
    cin >> n;
    dp_tri[2] = 1;
    for(int i = 3; i <= n; i++){
        for(int j = 0; j <= i - 3; j++){
            dp_tri[i] += dp_tri[j + 2] * dp_tri[i - 3 - j + 2];
            dp_tri[i] %= MOD;
        }
    }
    dp_quad[2] = 1;
    for(int i = 4; i <= n; i += 2){
        for(int j = 0; j <= i - 4; j += 2){
            for(int k = 0; k <= i - j - 4; k += 2){
                dp_quad[i] += (dp_quad[j + 2] * dp_quad[k + 2] % MOD) * dp_quad[i - j - k - 2];
                dp_quad[i] %= MOD;
            }
        }
    }
    cout << dp_tri[n] << "\n" << dp_quad[n] << endl;
    return 0;
}