#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int n, x, y, index = 0, count1 = 0, count2 = 0, min_x, min_y, start_index = 0, c = 0;
    vector<pair<long long, long long>> point, intersect, check;
    cin >> n;
    cin >> x >> y;
    point.push_back({x, y});
    min_x = x;
    min_y = y;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        point.push_back({x, y});
        if(x < min_x){
            min_x = x;
            min_y = y;
            start_index = i;
        }else if(x == min_x && y < min_y){
            min_y = y;
            start_index = i;
        }
    }   
    for(int i = 0; i < n; i++){
        if(point[(i + start_index) % n].first == point[(i + start_index + 1) % n].first && point[(i + start_index) % n].second * point[(i + start_index + 1) % n].second < 0 && c == 0){
            intersect.push_back({point[(i + start_index) % n].first, 0});
            c = 1;
        }else if(c == 1){
            if(point[(i + start_index) % n].first == point[(i + start_index + 1) % n].first && point[(i + start_index) % n].second * point[(i + start_index + 1) % n].second < 0){
                intersect.push_back({point[(i + start_index) % n].first, 0});
                if(intersect.size() % 2 == 0){
                    if(intersect[intersect.size() - 1].first > intersect[intersect.size() - 2].first){
                        intersect[intersect.size() - 2] = {intersect[intersect.size() - 2].first, 0};
                        intersect[intersect.size() - 1] = {intersect[intersect.size() - 1].first, 1};
                    }else{
                        intersect[intersect.size() - 2] = {intersect[intersect.size() - 2].first, 1};
                        intersect[intersect.size() - 1] = {intersect[intersect.size() - 1].first, 0};
                    }
                }
            }
        }
    }
    sort(intersect.begin(), intersect.end());
    for(int i = 0; i < (int)intersect.size(); i++, index++){
        check.push_back({intersect[i].second, i});
        if(check.size() >= 2 && check[index - 1].first != check[index].first){
            if(check.size() == 2){
                count1++;
            }
            if(check[index - 1].second + 1 == check[index].second){
                count2++;
            }
            check.pop_back();
            check.pop_back();
            index -= 2;
        }
    }
    cout << count1 << ' ' << count2 << '\n';
    return 0;
}