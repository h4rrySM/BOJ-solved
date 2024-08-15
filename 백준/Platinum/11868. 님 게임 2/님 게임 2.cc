#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int n, a, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans ^= a;
    }
    cout << (ans == 0 ? "cubelover" : "koosaga") << '\n';
    return 0;
}