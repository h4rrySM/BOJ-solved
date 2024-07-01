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
	int n, x, y, s, c;
	double l, lt, lm;
	vector<pair<int, int>> v1;
	pair<int, int> p1, p2;
	for(int i = 1;; i++){
	    lm = -1;
	    coord.clear();
        v1.clear();
	    scanf("%d", &n);
	    if(n == 0){
	        break;
	    }
    	for(int i = 0; i < n; i++){
    		scanf("%d %d", &x, &y);
    		coord.push_back({x, y});
    	}
    	sort(coord.begin(), coord.end(), compare_y);
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
    	for(int i = 0; i < s; i++){
    	    l = 0;
    	    for(int j = 0; j < s; j++){
    	        lt = ccw(v1[i], v1[(i + 1) % s], v1[j]);
    	        lt *= lt > 0 ? 1 : -1;
    	        lt /= length(v1[i], v1[(i + 1) % s]);
    	        l = l > lt ? l : lt;
    	    }
    	    if(lm == -1){
    	        lm = l;
    	    }else{
    	        lm = lm < l ? lm : l;
    	    }
    	}
    	lm = ceil(100 * lm) / 100;
    	printf("Case %d: %.2lf\n", i, lm);
	}
	return 0;
}