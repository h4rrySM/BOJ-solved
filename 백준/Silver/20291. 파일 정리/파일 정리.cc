#include <iostream>
#include <string>
#include <map>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    string filename;
    map<string, int> file_count;
    int n;
    cin >> n;
    for(; n > 0; n--){
        cin >> filename;
        filename = filename.substr(filename.find('.') + 1);
        file_count[filename]++;
    }
    for(auto p1: file_count){
        cout << p1.first << ' ' << p1.second << '\n';
    }
    return 0;
}