#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int p[1001] = {0,};
double get_length(pair<long long, long long> p1, pair<long long, long long> p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
int get_parent(int a){
    p[a] = p[a] == a ? a : get_parent(p[a]);
    return p[a];
}
int main(){
    int n, m, x, y;
    vector<pair<int, int>> coord;
    vector<pair<double, pair<int, int>>> g;
    double min_length = 0;
    for(int i = 1; i <= 1000; i++){
        p[i] = i;
    }
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        coord.push_back({x, y});
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        p[get_parent(x)] = get_parent(y);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            g.push_back({get_length(coord[i], coord[j]), {i + 1, j + 1}});
        }
    }
    sort(g.begin(), g.end());
    for(int i = 0; i < (int)g.size(); i++){
        x = g[i].second.first;
        y = g[i].second.second;
        if(get_parent(x) != get_parent(y)){
            p[get_parent(x)] = get_parent(y);
            min_length += g[i].first;
        }
    }
    printf("%.2lf", min_length);
    return 0;
}