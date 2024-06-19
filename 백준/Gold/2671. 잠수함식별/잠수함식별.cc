#include <cstdio>
#include <string>
#include <regex>
using namespace std;
int main(){
    char c1[201];
    string s1;
    regex ex1("(100+1+|01)+");
    scanf("%s", c1);
    s1 = c1;
    printf("%s\n", regex_match(s1, ex1) ? "SUBMARINE" : "NOISE");
    return 0;
}