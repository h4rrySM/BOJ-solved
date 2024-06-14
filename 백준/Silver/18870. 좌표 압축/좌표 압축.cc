#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,x;
    vector<int> v1,v2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        v1.push_back(x);
    }
    v2 = v1;
    sort(v2.begin(),v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    for(int i=0;i<v1.size();i++){
        printf("%ld ",distance(v2.begin(),lower_bound(v2.begin(),v2.end(),v1[i])));
    }
    return 0;
}