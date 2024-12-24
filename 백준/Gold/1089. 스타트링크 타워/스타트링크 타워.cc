#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
vector<vs> patterns = {
    {"###", "#.#", "#.#", "#.#", "###"}, 
    {"..#", "..#", "..#", "..#", "..#"}, 
    {"###", "..#", "###", "#..", "###"}, 
    {"###", "..#", "###", "..#", "###"}, 
    {"#.#", "#.#", "###", "..#", "..#."}, 
    {"###", "#..", "###", "..#", "###"}, 
    {"###", "#..", "###", "#.#", "###"}, 
    {"###", "..#", "..#", "..#", "..#"}, 
    {"###", "#.#", "###", "#.#", "###"},  
    {"###", "#.#", "###", "..#", "###"}   
};
bool match(vs board, vs pattern) {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '#' && pattern[i][j] == '.') {
                return false;
            }
        }
    }
    return true; 
}
int main(){ cin.tie(0)->sync_with_stdio(0);
    int N;
    double mean = 0;
    int combi = 1;
    cin >> N;
    vs board(5), current(5);
    vector<vi> numbers;
    numbers.resize(N);
    for(string &s: board){
        cin >> s;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            current[j] = board[j].substr(i * 4, 3); 
        }
        double sum = 0;
        int c = 0;
        for(int d = 0; d <= 9; d++){
            if(match(current, patterns[d])){
                sum += d;
                c++;
            }
        }
        if(!c){
            cout << -1 << '\n';
            return 0;
        }else{
            mean *= c * 10;
            mean += sum * combi;
            combi *= c;

        }
    }
    mean /= combi;
    cout.precision(6);
    cout << fixed << mean << '\n';
    return 0;
}