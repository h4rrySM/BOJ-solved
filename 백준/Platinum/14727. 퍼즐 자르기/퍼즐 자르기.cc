#include <iostream>
#include <stack>
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define pii pair<int, int>
#define ll long long
using namespace std;
int main(){ IO;
    ll N, H, min_height = 1000001, max_area = 0, area, front_index;
    stack<pii> s1;
    pii p1;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> H;
        min_height = min_height < H ? min_height : H;
        for(; !s1.empty();){
            if(s1.top().first > H){
                p1 = s1.top();
                s1.pop();
                front_index = s1.empty() ? 0 : s1.top().second;
                area = (i - front_index - 1) * p1.first;
                max_area = max_area > area ? max_area : area;
            }else{
                break;
            }
        }
        s1.push({H, i});
    }
    for(; !s1.empty();){
        p1 = s1.top();
        s1.pop();
        front_index = s1.empty() ? 0 : s1.top().second;
        area = (N - front_index) * p1.first;
        max_area = max_area > area ? max_area : area;
    }
    area = min_height * N;
    max_area = max_area > area ? max_area : area;
    cout << max_area << '\n';
    return 0;
}