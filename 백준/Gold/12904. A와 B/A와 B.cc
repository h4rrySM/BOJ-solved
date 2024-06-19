#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    char s[1000],t[1001];
    string s1, s2;
    scanf("%s\n%s", s, t);
    s1 = s;
    s2 = t;
    for(; s1.size() != s2.size(); ){
        if(s2[s2.size() - 1] == 'A'){
            s2.pop_back();
        }else{
            s2.pop_back();
            reverse(s2.begin(), s2.end());
        }
    }
    printf("%d", s1.compare(s2) == 0 ? 1 : 0);
    return 0;
}