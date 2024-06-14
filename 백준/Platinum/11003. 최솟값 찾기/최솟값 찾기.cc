#include <cstdio>
#include <deque>
using namespace std;
int main(){
    int n, l, a;
    deque<pair<int, int>> dq;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(!dq.empty() && dq.front().second <= i - l){
            dq.pop_front();
        }
        for(; !dq.empty() && dq.back().first > a; ){
            dq.pop_back();
        }
        dq.push_back({a, i});
        printf("%d ", dq.front().first);
    }
    return 0;
}