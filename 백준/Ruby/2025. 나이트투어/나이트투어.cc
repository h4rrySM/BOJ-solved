#include <bits/stdc++.h>
using namespace std;
int n;
int visited[670][670] = {0,};
int isin(int i, int j){
    return ((i > -1) && (i < n) && (j > -1) && (j < n));
}
int d[8][2] = {
    {-2, -1},
    {-2, 1},
    {2, -1},
    {2, 1},
    {-1, -2},
    {1, -2},
    {-1, 2},
    {1, 2}
};
int count(int i, int j){
    int c = 0;
    for(int k = 0; k < 8; k++){
        c += (isin(i+d[k][0], j+d[k][1]) && visited[i+d[k][0]][j+d[k][1]] == 0);
    }
    return c;
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pair<int, int>> move;
    int y = 0, x = 0;
    cin >> y >> x;
    y--; 
    x--;
    int l;
    for(l = 0; l < n*n; l++){
        visited[y][x] = 1;
        move.push_back({y, x});
        if(l == n*n - 1){
            break;
        }
        int min = 9, now, ny = -1, nx = -1;
        for(int i = 0; i < 8; i++){
            int ty = y + d[i][0], tx = x + d[i][1];
            if(isin(ty,tx) && visited[ty][tx] == 0){
                now = count(ty,tx);
                if(now < min || (now == min && abs(n-2*ny)+abs(n-2*nx) < abs(n-2*ty)+abs(n-2*tx) )){
                    min = now;
                    ny = ty;
                    nx = tx;
                }
            }
        }
        if(ny == -1 && nx == -1){
            break;
        }
        y = ny;
        x = nx;
    }
    if(move.size() == n*n){
        for(auto &m: move){
            cout << m.first + 1 << " " << m.second + 1 << "\n";
        }
    }else{
        cout << -1 << " " << -1;
    }
    return 0;
}