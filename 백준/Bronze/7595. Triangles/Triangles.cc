#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

int main(){ IO;
    int n;
    for(;;){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                cout << '*';
            }
            cout << '\n';
        }
    }
    return 0;
}
