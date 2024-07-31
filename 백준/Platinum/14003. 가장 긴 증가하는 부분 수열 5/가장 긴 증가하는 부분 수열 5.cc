#include <stdio.h>
int main(){
    int n,l=1,p,s,e,m;
    int seq[1000001]={0,},c[1000001]={0,},save[1000001]={0,};
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p);
        seq[i]=p;
    }
    c[1]=seq[1];
    for(int i=1;i<=n;i++){
        if(seq[i]>c[l]){
            l++;
            c[l]=seq[i];
            save[i]=l;
        }else{
            s=1;
            e=l;
            for(;s!=e;){
                m=(s+e)/2;
                if(c[m] < seq[i]){
                    s=m+1;
                }else if(c[m] > seq[i]){
                    e=m;
                }else{
                    s=m;
                    break;
                }
            }
            c[s]=seq[i];
            save[i]=s;
        }
    }
    printf("%d\n",l);
    for(int i=n;i>0;i--){
        if(save[i]==l){
            save[i]=-1;
            l--;
        }
    }
    for(int i=1;i<=n;i++){
        if(save[i]==-1){
            printf("%d ",seq[i]);
        }
    }
    return 0;
}