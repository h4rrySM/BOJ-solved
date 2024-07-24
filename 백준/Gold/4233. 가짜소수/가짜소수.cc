#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
ll power(ll a, ll b, ll mod){
    return b ? power(a * a % mod, b >> 1, mod) * (b & 1 ? a : 1) % mod : 1;
}
bool prime(ll p){
    for(int i = 2; i * i <= p; i++){
        if(p % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){ IO;
    ll p, a;
    for(;;){
        cin >> p >> a;
        if(p == 0 && a == 0){
            break;
        }
        cout << (prime(p) ? "no" : (power(a, p, p) == a ? "yes" : "no")) << '\n';
    }
    return 0;
}