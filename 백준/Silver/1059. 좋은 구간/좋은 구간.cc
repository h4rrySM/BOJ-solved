#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int l, n, left;
    vector<int> s;
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> n;
        s.push_back(n);
    }
    s.push_back(0);
    sort(s.begin(), s.end());
    cin >> n;
    for(int i = 0; i < l; i++){
        if(s[i] == n){
            cout << "0" << endl;
            return 0;
        }else{
            if(s[i] < n){
                left = i;
            }
        }
    }
    cout << (s[left + 1] - n) * (n - s[left]) - 1 << endl;
    return 0;
}