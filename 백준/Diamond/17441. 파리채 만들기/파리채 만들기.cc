#include <cstdio>
#include <vector>
using namespace std;
double area(vector<double> v1, vector<double> v2){
    double d = 0;
    for(int i = 0; i < (int)v1.size() - 1; i++){
        d += ((v1[i] - v1[0]) * (v2[i + 1] - v2[0]) - (v1[i + 1] - v1[0]) * (v2[i] - v2[0])) / 2;
    }
    return d;
}
double cal(vector<double> v1, vector<double> v2){
    double d = 0;
    int n = v1.size();
    for(int i = 0; i < n; i++){
        d += (v1[(i + 1) % n] - v1[i]) * (v2[(i + 1) % n] * v2[(i + 1) % n] + v2[i] * v2[(i + 1) % n] + v2[i] * v2[i]);
    }
    d /= 6;
    return d;
}
double cal2(vector<double> v1, vector<double> v2){
    double d = 0;
    int n = v1.size();
    for(int i = 0; i < n; i++){
        d += (v1[(i + 1) % n] - v1[i]) * (v2[(i + 1) % n] * v2[(i + 1) % n] * v2[(i + 1) % n] + v2[i] * v2[(i + 1) % n] * v2[(i + 1) % n] + v2[i] * v2[i] * v2[(i + 1) % n] + v2[i] * v2[i] * v2[i]);
    }
    d /= 12;
    return d;
}
int main(){
    int n, x, y;
    double t1, t2, t3;
    vector<double> vx, vy;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        vx.push_back(x);
        vy.push_back(y);
    }
    t1 = area(vx, vy);
    t2 = cal(vx, vy);
    t3 = cal(vy, vx);
    printf("%.7lf", 2 / t1 * ((cal2(vy, vx) - cal2(vx, vy)) - (t2 * t2 + t3 * t3) / t1));
    return 0;
}