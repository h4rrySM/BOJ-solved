#include <cstdio>
int main(){
    int n, c = 0;
    scanf("%d", &n);
    for(int i = n; i > 0; i /= 10){
        c = (i % 10 == 7 ? 1 : c);
    }
    printf("%d", c * 2 + (n % 7 == 0));
    return 0;
}