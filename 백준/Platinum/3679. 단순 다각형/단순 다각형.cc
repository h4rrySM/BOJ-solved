#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, int>> coord;
long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}
int compare_xy(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    return p1.first.first == p2.first.first ? p1.first.second < p2.first.second : p1.first.first < p2.first.first;
}
double length(pair<long long, long long> p1, pair<long long, long long> p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int compare_a(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
	long long a = ccw(coord[0].first, p1.first, p2.first);
	return a ? a > 0 : length(coord[0].first, p1.first) < length(coord[0].first, p2.first);
}
int main() {
	int n, x, y, t, c;
	scanf("%d", &c);
	for(; c > 0; c--){
	    coord.clear();
	    scanf("%d", &n);
    	for(int i = 0; i < n; i++){
    		scanf("%d %d", &x, &y);
    		coord.push_back({{x, y}, i});   
    	}
    	sort(coord.begin(), coord.end(), compare_xy);
    	sort(coord.begin() + 1, coord.end(), compare_a);
    	for(t = n - 2; t >= 0; t--){
    		if(ccw(coord[0].first, coord[t].first, coord[t + 1].first)){
    		    break;
    		}
    	}
    	reverse(coord.begin() + t + 1, coord.end());
        printf("%d", coord[0].second);
    	for(int i = 1; i < n; i++){
    	    printf(" %d", coord[i].second);
    	}
        printf("\n");
    }
	return 0;
}