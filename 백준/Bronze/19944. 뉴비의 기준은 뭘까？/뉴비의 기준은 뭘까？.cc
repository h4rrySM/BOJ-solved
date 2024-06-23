#include <cstdio>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    if(m <= 2){
        printf("NEWBIE!");
    }else{
        printf("%s", m <= n ? "OLDBIE!" : "TLE!");
    }
    return 0;
}