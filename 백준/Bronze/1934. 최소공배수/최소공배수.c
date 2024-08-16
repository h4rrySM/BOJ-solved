int g(int a,int b){return b?g(b,a%b):a;}
main(a,b,t){scanf("%d",&t);for(;t-->0;){scanf("%d %d",&a,&b);printf("%d\n",a*b/g(a,b));}}