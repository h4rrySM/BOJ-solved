#include <cstdio>
using namespace std;
int main(){
    int n;
    char s[21];
    scanf("%d", &n);
    for(; n > 0; n--){
        scanf("%s", s);
        for(int i = 0; s[i] != '\0'; i++){
            s[i] += s[i] <= 90 ? 32 : 0;
        }
        printf("%s\n", s);
    }
    return 0;
}