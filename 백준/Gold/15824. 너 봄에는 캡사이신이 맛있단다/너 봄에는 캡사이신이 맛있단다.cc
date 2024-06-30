#include <cstdio>
#include <vector>
#include <algorithm>
#define MOD 1000000007 
using namespace std;
int main(){
    int n, s, t = 1;
    long long a = 0;
    vector<int> v1, v2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s);
        v1.push_back(s);
        v2.push_back(t - 1);
        t = t * 2 % MOD;
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < n; i++){
        a += (long long)v2[i] * (v1[i] - v1[n - i - 1]);
        a %= MOD;
    }
    printf("%lld", a);
    return 0;
}