#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    vector<char> v1;
    vector<int> a;
    stack<int> stack1;
    int n, k, t = 1, j = 0;
    cin >> n;
    a.resize(n);
    for(int &i: a){
        cin >> i;
    }
    for(; t < n + 2 && j != n;){
        if(!stack1.empty() && stack1.top() == a[j]){
            stack1.pop();
            v1.push_back('-');
            j++;
        }else{
            stack1.push(t);
            v1.push_back('+');
            t++;
        }
    }
    if(!stack1.empty()){
        cout << "NO\n";
    }else{
        for(char &c: v1){
            cout << c << '\n';
        }
    }
    return 0;
}