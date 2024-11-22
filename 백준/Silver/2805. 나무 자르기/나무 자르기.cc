#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int N, M, max_height = 0, low = 0, high;
    ll trees_sum;
    vector<int> trees;
    cin >> N >> M;
    trees.resize(N);
    for(int &i: trees){
        cin >> i;
        max_height = max_height < i ? i : max_height;
    }
    high = max_height;
    for(; low <= high;){
        trees_sum = 0;
        int mid = (low + high) / 2;
        for(int &i: trees){
            trees_sum += (i > mid) * (i - mid);
        }
        if(trees_sum < M){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << high;
    return 0;
}