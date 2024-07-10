#include <cstdio>
int main(){
    int n;
    char s[102];
    scanf("%d %s", &n, s);
    if(s[n - 1] == 'G'){
        s[n - 1] = '\0';
    }else{
        s[n] = 'G';
    }
    printf("%s", s);
}