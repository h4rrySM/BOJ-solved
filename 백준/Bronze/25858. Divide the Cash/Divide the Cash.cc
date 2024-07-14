#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, d, solve, total = 0;
    vector<int> problems;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> solve;
        total += solve;
        problems.push_back(solve);
    }
    for(int i = 0; i < n; i++){
        cout << d / total * problems[i] << endl;
    }
    return 0;
}