#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n;
    vector<pii> people;
    vector<int> order;
    cin >> n;
    people.resize(n);
    order.resize(n);
    for(pii &i: people){
        cin >> i.first >> i.second;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(people[i].first < people[j].first && people[i].second < people[j].second){
                order[i]++;
            }
        }
    }
    for(int &i: order){
        cout << i + 1 << ' ';
    }
    return 0;
}