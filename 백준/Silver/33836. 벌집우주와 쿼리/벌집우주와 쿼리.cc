#include <bits/stdc++.h>
using namespace std;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int q;
    int x, y;
    int n;
    cin >> q;
    for(; q--;){
        n = 0;
        cin >> x >> y;
        if(y == 0 && x >= 0){
            n = 0;
        }else if(y != 0 && (x < 0 && x < y)){
            n = 2;
        }else{
            n = 1;
        }
        cout << n << '\n';
    }
    return 0;
}