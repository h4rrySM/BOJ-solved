#include <cstdio>
#define MOD 42
int main(){
    char n[31] = {0, };
    int r;
    for(;;){
        scanf("%s", n);
        r = 0;
        if(n[0] == 48 && n[1] == '\0'){
            break;
        }
        for(int i = 0; n[i] != '\0'; i++){
            r *= 10;
            r += n[i] - 48;
            r %= MOD;
        }
        printf("%s\n", r ? "TENTE NOVAMENTE" : "PREMIADO");
    }
    return 0;
}