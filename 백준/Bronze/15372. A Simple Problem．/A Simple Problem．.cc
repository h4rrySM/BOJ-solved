#include <cstdio>
int main(){
    int t;
    long long n;
    scanf("%d", &t);
    for(; t > 0; t--){
        scanf("%lld", &n);
        printf("%lld\n", n * n);
    }
    return 0;
}