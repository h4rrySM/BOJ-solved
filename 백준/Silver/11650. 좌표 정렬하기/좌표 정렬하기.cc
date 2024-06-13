#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,x,y;
    vector<pair<int,int>> v1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        v1.push_back({x,y});
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<n;i++){
        printf("%d %d\n",v1[i].first,v1[i].second);
    }
    return 0;
}