#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    ll l = 1000000000;
    vector<ll> primes;
    vector<bool> check_prime(l, true);
    for(ll i = 2; i <= 31622; i++){
        if(check_prime[i]){
            for(ll j = i * i; j < l; j += i){
                check_prime[j] = false;
            }
        }
    }
    for(ll i = 2; i < l; i++){
        if(check_prime[i]){
            primes.push_back(i);
        }
    }
    ll z, res = 0;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> z;
        ll max_product = -1;
        for(int i = 0; i < primes.size() - 1; i++){
            ll product = primes[i] * primes[i + 1];
            if(product <= z){
                max_product = product;
            }else{
                break;
            }
        }
        cout << "Case #" << i <<": " << max_product << '\n';
    }
    return 0;
}