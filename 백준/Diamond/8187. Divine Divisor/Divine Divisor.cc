#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll __int128
using namespace std;
ll power(ll a, ll b, ll mod){
    ll o = 1;
    for(; b > 0; b >>= 1, a = a * a % mod){
        o = b & 1 ? o * a % mod : o;
    }
    return o;
}
ll gcd(ll a, ll b){
    for(; b > 0;){
        a = a % b + b;
        b = a - b;
        a -= b;
    }
    return a;
}
int miller_rabin(ll n){
    ll primes[8] = {2, 3, 5, 7, 11, 13, 17, 19}, d, c;
    if(n == 1){
        return 0;
    }
    for(ll p: primes){
        c = 0;
        if(n == p){
            return 1;
        }
        for(d = n - 1; (d + 1) % 2;){
            d /= 2;
            if(power(p, d, n) == n - 1){
                c = 1;
                break;
            }
        }
        d = power(p, d, n);
        if(d != 1 && !c){
            return 0;
        }
    }
    return 1;
}
ll pollard_rho(ll n){
    ll x1, x2, c, p;
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
    for(p = 1; p == 1 && p != n;){
        x1 = (x1 * x1 % n + c) % n;
        x2 = (x2 * x2 % n + c) % n;
        x2 = (x2 * x2 % n + c) % n;
        p = gcd(x1 > x2 ? x1 - x2 : x2 - x1, n);
    }
    return miller_rabin(p) ? p : pollard_rho(p);
}
void power_2(ll a){
    vector<int> num;
    num.push_back(1);
    for(int c = 0; a > 0; a--, c = 0){
        for(int& d: num){
            d *= 2;
            d += c;
            c = 0;
            if(d >= 10){
                d -= 10;
                c = 1;
            }
        }
        if(c == 1){
            num.push_back(c);
        }
    }
    num[0]--;
    for(int i = 0; num[i] < 0; num[i] += 10, i++, num[i]--){
    }
    for (int i = (int)num.size() - 1; i >= 0; i--){
        cout << num[i];
    }
}
int main(){ IO;
    int n, k = 1, d = 0;
    long long a;
    vector<ll> v1;
    cin >> n;
    for(;n > 0; n--){
        cin >> a;
        for(ll i = a; i > 1;){
            v1.push_back(pollard_rho(i));
            i /= v1.back();
        }
    }
    sort(v1.begin(), v1.end());
    if(v1.size() == 1){
        cout << "1\n1" << '\n';
    }else{
        for(int i = 0; i < (int)v1.size();){
            int j;
            for(j = i; j < (int)v1.size() && v1[i] == v1[j]; j++){
            }
            if(j - i == k){
                d++;
            }else if(j - i > k){
                k = j - i;
                d = 1;
            }
            i = j;
        }
        cout << k << '\n';
        power_2(d);
        cout << '\n';
    }
    return 0;
}