#include <cstdio>
#include <algorithm>
using namespace std;
int tree[800001] = {0, }, a[200001] = {0, };
int cal(int i, int start, int end, int left, int right){
    int mid = (start + end) / 2;
    if(left <= start && end <= right){
        return tree[i];
    }else if(end >= left && right >= start){
        return cal(i * 2, start, mid, left, right) + cal(i * 2 + 1, mid + 1, end, left, right);
    }
    return 0;
}
int update(int i, int start, int end, int index, int k){
    int mid = (start + end) / 2;
    if(start <= index && index <= end){
        tree[i] += k;
        if(start != end){
            update(i * 2, start, mid, index, k);
            update(i * 2 + 1, mid + 1, end, index, k);
        }
    }
    return 0;
}
int main(){
    int n, m, t, p;
    scanf("%d", &t);
    for(; t > 0; t--){
        fill_n(tree, 800001, 0);
        fill_n(a, 200001, 0);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            a[i] = n + 1 - i;
            update(1, 1, n + m, a[i], 1);
        }
        for(int i = 1; i <= m; i++){
            scanf("%d", &p);
            printf("%d ", cal(1, 1, n + m, a[p] + 1, n + i));
            update(1, 1, n + m, a[p], -1);
            a[p] = n + i;
            update(1, 1, n + m, a[p], 1);
        }
        printf("\n");
    }
    return 0;
}