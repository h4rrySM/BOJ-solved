#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int N, height, number_meerkat = 0, temp_number = 0, temp_l_height = 0, temp_r_height = 0, r = 0, l = 0;
    char direction;
    vector<char> directions;
    vector<int> l_meerkat, r_meerkat;
    cin >> N;
    vector<int> order(N);
    for(int i = 0; i < N; i++){
        cin >> height >> direction;
        if(direction == 'L'){
            l_meerkat.push_back(height);
        }else{
            r_meerkat.push_back(height);
        }
        directions.push_back(direction);
    }
    sort(l_meerkat.begin(),l_meerkat.end());
    sort(r_meerkat.begin(),r_meerkat.end());
    for(int i = 0; i <= N; i++){
        r = 0;
        l = 0;
        temp_number = 0;
        temp_l_height = 0;
        temp_r_height = 0;
        for(int j = N - 1; j >= i; j--){
            if(directions[j] == 'L'){
                order[j] = l_meerkat[l++];
            }
        }
        for(int j = 0; j < i; j++){
            order[j] = directions[j] == 'L' ? l_meerkat[l++] : r_meerkat[r++];
        }
        for(int j = N - 1; j >= i; j--){
            if(directions[j] == 'R'){
                order[j] = r_meerkat[r++];
            }
        }
        for(int j = 0; j < N; j++){
            if(directions[j] == 'L' && temp_l_height < order[j]){
                temp_number++;
            }
            if(directions[N - 1 - j] == 'R' && temp_r_height < order[N - 1 - j]){
                temp_number++;
            }
            temp_l_height = temp_l_height > order[j] ? temp_l_height : order[j];
            temp_r_height = temp_r_height > order[N - 1 - j] ? temp_r_height : order[N - 1 - j];   
        }
        number_meerkat = number_meerkat > temp_number ? number_meerkat : temp_number;
    }
    cout << number_meerkat << '\n';
    return 0;
}