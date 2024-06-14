#include <stdio.h>
int main(){
    double a,b,c=299792458;
    scanf("%lf %lf",&a,&b);
    printf("%lf",(a+b)/(1+a*b/c/c));
    return 0;
}