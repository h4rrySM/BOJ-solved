#include <stdio.h>
int main(){
    int h, m, s, H, M, S;
    scanf("%d : %d : %d\n%d : %d : %d", &h, &m, &s, &H, &M, &S);
    h = (H - h) * 3600 + (M - m) * 60 + (S - s);
    h += h < 0 ? 3600 *  24 : 0;
    printf("%d", h);
    return 0;
}