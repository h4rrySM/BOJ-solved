#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int N, animal_number, l_pos, r_pos;
    vector<pair<int, int>> animal_info;
    vector<int> v1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> animal_number >> l_pos >> r_pos;
        animal_info.push_back({l_pos, -r_pos});
    }
    sort(animal_info.begin(), animal_info.end());
    animal_info.erase(unique(animal_info.begin(), animal_info.end()), animal_info.end());
    v1.push_back(-animal_info[0].second);
    for(int i = 1; i < N; i++){
        int start = 0, end = v1.size() - 1, mid;
        for(; start <= end;){
            mid = (start + end) / 2;
            if(v1[mid] >= -animal_info[i].second){
                start = mid + 1;
            }else if(v1[mid] < -animal_info[i].second){
                end = mid - 1;
            }
        }
        if(start > v1.size() - 1){
            v1.push_back(-animal_info[i].second);
        }else{
            v1[start] = -animal_info[i].second;
        }
    }
    cout << v1.size() << '\n';
    return 0;
}