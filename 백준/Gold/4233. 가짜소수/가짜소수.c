#define l long long
l p,a;f(l u,l v){return v?(v&1?u:1)*f(u*u%p,v>>1)%p:1;}g(i,t){for(;i<=p/i;)t+=!(p%i++);return !t;}main(){for(;scanf("%d%d",&p,&a)*p;printf("%s",f(a,p)-a|g(2,0)?"no\n":"yes\n"));}