#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int distance(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
bool inside(int W, int H, int cx, int cy, int r) {
    return (cx * cx >= r && r <= (W - cx) * (W - cx) && cy * cy >= r && r <= (H - cy) * (H - cy));
}
bool contain(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy) {
    int r1 = distance(Ax, Ay, Bx, By), r2 = distance(Cx, Cy, Dx, Dy), d = distance(Ax, Ay, Cx, Cy);
    ll k = r1 - d - r2;
    return k >= 0 && k * k > 4LL * r2 * d; 
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    int N, W, H, count = 0;
    cin >> N >> W >> H;
    vector<pii> stars(N);
    for(int i = 0; i < N; i++){
        cin >> stars[i].first >> stars[i].second;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                for(int l = 0; l < N; l++){
                    if(i == j || j == k || k == l || i == k || i == l || j == l){
                        continue;
                    }
                    int Ax = stars[i].first, Ay = stars[i].second, Bx = stars[j].first, By = stars[j].second, Cx = stars[k].first, Cy = stars[k].second, Dx = stars[l].first, Dy = stars[l].second;
                    if(contain(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy)){
                        int r1 = distance(Ax, Ay, Bx, By), r2 = distance(Cx, Cy, Dx, Dy);  
                        if (inside(W, H, Ax, Ay, r1) && inside(W, H, Cx, Cy, r2)) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    cout << count << '\n';
    return 0;
}