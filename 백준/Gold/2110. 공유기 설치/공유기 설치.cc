#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){ cin.tie(0)->sync_with_stdio(0);

    int N, C, low, high, count;
    vector<int> houses;
    cin >> N >> C;
    houses.resize(N);
    for(int &i: houses){
        cin >> i;
    }
    sort(houses.begin(), houses.end());
    low = 0;
    high = houses.back() - houses.front();
    for(; low <= high;){
        count = 1;
        int mid = (low + high) / 2, index = 0;
        for(int i = 1; i < N; i++){
            if(houses[i] - houses[index] >= mid){
                count++;
                index = i;
            }
        }
        if(count < C){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << high;
    return 0;
}