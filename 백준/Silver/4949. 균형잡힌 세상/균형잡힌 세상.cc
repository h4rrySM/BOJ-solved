#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    string str;
    for(getline(cin, str); str[0] != '.'; getline(cin, str)){
        stack<char> st;
        int k = 0;
        for(int i = 0; i < str.length() - 1; i++){
            if(str[i] == '(' || str[i] == '['){
                st.push(str[i]);
            }else if(str[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    k = 1;
                    break;
                }
            }else if(str[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    k = 1;
                    break;
                }
            }
        }
        if(st.empty() && k == 0){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
    return 0;
}