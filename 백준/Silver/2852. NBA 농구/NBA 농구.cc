#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n, t, m, s, win[3][2] = {0, };
    vector<pair<int, int>> score_log;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d:%d", &t, &m, &s);
        score_log.push_back({t, m * 60 + s});
    }
    score_log.push_back({0, 48 * 60});
    for(int i = 0; i < n; i++){
        win[score_log[i].first][1]++;
        if(win[1][1] != win[2][1]){
            win[win[1][1] > win[2][1] ? 1 : 2][0] += score_log[i + 1].second - score_log[i].second;
        }
    }
    printf("%02d:%02d\n", win[1][0] / 60, win[1][0] % 60);
    printf("%02d:%02d\n", win[2][0] / 60, win[2][0] % 60);
    return 0;
}