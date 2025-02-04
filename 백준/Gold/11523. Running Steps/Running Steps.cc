#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    ll c[101][101] = {0,}, ans[101] = {0, };
    int p, t, s;
    for(int i = 0; i < 101; i++){
		c[i][0] = 1;
        c[i][i] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	for(int i = 1; i <= 50; i++){ 
		for(int j = i / 2; 3 * j >= i; j--){
            int k = i - 2 * j;
            ans[2 * i] += c[k + j][j] * c[k + j][j];
        }
	}
    cin >> p;
	for(;p--;){
		cin >> t >> s;
		cout << t << " " << ans[s] << '\n';
	}
    return 0;
}