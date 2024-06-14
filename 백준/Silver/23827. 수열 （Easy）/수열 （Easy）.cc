#include <cstdio>
using namespace std;
int main(){
    int n,t=1000000005;
    long long s=0,k=1,mul[32]={0,},a[500000]={0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        s += a[i];
        s %= 1000000007;
    }
    s *= s;
    s %= 1000000007;
    for(int i=0;i<n;i++){
        s -= a[i]*a[i];
        s %= 1000000007;
        s += 1000000007;
        s %= 1000000007;
    }
    mul[0]=2;
    for(int i=1;i<32;i++){
        mul[i]=mul[i-1]*mul[i-1]%1000000007;
    }
    for(int i=0;t!=0;t>>=1,i++){
        if(t & 1){
            k *= mul[i];
            k %= 1000000007;
        }
    }
    printf("%lld",s*k%1000000007);
    return 0;
}