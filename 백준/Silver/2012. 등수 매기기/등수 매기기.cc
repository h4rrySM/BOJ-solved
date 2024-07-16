#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long k = 0;
    cin >> n;
    vector<int> pred(n);
    for(int i = 0; i < n; i++){
        cin >> pred[i];
    }
    sort(pred.begin(), pred.end());
    for(int i = 0; i < n; i++){
        k += abs(pred[i] - i - 1);
    }
    cout << k << endl;
    return 0;
}