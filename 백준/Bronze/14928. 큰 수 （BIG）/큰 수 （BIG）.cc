#include <cstdio>
#define MOD 20000303
int main(){
    char n[1000002] = {0, };
    int r = 0;
    scanf("%s", n);
    for(int i = 0; n[i] != '\0'; i++){
        r *= 10;
        r += n[i] - 48;
        r %= MOD;
    }
    printf("%d", r);
    return 0;
}