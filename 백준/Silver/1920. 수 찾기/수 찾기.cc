#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,n,m;
    unordered_map<int, bool> b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        b[a]=1;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a;
        cout << b[a] << "\n";
    }
    return 0;
}