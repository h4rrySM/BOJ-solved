#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int n, m, k;
    cin >> n >> m >> k;
    cout << (m > k ? k : m) + (n - m > n - k ? n - k : n - m) << '\n';
    return 0;
}