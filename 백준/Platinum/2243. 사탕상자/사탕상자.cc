#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define MAX 1000000
using namespace std;

vector<int> a(MAX), segtree(4 * MAX);
int init_segtree(int i, int start, int end){
    int mid = (start + end) / 2;
    return segtree[i] = (start == end ? a[start] : init_segtree(i << 1, start, mid) + init_segtree((i << 1) + 1, mid + 1, end));
}
void update_segtree(int i, int start, int end, int update_index, int update_value){
    int mid = (start + end) / 2;
    if(start <= update_index && update_index <= end){
        segtree[i] += update_value;
        if(start != end){
            update_segtree(i << 1, start, mid, update_index, update_value);
            update_segtree((i << 1) + 1, mid + 1, end, update_index, update_value);
        }
    }
    return;
}
int find_segtree(int i, int start, int end, int find){
    int mid = (start + end) / 2;
    if(start == end){
        return start;
    }
    return (segtree[i << 1] >= find ? find_segtree(i << 1, start, mid, find) : find_segtree((i << 1) + 1, mid + 1, end, find - segtree[i << 1]));
}
int main(){ IO;
    int N, M, q, s, t, find;
    cin >> N;
    init_segtree(1, 0, MAX - 1);
    for(int i = 0; i < N; i++){
        cin >> q;
        if(q == 1){
            cin >> s;
            find = find_segtree(1, 0, MAX - 1, s);
            cout << find + 1 << '\n';
            update_segtree(1, 0, MAX - 1, find, -1);
        }else{
            cin >> s >> t;
            update_segtree(1, 0, MAX - 1, s - 1, t);
            a[s - 1] += t;
        }
    }
    return 0;
}