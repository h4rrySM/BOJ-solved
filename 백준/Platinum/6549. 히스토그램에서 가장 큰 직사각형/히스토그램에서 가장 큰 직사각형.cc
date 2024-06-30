#include <cstdio>
#include <stack>
using namespace std;
int main(){
    long long n, h, s, t, k, m;
    stack<pair<long long, long long>> s1;
    pair<long long, long long> p1;
    for(;;){
        s = 0;
        m = 1000000001;
        scanf("%lld", &n);
        if(n == 0){
            break;
        }
        for(long long i = 1; i <= n; i++){
            scanf("%lld", &h);
            m = m < h ? m : h;
            for(; !s1.empty(); ){
                if(s1.top().first > h){
                    p1 = s1.top();
                    s1.pop();
                    k = s1.empty() ? 0 : s1.top().second;
                    t = (i - k - 1) * p1.first;
                    s = s > t ? s : t;
                }else{
                    break;
                }
            }
            s1.push({h, i});
        }
        for(; !s1.empty();){
            p1 = s1.top();
            s1.pop();
            k = s1.empty() ? 0 : s1.top().second;
            t = (n - k) * p1.first;
            s = s > t ? s : t;
        }
        t = m * n;
        s = s > t ? s : t;
        printf("%lld\n", s);
    }
    return 0;
}