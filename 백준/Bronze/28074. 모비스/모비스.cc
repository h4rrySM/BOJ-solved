#include <cstdio>
char mobis[5] = {'M','O','B','I','S'};
int mobis_count[5] = {0, };
int main(){
    int c = 1;
    char str[101];
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++){
        for(int j = 0; j < 5; j++){
            if(str[i] == mobis[j]){
                mobis_count[j] = 1;
            }
        }
    }
    for(int j = 0; j < 5; j++){
        if(mobis_count[j] == 0){
            c = 0;
        }
    }
    printf("%s", c ? "YES" : "NO");
    return 0;
}