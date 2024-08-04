#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> socks(10);
    int a;
    for(int i = 0; i < 5; i++){
        cin >> a;
        socks[a]++;
    }
    for(int i = 0; i <= 9; i++){
        if(socks[i] % 2 == 1){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}