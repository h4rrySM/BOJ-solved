#include <iostream>
#include <string>
using namespace std;
int main(){
    string str[7] = {
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "Never gonna stop" 
    };
    string s1;
    int t, c, d = 0;
    cin >> t;
    cin.ignore();
    for(; t > 0; t--){
        c = 0;
        getline(cin, s1);
        for(int i = 0; i < 7; i++){
            if(s1 == str[i]){
                c = 1;
            }
        }
        if(!c){
            d = 1;
        }
    }
    cout << (d ? "Yes" : "No");
    return 0;
}