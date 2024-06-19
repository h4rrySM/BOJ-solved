#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int c = 0;
int f(string s1, string s2){
    string s3 = s2;
    if(s1.size() == s2.size()){
        if(s1.compare(s2) == 0){
            c = 1;
        }   
        return 0;
    }
    if(s2[s2.size() - 1] == 'A'){
        s2.pop_back();
        f(s1, s2);
    }
    if(s3[0] == 'B'){
        reverse(s3.begin(), s3.end());
        s3.pop_back();
        f(s1, s3);
    }
    return 0;
}
int main(){
    char s[50],t[51];
    string s1, s2;
    scanf("%s\n%s", s, t);
    s1 = s;
    s2 = t;
    f(s1, s2);
    printf("%d", c);
    return 0;
}