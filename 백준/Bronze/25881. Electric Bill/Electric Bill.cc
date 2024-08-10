#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){ IO;
    int a, b, n, k;
    cin >> a >> b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        cout << k << ' ' << (k > 1000 ? 1000 * a + (k - 1000) * b : k * a) << '\n';
    }
    return 0;
}