#include <stdio.h>
int main(){
    long long min,max;
    long long check[1000001]={0,};
    long long count=0;
    scanf("%lld %lld", &min,&max);
    for(long i = 2;i*i<=max;i++){
        long long j = min / (i * i);
        if (min % (i * i)!=0){
          j++;  
        } 
        for(;j*i*i<=max;j++){
            check[j*i*i-min] = 1;
        }
    }
    for(long long i=0;i<=max-min;i++){
        if(check[i]==0){
            count++;
        }
    }
    printf("%lld",count);
    return 0;
}