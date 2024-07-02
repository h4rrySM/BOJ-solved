#include <cstdio>
#include <stack>
using namespace std;
int main(){
    int n, h, s, t, k, m;
    stack<pair<int, int>> s1;
    pair<int, int> p1;
    s = 0;
    m = 1000000001;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &h);
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
    printf("%d\n", s);
    return 0;
}