#include <cstdio>
#include <vector>
using namespace std;
pair<int, int> tree_min[400001];
int a[100001];
pair<int, int> init_min(int i, int start, int end){
    int mid = (start + end) / 2;
    if(start == end){
        tree_min[i] = {a[start], start};
    }else{
        pair<int, int> u = init_min(i*2, start, mid);
        pair<int, int> v = init_min(i*2+1, mid+1, end);
        tree_min[i] = u < v ? u : v;
        if(u.first == v.first){
            tree_min[i] = u.second < v.second ? u : v;
        }else{
            tree_min[i] = u.first < v.first ? u : v;
        }
    }
    return tree_min[i];
}
pair<int, int> min_index(int i, int start, int end, int left, int right){
    int mid = (start + end) / 2;
    if(left <= start && end <= right){
        return tree_min[i];
    }else if(end >= left && right >= start){
        pair<int, int> u = min_index(i*2, start, mid, left, right);
        pair<int, int> v = min_index(i*2+1, mid+1, end, left, right);
        if(u.first == v.first){
            return u.second < v.second ? u : v;
        }else{
            return u.first < v.first ? u : v;
        } 
    }
    return {1000000001, -1};
}
pair<int, int> update(int i, int start, int end, int index, int k){
    int mid = (start + end) / 2;
    if(start == end && start == index){
        tree_min[i] = {k, index};
    }else if(start <= index && index <= end){
        pair<int, int> u = update(i*2, start, mid, index, k);
        pair<int, int> v = update(i*2+1, mid+1, end, index, k);
        if(u.first == v.first){
            tree_min[i] = u.second < v.second ? u : v;
        }else{
            tree_min[i] = u.first < v.first ? u : v;
        }
    }
    return tree_min[i];
}
int main(){
    int n, m, q, s, t;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    init_min(1,1,n);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d",&q, &s,&t);
        if(q == 1){
            update(1, 1, n, s, t);
        }else{
            printf("%d\n", min_index(1, 1, n, s, t).second);
        }
    }
    return 0;
}