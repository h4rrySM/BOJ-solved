#include <cstdio>
int main(){
    int t, a, b, c, p;
    scanf("%d", &t);
    for(; t > 0; t--){
        scanf("%d %d %d %d", &a, &b, &c, &p);
        printf("%d\n", !(a % p) + !(b % p) + !(c % p) > 1);
    }
}