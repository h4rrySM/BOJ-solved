#include <cstdio>
using namespace std;
int main(){
    int c1[720000]={0,},c2[360000]={0,},pi[360000]={0,},n,a,c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        c1[a]=1;
        c1[a+360000]=1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        c2[a]=1;
    }
    for(int i=1,j=0;i<360000;i++){
        for(;j>0 && c2[i]!=c2[j];){
            j = pi[j-1];
        }
        if(c2[i]==c2[j]){
            j++;
            pi[i]=j;
        }
    }
    for(int i=0,j=0;i<720000;i++){
        for(;j>0 && c1[i]!=c2[j];){
            j = pi[j-1];
        }
        if(c1[i]==c2[j]){
            if(j==359999){
                c=1;
                break;
            }else{
                j++;
            }
        }
    }
    if(c){
        printf("possible");
    }else{
        printf("impossible");
    }
    return 0;
}