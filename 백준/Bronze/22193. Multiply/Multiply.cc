#include <cstdio>
int main(){
    char a[50001] = {0, }, b[50001] = {0, }, mul[100001] = {0, };
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s %s", a, b);
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            mul[n + m - i - j - 2] += (a[i] - 48) * (b[j] - 48);
            mul[n + m - i - j - 1] += mul[n + m - i - j - 2] / 10;
            mul[n + m - i - j - 2] %= 10;
        }
    }
    if((a[0] == 48 && n == 1) || (b[0] == 48 && m == 1)){
        printf("0");
    }else{
        if(mul[n + m - 1]){
            printf("%d", mul[n + m -1]);
        }
        for(int k = n + m - 2; k >= 0; k--){
            printf("%d", mul[k]);
        }
    }
    return 0;
}