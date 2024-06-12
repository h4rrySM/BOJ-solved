#include <cstdio>
using namespace std;
int main(){
    int pi[1000000]={0,},n,c=0,t1,t2,t3;
    char a,c1[2000000]={0,},c2[1000000]={0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&a);
        c1[i]=a;
        c1[i+n]=a;
    }
    for(int i=0;i<n;i++){
        scanf(" %c",&a);
        c2[i]=a;
    }
    for(int i=1,j=0;i<n;i++){
        for(;j>0 && c2[i]!=c2[j];){
            j = pi[j-1];
        }
        if(c2[i]==c2[j]){
            j++;
            pi[i]=j;
        }
    }
    for(int i=0,j=0;i<2*n-1;i++){
        for(;j>0 && c1[i]!=c2[j];){
            j = pi[j-1];
        }
        if(c1[i]==c2[j]){
            if(j==n-1){
                c++;
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    t1 = n;
    t2 = c;
    for(;t2!=0;){
        t3 = t2;
        t2 = t1%t2;
        t1 = t3;
    }
    printf("%d/%d",c/t1,n/t1);   
    return 0;
}