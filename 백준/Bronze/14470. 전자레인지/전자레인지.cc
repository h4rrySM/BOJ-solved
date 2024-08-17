#include <iostream>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if(a < 0){
        cout << (-1) * a * c + d + b * e << '\n';
    }else{
        cout << (b - a) * e << '\n';
    }
    return 0;
}