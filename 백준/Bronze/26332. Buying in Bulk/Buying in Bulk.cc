#include <iostream>
using namespace std;
int main(){
    int n, c, p;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c >> p;
        cout << c << ' ' << p << '\n' << (p + (c - 1) * (p - 2)) << '\n';
    }
    return 0;
}