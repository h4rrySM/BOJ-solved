#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
vector<pair<int, int>> coord;
int compare_y(pair<int, int> p1, pair<int, int> p2){
    return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
}
long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}
double length(pair<long long, long long> p1, pair<long long, long long> p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
int compare_a(pair<int, int> p1, pair<int, int> p2){
	long long a = ccw(coord[0], p1, p2);
	return a ? a > 0 : length(coord[0], p1) < length(coord[0], p2);
}
int main() {
	int n, x, y;
	pair<int, int> p1, p2;
	stack<pair<int, int>> s1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		coord.push_back({x, y});
	}
	sort(coord.begin(), coord.end(), compare_y);
	sort(coord.begin() + 1, coord.end(), compare_a);
	s1.push(coord[0]);
	s1.push(coord[1]);
	for(int i = 2; i < n; i++){
		for(; s1.size() >= 2; ){
			p1 = s1.top();
			s1.pop();
			p2 = s1.top();
			if(ccw(p2, p1, coord[i]) > 0){
				s1.push(p1);
				break;
			}
		}
		s1.push(coord[i]);
	}
	printf("%d", (int)s1.size());
	return 0;
}