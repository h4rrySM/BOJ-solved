#include <cstdio>
using namespace std;
int main(){
    int n, t, s = -8;
    scanf("%d", &n);
    for(;n > 0; n--){
        scanf("%d", &t);
        s += t + 8;
    }
    printf("%d %d", s / 24, s % 24);
    return 0;
}