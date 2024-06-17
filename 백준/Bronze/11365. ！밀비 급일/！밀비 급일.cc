#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string s1;
    for(;;){
        getline(cin, s1);
        if(s1 == "END"){
            break;
        }
        for(int i = s1.size()-1; i >= 0 ;i--){
            printf("%c",s1[i]);
        }
        printf("\n");
    }
    return 0;
}