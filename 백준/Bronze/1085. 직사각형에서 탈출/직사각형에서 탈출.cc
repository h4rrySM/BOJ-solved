#include <stdio.h>
int main(){
    int x,y,w,h,ans;
    scanf("%d %d %d %d",&x,&y,&w,&h);
    if(x<=(w/2)){
        if(x<=y&&x<=(h-y)){
            ans = x;
        } else {
            ans = y<(h-y) ? y : (h-y);
        }
    } if(x>=(w/2)){
        if((w-x)<=y&&(w-x)<=(h-y)){
            ans = (w-x);
        } else {
            ans = y<(h-y) ? y : (h-y);
        }
    }
    printf("%d",ans);
    return 0;
}