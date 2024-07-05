#include <cstdio>
int count(int n){
    int b = 0;
    for(int i = 0; i <= 24; i++){
        b += n & (1 << i) ? 1 : 0;
    }
    return b;
}
int main(){
    int n, k, b, a = 0;
    scanf("%d %d", &n, &k);
    b = count(n);
    if(b > k){
        for(int i = 0; i <= 23; i++){
            if(n & (1 << i)){
                for(int j = i + 1; j <= 23; j++){
                    if(n & (1 << j)){
                        for(int k = i; k < j; k++){
                            a += 1 << k;
                            n += 1 << k;
                        }
                        b = count(n);
                        if(b <= k){
                            printf("%d", a);
                            return 0;
                        }
                        break;
                    }
                }
            }
        }
    }
    printf("%d", a);
    return 0;
}