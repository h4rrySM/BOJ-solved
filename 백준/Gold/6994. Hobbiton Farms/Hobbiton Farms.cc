#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t; 
    for(int i = 0; i < t; i++){
        double r, xc, yc, xl, yl, xu, yu;
        cin >> r >> xc >> yc >> xl >> yl >> xu >> yu;
        double closest_x = max(xl, min(xc, xu)), closest_y = max(yl, min(yc, yu));
        double distance = sqrt((xc - closest_x) * (xc - closest_x) + (yc - closest_y) * (yc - closest_y));
        if(distance <= r){
            cout << "The given circle and rectangle overlap.\n";
        }else{
            cout << "The given circle and rectangle do not overlap.\n";
        }
    }
    return 0;
}