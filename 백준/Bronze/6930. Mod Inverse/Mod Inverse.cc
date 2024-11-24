#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int gcd(int a, int b){
	for(; b > 0;){
		a = a % b + b;
		b = a - b;
		a -= b;
	}	
	return a;
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    int x, m;
    cin >> x >> m;
    if(gcd(x, m) != 1){
        cout << "No such integer exists.\n";
    }else{
        for(int i = 1; i < m; i++){
            if(x * i % m == 1){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}