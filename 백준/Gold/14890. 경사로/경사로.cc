#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, l, con, ans = 0, check;
    cin >> n >> l;
    int paths[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paths[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        con = 1;
        check = 1;
        if(n == 1){
            ans++;
            continue;
        }
        for(int j = 0; j < n - 1; j++){
            if(paths[i][j] == paths[i][j + 1]){
                con++;
            }else if(paths[i][j] + 1 == paths[i][j + 1]){
                if(con < l){
                    check = 0;
                    break;
                }
                con = 1;
            }else if(paths[i][j] == paths[i][j + 1] + 1){
                con = 1;
                j++;
                int k;
                for(k = j; k < j + l - 1 && k < n - 1; k++){
                    if(paths[i][k] == paths[i][k + 1]){
                        con++;
                    }else{
                        check = 0;
                        break;
                    }
                }
                j = k - 1;
                if(con < l){
                    check = 0;
                    break;
                }
                con = 0;
            }else{
                check = 0;
                break;
            }
        }
        if(check){
            ans++;
        }
    }
    for(int i = 0; i < n; i++){
        con = 1;
        check = 1;
        if(n == 1){
            ans++;
            continue;
        }
        for(int j = 0; j < n - 1; j++){
            if(paths[j][i] == paths[j + 1][i]){
                con++;
            }else if(paths[j][i] + 1 == paths[j + 1][i]){
                if(con < l){
                    check = 0;
                    break;
                }
                con = 1;
            }else if(paths[j][i] == paths[j + 1][i] + 1){
                con = 1;
                j++;
                int k;
                for(k = j; k < j + l - 1 && k < n - 1; k++){
                    if(paths[k][i] == paths[k + 1][i]){
                        con++;
                    }else{
                        check = 0;
                        break;
                    }
                }
                j = k - 1;
                if(con < l){
                    check = 0;
                    break;
                }
                con = 0;
            }else{
                check = 0;
                break;
            }
        }
        if(check){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}