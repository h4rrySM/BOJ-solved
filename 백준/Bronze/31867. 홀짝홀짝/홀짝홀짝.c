main(n,e,o){char k[1<<20];scanf("%d%s",&n,k);for(e=0,o=0;n--;){if(k[n]&1){o++;}else{e++;}}printf("%d",(o>e)-(o==e));}