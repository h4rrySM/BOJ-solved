#include <iostream>
#include <vector>
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){ IO;
    int k, min_weight = -5;
    vector<pair<pair<int, int>, int>> graph;
    cin >> k;
    if(k == 2){
        cout << 4 << '\n';
        graph.push_back({{1, 2}, 0});
        graph.push_back({{2, 3}, -1});
        graph.push_back({{3, 4}, -2});
        graph.push_back({{3, 1}, -3});
        graph.push_back({{1, 4}, -4});
        graph.push_back({{4, 2}, -5});
    }else{
        cout << (1 << (k - 3)) * 3 + 1 << '\n';
        graph.push_back({{1, 2}, 0});
        graph.push_back({{2, 3}, -3});
        graph.push_back({{3, 4}, -5});
        for(int vertices = 4, forest_score = 3, weight = -4; forest_score < k; forest_score++){
            for(int i = 1; i <= vertices - 1;){
                graph.push_back({{vertices + i, i++}, weight - 2}); 
                weight -= 2;
                min_weight--; 
            }
            vertices = 2 * vertices - 1;
        }
        graph.push_back({{3, 1}, -1});
        graph.push_back({{1, 4}, -2});
        graph.push_back({{4, 2}, -4});
        for(int vertices = 4, forest_score = 3, weight = -5; forest_score < k; forest_score++){
            for(int i = 1; i <= vertices - 1;){
                graph.push_back({{vertices + i, ++i}, weight - 2});
                weight -= 2;
                min_weight--;   
            }
            vertices = 2 * vertices - 1;
        }
    }
    for(pair<pair<int, int>, int> p: graph){
        cout << p.first.first << ' ' << p.first.second << ' ' << p.second + 1 - min_weight << '\n';
    }
    return 0;
}