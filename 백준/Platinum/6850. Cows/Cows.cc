#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> coord;
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}
int length(pair<int, int> p1, pair<int, int> p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int compare_a(pair<int, int> p1, pair<int, int> p2){
	long long a = ccw(coord[0], p1, p2);
	return a ? a > 0 : length(coord[0], p1) < length(coord[0], p2);
}
double area(vector<pair<int, int>> v1){
    double d = 0;
    for(int i = 0; i < (int)v1.size() - 1; i++){
        d += ((v1[i].first - v1[0].first) * (v1[i + 1].second - v1[0].second) - (v1[i + 1].first - v1[0].first) * (v1[i].second - v1[0].second)) / 2.0;
    }
    return d;
}
int main() {
	int n, a, b;
	vector<pair<int, int>> v1;
	pair<int, int> p1, p2;
    scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		coord.push_back({a, b});
	}
	sort(coord.begin(), coord.end());
	sort(coord.begin() + 1, coord.end(), compare_a);
	v1.push_back(coord[0]);
	v1.push_back(coord[1]);
	for(int i = 2; i < n; i++){
		for(; v1.size() >= 2; ){
			p1 = v1.back();
			v1.pop_back();
			p2 = v1.back();
			if(ccw(p2, p1, coord[i]) > 0){
				v1.push_back(p1);
				break;
			}
		}
		v1.push_back(coord[i]);
	}
	printf("%.0lf", area(v1) / 50 - 0.5);
	return 0;
}