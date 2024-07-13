#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int b;
    cin >> b;
    b = 500-5*b;
    cout << 100-b << '\n' << (b ? b/abs(b) : 0) << endl;
}