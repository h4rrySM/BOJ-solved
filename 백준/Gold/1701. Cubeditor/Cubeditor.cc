#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int pi[5001]={0,},m=0,l=1;
    char a[5001];
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        fill_n(pi,5001,i);
        l=1+i;
        for(int j=i;a[l]!='\0';l++){
            for(;j>i && a[l]!=a[j];){
                j = pi[j-1];
            }
            if(a[l]==a[j]){
                j++;
                pi[l]=j;
                m = m > j-i ? m : j-i;
            }
        }
    }
    printf("%d",m);
    return 0;
}