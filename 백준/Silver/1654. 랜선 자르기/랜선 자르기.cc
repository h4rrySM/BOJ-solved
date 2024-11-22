#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){ cin.tie(0)->sync_with_stdio(0);
    int N, K, max_height = 0;
    ll wires_count, low, high;
    vector<int> wires;
    cin >> K >> N;
    wires.resize(K);
    for(int &i: wires){
        cin >> i;
        max_height = max_height < i ? i : max_height;
    }
    low = 1;
    high = max_height;
    for(; low <= high;){
        wires_count = 0;
        ll mid = (low + high) / 2;
        for(int &i: wires){
            wires_count += i / mid;
        }
        if(wires_count < N){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << high;
    return 0;
}