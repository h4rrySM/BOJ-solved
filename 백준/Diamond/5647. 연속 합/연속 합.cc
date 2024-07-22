#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define LL __int128
using namespace std;
ll gcd(LL a, LL b){
    for(; b > 0;){
        a = a % b + b;
        b = a - b;
        a -= b;
    }
    return a;
}
ll get_num(ll a){
	for(; a % 2 == 0; a /= 2){
	}
	return a;	
}
ll power(LL a, LL b, LL mod){
    LL o = 1;
    for(; b > 0; b >>= 1, a = a * a % mod){
        o = b & 1 ? o * a % mod : o;
    }
    return o;
}
bool miller_rabin(LL n){
    int primes[7] = {2, 3, 5, 7, 11, 13, 17};
    if(n == 1){
        return false;
    }
    for(int p: primes){
        bool c = false;
        ll d = n - 1;
        if(n == p){
            return true;
        }
        for(; (d + 1) % 2;){
            d /= 2;
            if(power(p, d, n) == n - 1){
                c = true;
                break;
            }
        }
        d = power(p, d, n);
        if(d != 1 && !c){
            return false;
        }
    }	
    return true;
}
ll pollard_rho(LL n){
    LL x1, x2, c, p;
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
int main(){ IO;
    int t;
	ll factors_num, exp_num, q, prime_factor;
	vector<ll> factors;
    for(;;){
		factors_num = 1;
		exp_num = 1;
		factors.clear();
		cin >> q;
		if(q == 0){
		    break;
		}
		q = q % 2 ? q : get_num(q);
		for(; q > 1;){
			prime_factor = pollard_rho(q);
			factors.push_back(prime_factor);
			q /= prime_factor;
		}
		sort(factors.begin(), factors.end());
    	for(int i = 1; i < (int)factors.size(); i++){
        	if(factors[i] != factors[i - 1]){
            	factors_num *= 2 * exp_num + 1;
            	exp_num = 1;
        	}else{
           		exp_num++;
        	}
    	}
    	factors_num *= factors.empty() ? 1 : 2 * exp_num + 1;
    	cout << factors_num * 2 << '\n';
	}
    return 0;
}