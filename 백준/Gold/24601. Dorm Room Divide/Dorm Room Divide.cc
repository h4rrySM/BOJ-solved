#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pdd = pair<double, double>;
typedef struct{
    ll x, y;
} COORD;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n;
    vector<COORD> vertices;
    cin >> n;
    vertices.resize(n);
    for (COORD &i: vertices) {
        cin >> i.x >> i.y;
    }
    pdd result;
    ld total = 0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        total += vertices[i].x * vertices[j].y;
        total -= vertices[j].x * vertices[i].y;
    }
    total = fabs(total / 2.0);
    ld half = total / 2.0, s = 0;
    COORD door = vertices[0];
    for(int i = 1; i < n; i++){
        int j = i, next_j = (i + 1) % n;
        ll x1 = door.x, y1 = door.y, x2 = vertices[j].x, y2 = vertices[j].y, x3 = vertices[next_j].x, y3 = vertices[next_j].y;
        ld ds = fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
        s += ds;
        if(s >= half){
            if(s == half){
                result = {vertices[next_j].x, vertices[next_j].y};
                break;
            }else{
                ld ratio = (half - (s - ds)) / ds;
                result = {x2 + ratio * (x3 - x2), y2 + ratio * (y3 - y2)};
                break;
            }
        }
    }
    cout.precision(6);
    cout << fixed << result.first << " " << result.second << '\n';
    return 0;
}