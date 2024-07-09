#include <cstdio>
int main(){
    int n, m;
    long long c = 1, d = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n - 1; i++){
        c *= m - i;
        d *= i;
    }
    printf("%lld", c / d);
    return 0;
}