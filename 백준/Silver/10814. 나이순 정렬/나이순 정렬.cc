#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int f(pair<int,string> p1, pair<int,string> p2){
    return p1.first < p2.first;
}
int main(){
    int n,age;
    char name[101];
    string s1;
    vector<pair<int,string>> v1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %s",&age,name);
        s1 = name;
        v1.push_back({age,s1});
    }
    stable_sort(v1.begin(),v1.end(),f);
    for(int i=0;i<n;i++){
        printf("%d %s\n",v1[i].first,v1[i].second.c_str());
    }
    return 0;
}