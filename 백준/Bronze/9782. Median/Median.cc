#include <iostream>
#include <string>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){ IO;
    int n;
    double m, k;
    for(int t = 1;; t++){
        cin >> n;
        if(n == 0){
            break;
        }
        if(n == 1){
            cin >> m;
        }else{
            for(int i = 1; i <= n; i++){
                cin >> k;
                if(i == n / 2){
                    if(n % 2 == 1){
                        cin >> k;
                        i++;
                        m = k;
                    }else{
                        m = k;
                        cin >> k;
                        i++;
                        m = (m + k) / 2;
                    }
                }
            }
        }
        cout << fixed;
        cout.precision(1);
        cout << "Case "  << t << ": " << m << '\n';
    }
    return 0;
}