#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long multiply(long long a, long long b, long long mod){
    long long o = 0;
    for(; b != 0; b >>= 1, a = (a + a) % mod){
        if(b & 1){
            o += a;
            o %= mod;
        }
    }
    return o;
}
long long power(long long a, long long b, long long mod){
    long long o = 1;
    for(; b != 0; b >>= 1, a = multiply(a, a, mod)){
        if(b & 1){
            o = multiply(o, a, mod);
        }
    }
    return o;
}
long long gcd(long long a, long long b){
    long long t1, t2, t3;
    t1 = a > b ? a : b;
    t2 = a + b - t1;
    for(; t2 != 0;){
        t3 = t2;
        t2 = t1 % t2;
        t1 = t3;
    }
    return t1;
}
int miller_rabin(long long n){
    long long primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    long long d;
    if(n == 1){
        return 0;
    }
    for(int i = 0; i < 12; i++){
        if(n == primes[i]){
            return 1;
        }
        d = n - 1;
        if(d % 2 == 0){
            d /= 2;
        }
        for(; d % 2 == 0; d /= 2){
            if(power(primes[i], d, n) == n - 1){
                return 1;
            }
        }
        d = power(primes[i], d, n);
        if(d != 1 && d != n - 1){
            return 0;
        }
    }
    return 1;
}
long long pollard_rho(long long n){
    long long x1, x2, c, p;
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
        x1 = (multiply(x1, x1, n) + c) % n;
        x2 = (multiply(x2, x2, n) + c) % n;
        x2 = (multiply(x2, x2, n) + c) % n;
        p = gcd(x1 > x2 ? x1 - x2 : x2 - x1, n);
        if(p == n){
            break;
        }
    }
    return miller_rabin(p) ? p : pollard_rho(p);
}
int main(){
    long long n, p;
    vector<long long> v1;
    
    scanf("%lld",&n);
    for(; n > 1;){
        p = pollard_rho(n);
        v1.push_back(p);
        n /= p;
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < (int)v1.size(); i++){
        printf("%lld\n",v1[i]);
    }
    return 0;
}