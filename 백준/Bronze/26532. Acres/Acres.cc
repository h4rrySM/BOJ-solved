#include <iostream>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int a, b;
    cin >> a >> b;
    cout << (a * b + 4840 * 5 - 1) / (4840 * 5) << endl;
    return 0;
}