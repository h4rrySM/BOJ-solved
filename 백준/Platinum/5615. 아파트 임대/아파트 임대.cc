#include <cstdio>
using namespace std;
unsigned long long power(unsigned long long a, unsigned long long b, unsigned long long mod){
    unsigned long long o = 1;
    for(; b != 0; b >>= 1, a *= a){
        a %= mod;
        if(b & 1){
            o *= a;
            o %= mod;
        }
    }
    return o;
}
int miller_rabin(unsigned long long n){
    unsigned long long primes[3] = {2, 7, 61};
    unsigned long long d;
    int c;
    if(n == 1){
        return 0;
    }
    for(int i = 0; i < 3; i++){
        c = 0;
        if(n == primes[i]){
            return 1;
        }
        d = n - 1;
        if(d % 2 == 0){
            d /= 2;
        }
        for(; d % 2 == 0; d /= 2){
            if(power(primes[i], d, n) == n - 1){
                c = 1;
            }
        }
        d = power(primes[i], d, n);
        if(d != 1 && d != n - 1 && c == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    unsigned long long a;
    int n, k = 0;
    scanf("%d",&n);
    for(; n > 0; n--){
        scanf("%llu", &a);
        k += miller_rabin(a * 2 + 1) ? 1 : 0;
    }
    printf("%d", k);
    return 0;
}