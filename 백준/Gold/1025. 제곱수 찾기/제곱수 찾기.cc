#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int n, m, s1, d, s = -1;
    char num[10][10];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", num[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < m; l++){
                    if(k == 0 && l == 0){
                        if((int)floor(sqrt(num[i][j] - 48)) * (int)floor(sqrt(num[i][j] - 48)) == num[i][j] - 48){
                            s = s > num[i][j] - 48 ? s : num[i][j] - 48;
                        }
                        continue;
                    }
                    d = 1;
                    s1 = 0;
                    for(int o = i, p = j; o < n && p < m; o += k, p += l, d *= 10){
                        s1 += (num[o][p] - 48) * d; 
                        if((int)floor(sqrt(s1)) * (int)floor(sqrt(s1)) == s1){
                            s = s > s1 ? s : s1;
                        }
                    }
                    d = 1;
                    s1 = 0;
                    for(int o = i, p = j; o >= 0 && p >= 0; o -= k, p -= l, d *= 10){
                        s1 += (num[o][p] - 48) * d; 
                        if((int)floor(sqrt(s1)) * (int)floor(sqrt(s1)) == s1){
                            s = s > s1 ? s : s1;
                        }
                    }
                    d = 1;
                    s1 = 0;
                    for(int o = i, p = j; o < n && p >= 0; o += k, p -= l, d *= 10){
                        s1 += (num[o][p] - 48) * d; 
                        if((int)floor(sqrt(s1)) * (int)floor(sqrt(s1)) == s1){
                            s = s > s1 ? s : s1;
                        }
                    }
                    d = 1;
                    s1 = 0;
                    for(int o = i, p = j; o >= 0 && p < m; o -= k, p += l, d *= 10){
                        s1 += (num[o][p] - 48) * d; 
                        if((int)floor(sqrt(s1)) * (int)floor(sqrt(s1)) == s1){
                            s = s > s1 ? s : s1;
                        }
                    }
                }
            }
        }
    }
    printf("%d", s);
    return 0;
}