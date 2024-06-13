#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int f(string s1, string s2){
    if(s1.size() != s2.size()){
        return s1.size() < s2.size();
    }else{
        return s1 < s2;
    }
}
int main(){
    int n;
    char w[101];
    string s1;
    vector<string> v1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",w);
        s1 = w;
        v1.push_back(s1);
    }
    sort(v1.begin(),v1.end(),f);
    printf("%s\n",v1[0].c_str());
    for(int i=1;i<n;i++){
        if(v1[i]!=v1[i-1]){
            printf("%s\n",v1[i].c_str());
        }
    }
    return 0;
}