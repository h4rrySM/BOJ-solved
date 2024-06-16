#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main(){
    int n, m;
    char name[21];
    string s1;
    map<string, int> m1;
    vector<string> v1;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", name);
        s1 = name;
        m1[s1] = 1;
    }
    for(int i = 0; i < m; i++){
        scanf("%s", name);
        s1 = name;
        if(m1[s1] == 1){
            v1.push_back(s1);
        }
    }
    sort(v1.begin(), v1.end());
    printf("%d\n", (int)v1.size());
    for(int i = 0; i < (int)v1.size(); i++){
        printf("%s\n", v1[i].c_str());
    }
    return 0;
}