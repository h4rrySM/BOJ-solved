#include <cstdio>
#define MOD 1000000007
int main(){
    int n, k, a[5001], s = 0;
    scanf("%d %d", &n, &k);
    a[0] = 1;
    for(int i = 1; i <= 5000; i++){
        a[i] = a[i - 1] * 2;
        a[i] %= MOD;
    }
    s += a[n - k + 1] - 1;
    s %= MOD;
    if(n > 2*k - 1){
        s += a[n + 2 - k] - a[k + 1];
        s = (s % MOD + MOD) % MOD;
    }
    printf("%d", s);
    return 0;
}