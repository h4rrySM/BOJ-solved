#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){ IO;
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << n << " is " << (n % 2 == 0 ? "even" : "odd") << '\n';
    }
    return 0;
}