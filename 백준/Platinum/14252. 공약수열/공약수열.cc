#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
int gcd(int a, int b){
    for(;b > 0;){
        a = a % b + b;
        b = a - b;
        a -= b;
    }
    return a;
}
int main(){ IO;
    int N, c = 0, k = 2;
    vector<int> a;

    cin >> N;
    a.resize(N);
    for(int &ai: a){
        cin >> ai;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < N; i++){
        if(gcd(a[i], a[i - 1]) != 1){
            k = 2;
            for(int j = a[i - 1] +  1; j < a[i]; j++){
                if(gcd(a[i - 1], j) == 1 && gcd(a[i], j) == 1){
                    k = 1;
                }
            }
            c += k;
        }
    }
    cout << c << '\n';
    return 0;
}