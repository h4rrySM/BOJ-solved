#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long f(long long n){
    long long k = 1;
    for(int i = 2; i <= n; i++){
        k *= i;
    }
    return k;
}
__int128 power(__int128 a, __int128 b, __int128 mod){
    __int128 o = 1;
    for(; b != 0; b >>= 1, a = a * a % mod){
        if(b & 1){
            o = o * a % mod;
        }
    }
    return o;
}
__int128 gcd(__int128 a, __int128 b){
    for(;b != 0; ){
        a %= b;
        a += b;
        b = a - b;
        a -= b;
    }
    return a;
}
int miller_rabin(__int128 n){
    __int128 d, primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int c;
    if(n == 1){
        return 0;
    }
    for(int i = 0; i < 9; i++){
        c = 0;
        if(n == primes[i]){
            return 1;
        }
        d = n - 1;
        for(; d % 2 == 0; ){
            d /= 2;
            if(power(primes[i], d, n) == n - 1){
                c = 1;
                break;
            }
        }
        d = power(primes[i], d, n);
        if(d != 1 && d != n - 1 && c == 0){
            return 0;
        }
    }
    return 1;
}
long long pollard_rho(__int128 n){
    __int128 x1, x2, c, p;
    if(miller_rabin(n)){
        return n;
    }
    if(n == 1){
        return 1;
    }
    if(n % 2 == 0){
        return 2;
    }
    x1 = rand() % (n - 2) + 2;
    x2 = x1;
    c = rand() % (n - 1) + 1;
    for(p = 1; p == 1;){
        x1 = (x1 * x1 % n + c) % n;
        x2 = (x2 * x2 % n + c) % n;
        x2 = (x2 * x2 % n + c) % n;
        p = gcd(x1 > x2 ? x1 - x2 : x2 - x1, n);
        if(p == n){
            break;
        }
    }
    return miller_rabin(p) ? p : pollard_rho(p);
}
int main(){
    long long c, n_t;
    __int128 n;
    __int128 p;
    vector<__int128> v1;
    int t;
    scanf("%d", &t);
    for(; t > 0; t--){
        c = 0;
        scanf("%lld",&n_t);
        n = n_t;
        v1.clear();
        if(n == 4){
            c = 1;
        }else{
            for(; n > 1;){
                p = pollard_rho(n);
                v1.push_back(p);
                n /= p;
            }
            sort(v1.begin(), v1.end());
            for(int i = 1; i < (int)v1.size(); i++){
                if(v1[i] == v1[i-1]){
                    c = -1;
                    break;
                }
            }
        }
        printf("%lld\n", c == 0 ? f(v1.size()) : c);
    }
    return 0;
}