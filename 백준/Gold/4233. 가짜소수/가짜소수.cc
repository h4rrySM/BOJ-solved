#include <iostream>
#define l long long
l p,a;l f(l u,l v){return v?f(u*u%p,v>>1)*(v&1?u:1)%p:1;}l g(l i){for(;i*i<=p;){if(0==p%i++)return 0;}return 1;}main(){for(;std::cin>>p>>a&&p*a;std::cout<<(f(a,p)-a|g(2)?"no\n":"yes\n"));}