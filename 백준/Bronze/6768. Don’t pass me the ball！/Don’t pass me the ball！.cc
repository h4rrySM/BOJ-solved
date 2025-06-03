#include <bits/stdc++.h>
using namespace std;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int j;
    cin >> j;
    if(j > 3){
        cout << (j-1) * (j-2) * (j-3) / 6;
    }else{
        cout << 0;
    }
    return 0;
}
