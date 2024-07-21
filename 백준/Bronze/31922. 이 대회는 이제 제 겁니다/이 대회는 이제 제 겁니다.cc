#include <iostream>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int a, p, c;
    cin >> a >> p >> c;
    cout << (a + c > p ? a + c : p) << '\n';
    return 0;
}