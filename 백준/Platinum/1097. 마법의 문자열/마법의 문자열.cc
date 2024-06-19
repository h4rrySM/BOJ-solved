#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int kmp(string s){
    string s1 = s + s;
    string s2 = s;
    int t = 0, l = 1;
    int pi[160] = {0, };
    
    for(int j = 0; l < s2.size(); l++){
        for(; j > 0 && s2[l] != s2[j]; ){
            j = pi[j - 1];
        }
        if(s2[l] == s2[j]){
            j++;
            pi[l] = j;
        }
    }
    for(int i = 0, j = 0; i < s1.size() - 1; i++){
        for(; j > 0 && s1[i] != s2[j]; ){
            j = pi[j - 1];
        }
        if(s1[i] == s2[j]){
            if(j == l - 1){
                t++;
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return t;
}
int main(){
    int n, k, c = 0;
    char c1[21];
    string s1;
    vector<string> v1;
    scanf("%d", &n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        scanf("%s", c1);
        s1 = c1;
        v1.push_back(s1);
    }
    scanf("%d", &k);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    s1 = v1[p[0]];
    for(int i = 1; i < n; i++){
        s1.append(v1[p[i]]);
    }
    c += kmp(s1) == k ? 1 : 0;
    for(; next_permutation(p.begin(), p.end()); ){
        s1 = v1[p[0]];
        for(int i = 1; i < n; i++){
            s1.append(v1[p[i]]);
        }
        c += kmp(s1) == k ? 1 : 0;
    }
    printf("%d", c);
    return 0;
}