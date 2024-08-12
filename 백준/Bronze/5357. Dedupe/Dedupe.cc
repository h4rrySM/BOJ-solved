#include <iostream>
#include <string>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){ IO;
    int n;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        str.erase(unique(str.begin(), str.end()), str.end());
        cout << str << '\n';
    }
    return 0;
}