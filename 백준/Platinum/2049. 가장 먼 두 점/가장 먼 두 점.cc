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
int main() {
	int n, s, a, b;
	int l, lt;
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
	s = v1.size();
	a = 0;
	b = 1;
	l = length(v1[a], v1[b]);
	for(; a != s;){
	    p1 = {v1[(b + 1) % s].first - v1[b % s].first + v1[(a + 1) % s].first, v1[(b + 1) % s].second - v1[b % s].second + v1[(a + 1) % s].second};
	    ccw(v1[a % s], v1[(a + 1) % s], p1) > 0 ? b++ : a++;
	    lt = length(v1[a % s], v1[b % s]);
	    l = l > lt ? l : lt;
	}
	printf("%d", l);
	return 0;
}