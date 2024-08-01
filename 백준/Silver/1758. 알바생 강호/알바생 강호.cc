#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int N;
    long long c = 0;
    vector<int> tip;
    cin >> N;
    tip.resize(N);
    for(int &t : tip){
        cin >> t;
    }
    sort(tip.begin(), tip.end());
    for(int i = 0; i < N; i++){
        c += tip[N - i - 1] - i > 0 ? tip[N - i - 1] - i : 0;
    }
    cout << c << '\n';
    return 0;
}