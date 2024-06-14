#include <cstdio>
using namespace std;
int main(){
    int r, c, p = 1, q = 1, s = 0;
    char map[11][11] = {0,};
    char map2[11][11] = {0,};
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++){
        scanf("%s", map[i]+1);
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(map[i][j] == 'X' && ((map[i-1][j] != 'X') + (map[i+1][j] != 'X') + (map[i][j-1] != 'X') + (map[i][j+1] != 'X')) >= 3){
                map2[i][j] = '.';
            }else{
                map2[i][j] = map[i][j];
            }
        }
    }
    for(s = 0; s == 0; q++, c--){
        for(int i = p; i <= p + r - 1; i++){
            if(map2[i][q] != '.'){
                s = 1;
                break;
            }
        } 
    }
    q--;
    c++;
    
    for(s = 0; s == 0; c--){
        for(int i = p; i <= p + r - 1; i++){
            if(map2[i][q + c - 1] != '.'){
                s = 1;
                break;
            }
        } 
    }
    c++;
    
    for(s = 0; s == 0; p++, r--){
        for(int i = q; i <= q + c - 1; i++){
            if(map2[p][i] != '.'){
                s = 1;
                break;
            }
        } 
    }
    p--;
    r++;
    
    for(s = 0; s == 0; r--){
        for(int i = q; i <= q + c - 1; i++){
            if(map2[p + r - 1][i] != '.'){
                s = 1;
                break;
            }
        } 
    }
    r++;
    
    
    for(int i = p; i <= p + r - 1; i++){
        for(int j = q; j <= q + c - 1; j++){
            printf("%c", map2[i][j]);
        }
        printf("\n");
    }
    return 0;
}