#include <cstdio>
using namespace std;
int tree[2000001] = {0, }, a[500001] = {0, }, b[1000001] = {0, };
int cal(int i, int start, int end, int left, int right){
    int mid = (start + end) / 2;
    if(left <= start && end <= right){
        return tree[i];
    }else if(end >= left && right >= start){
        return cal(i * 2, start, mid, left, right) + cal(i * 2 + 1, mid + 1, end, left, right);
    }
    return 0;
}
int connect(int i, int start, int end, int index){
    int mid = (start + end) / 2;
    if(start == end && start == index){
        tree[i] = 1;
    }else if(start <= index && index <= end){
        tree[i] = connect(i * 2, start, mid, index) + connect(i * 2 + 1, mid + 1, end, index);
    }
    return tree[i];
}
int main(){
    int n, t;
    long long d = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        b[t] = i;
    }
    for(int i = 1; i <= n; i++){
        d += cal(1, 1, n, b[a[i]] + 1, n);
        connect(1, 1, n, b[a[i]]);
    }
    printf("%lld", d);
    return 0;
}