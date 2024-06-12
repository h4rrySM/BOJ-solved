#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int pi[1000001]={0,},c=0,l=1;
    string t,p;
    vector<int> v1;
    getline(cin,t);
    getline(cin,p);
    for(int j=0;p[l]!='\0';l++){
        for(;j>0 && p[l]!=p[j];){
            j = pi[j-1];
        }
        if(p[l]==p[j]){
            j++;
            pi[l]=j;
        }
    }
    for(int i=0,j=0;t[i]!='\0';i++){
        for(;j>0 && t[i]!=p[j];){
            j = pi[j-1];
        }
        if(t[i]==p[j]){
            if(j==l-1){
                c++;
                v1.push_back(i-l+2);
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    cout << c << '\n';
    for(int i=0;i<c;i++){
        cout << v1[i] << '\n';
    }
    return 0;
}