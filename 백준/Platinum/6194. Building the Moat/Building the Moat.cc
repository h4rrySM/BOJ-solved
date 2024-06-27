#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int, int>> coord;
long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}
int compare_a(pair<int, int> p1, pair<int, int> p2){
	return ccw(coord[0], p1, p2) > 0;
}
double length(pair<long long, long long> p1, pair<long long, long long> p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
int main() {
	int n, x, y;
	pair<int, int> p1, p2;
	vector<pair<int, int>> v1;
	double len = 0;
    scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		coord.push_back({x, y});   
	}
	sort(coord.begin(), coord.end());
	sort(coord.begin() + 1, coord.end(), compare_a);
	v1.push_back(coord[0]);
	v1.push_back(coord[1]);
	for(int i = 2; i < (int)coord.size(); i++){
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
	for(int i = 1; i < (int)v1.size(); i++){
	    len += length(v1[i-1], v1[i]);
	}
	len += length(v1[v1.size() - 1], v1[0]);
	printf("%.2lf", len);
	return 0;
}