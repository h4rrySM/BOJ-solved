#include <iostream>
#include <string>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    string str;
    getline(cin, str);
    cout << (str.front() == '"' && str.back() == '"' && str.length() > 2? str.substr(1, str.length() - 2) : "CE") << '\n';
    return 0;
}