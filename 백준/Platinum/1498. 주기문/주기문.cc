#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int pi[1000001] = {0, }, l = 1;
    char s[1000001];
    vector<pair<int, int>> v1;
    scanf("%s",s);
    for(int i = 0; s[l] != '\0'; l++){
        for(; i > 0 && s[l] != s[i]; ){
            i = pi[i - 1];
        }
        if(s[l] == s[i]){
            i++;
            pi[l] = i;
        }
    }
    for(int i = 2; i <= l; i++){
        if(i % (i - pi[i - 1]) == 0){
            v1.push_back({i, i / (i - pi[i - 1])});
        }
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < v1.size(); i++){
        if(v1[i].second == 1){
            continue;
        }
        printf("%d %d\n", v1[i].first, v1[i].second);
    }
    return 0;
}