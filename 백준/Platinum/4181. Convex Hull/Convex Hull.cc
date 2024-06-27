#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> coord;
long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}
double length(pair<long long, long long> p1, pair<long long, long long> p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int compare_a(pair<int, int> p1, pair<int, int> p2){
	long long a = ccw(coord[0], p1, p2);
	return a ? a > 0 : p1.second > p2.second;
}
int main() {
	int n, x, y;
	char c;
	pair<int, int> p1, p2;
	vector<pair<int, int>> v1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %c", &x, &y, &c);
		if(c == 'Y'){
		    coord.push_back({x, y});   
		}
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
			if(ccw(p2, p1, coord[i]) >= 0){
				v1.push_back(p1);
				break;
			}
		}
		v1.push_back(coord[i]);
	}
	printf("%d\n", (int)v1.size());
	for(int i = 0; i < (int)v1.size(); i++){
	    printf("%d %d\n", v1[i].first, v1[i].second);
	}
	return 0;
}