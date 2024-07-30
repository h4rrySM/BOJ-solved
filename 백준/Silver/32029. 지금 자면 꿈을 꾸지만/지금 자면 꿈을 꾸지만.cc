#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int n, a, b, ti, time = 0, count = 0, max_count = 0;
    vector<int> t;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> ti;
        t.push_back(ti);
    }
    sort(t.begin(), t.end());
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < a; j++){
            time = 0;
            count = 0;
            for(int k = 0; k < i; k++){
                if(time + a <= t[k]){
                    time += a;
                    count++;
                }
            }
            if(i != n){
                time += j * b;
            }
            for(int k = i; k < n; k++){
                if(time + a - j <= t[k]){
                    time += (a - j);
                    count++;
                }
            }
            max_count = max_count > count ? max_count : count;
        }
    }
    cout << max_count << '\n';
    return 0;
}