#include <cstdio>
using namespace std;
int main(){
    int n,x,a[10001]={0,};
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=10000;i++){
        for(;a[i]>0;a[i]--){
            printf("%d\n",i);
        }
    }
    return 0;
}