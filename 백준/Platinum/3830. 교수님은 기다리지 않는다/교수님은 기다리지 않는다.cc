#include <cstdio>
#include <algorithm>
using namespace std;
int p[100001] = {0,};
long long q[100001] = {0,};
int find_p(int a){
    if(p[a] != a){
        find_p(p[a]);
    }
    q[a] += p[a] != a ? q[p[a]] : 0;
    p[a] = p[a] == a ? a : find_p(p[a]);
    return p[a];
}
int main(){
    int n, m;
    int a, b, w;
    char c;
    for(;;){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0){
            break;
        }
        fill_n(p, 100001, -1);
        fill_n(q, 100001, 0);
        for(int i = 1; i <= 100000; i++){
            p[i] = i;
        }
        for(int i = 1; i <= m; i++){
            scanf(" %c", &c);
            if(c == '!'){
                scanf("%d %d %d", &a, &b, &w);
                int s = find_p(a), t = find_p(b);
                if(s != t){
                    q[s] = q[b] + w - q[a];
                    p[s] = t;
                }
            }else{
                scanf("%d %d", &a, &b);
                if(find_p(a) != find_p(b)){
                    printf("UNKNOWN\n");
                }else{
                    printf("%lld\n", q[a] - q[b]);
                }
            }
        }
    }
    return 0;
}