#include <bits/stdc++.h>
using namespace std;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, c = 0;
    string s;
    map<char, int> m;
    m['2'] = 0;
    m['5'] = 1;
    m['['] = 2;
    m[']'] = 3;
    int cases[4][4] = {
        {2, 1, 1, 1},
        {1, 2, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1}
    };
    cin >> n >> s;
    for(int i = 0; i < n - 1; i++){
        c += cases[m[s[i]]][m[s[i + 1]]];
    }
    cout << c;
    return 0;
}