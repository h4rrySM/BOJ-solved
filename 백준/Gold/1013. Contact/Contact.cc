#include <cstdio>
#include <string>
#include <regex>
using namespace std;
int main(){
    int t;
    char c1[201];
    string s1;
    regex ex1("(100+1+|01)+");
    scanf("%d", &t);
    for(; t > 0; t--){
        scanf("%s", c1);
        s1 = c1;
        printf("%s\n", regex_match(s1, ex1) ? "YES" : "NO");
    }
    return 0;
}