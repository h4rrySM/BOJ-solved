#include <iostream>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int t, n;
    cin >> t;
    for(; t > 0; t--){
        cin >> n;
        cout << ((n + 1) % (n % 100) == 0 ? "Good" : "Bye") << '\n';
    }
    return 0;
}