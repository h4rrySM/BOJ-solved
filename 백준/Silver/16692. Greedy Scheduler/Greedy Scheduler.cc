#include <bits/stdc++.h>
using namespace std;
typedef struct{
    int t, cashier, order;
} Info;
struct compare{
	bool operator()(pair<int, Info> a, pair<int, Info> b){
		if(a.first == b.first){
            return a.second.cashier > b.second.cashier;
        }
        return a.first > b.first;	
	}
};
int main(){ cin.tie(0)->sync_with_stdio(0);
    priority_queue<pair<int, Info>, vector<pair<int, Info>>, compare> pq;
    vector<int> v;
    int n, c, ti;
    cin >> n >> c;
    v.resize(c);
    for(int i = 0; i < n; i++){
        cin >> ti;
        pq.push({ti, {ti, i, i}});
    }
    for(int i = n; i < c; i++){
        cin >> ti;
        int u = pq.top().first, k = pq.top().second.t, l = pq.top().second.cashier, m = pq.top().second.order;
        pq.pop();
        pq.push({ti + u, {ti, l, i}});
        v[m] = l + 1;
    }
    for(; !pq.empty();){
        v[pq.top().second.order] = pq.top().second.cashier + 1;
        pq.pop();
    }
    for(auto i: v){ 
        cout << i << ' ';
    }
    return 0;
}