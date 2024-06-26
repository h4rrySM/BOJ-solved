#include <stdio.h>
int main(){
    int n,a,b,c;
    scanf("%d\n%d %d %d",&n,&a,&b,&c);
    printf("%d", (n<a ? n : a) + (n<b ? n : b) + (n<c ? n : c));
    return 0;
}