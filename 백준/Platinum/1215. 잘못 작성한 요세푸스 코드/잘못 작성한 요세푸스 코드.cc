#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    long long n, k, r = 0, a, b, c;
    scanf("%lld %lld", &n, &k);
    r += n > k ? (n - k) * k : 0;
    c = sqrt(k);
    for(int i = 1; i < c; i++){
        a = n < k / i ? n : k / i;
        b = k / (i + 1) + 1;
        r += b <= a ? (a - b + 1) * (2 * k - (a + b) * i) / 2 : 0;
    }
    for(int i = k / c < n ? k / c : n; i >= 1; i--){
        r += k % i;
    }
    printf("%lld", r);
    return 0;
}