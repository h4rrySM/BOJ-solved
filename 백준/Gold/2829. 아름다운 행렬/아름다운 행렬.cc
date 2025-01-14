#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int n, res = -1000 * 400 * 2;
    cin >> n;
    vector<vi> mat(n, vi(n, 0)), a(n, vi(n, 0)), b(n, vi(n, 0));
    for(int i = 0; i < n; i++){
        for(auto &j: mat[i]){
            cin >> j;
        }
    }
    for(int i = 0; i < n; i++){
        a[0][i] = mat[0][i];
        b[i][0] = mat[i][0];
        a[i][0] = mat[i][0];
        b[n - 1][i] = mat[n - 1][i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            a[i][j] = a[i - 1][j - 1] + mat[i][j];
            b[n - i - 1][j] = b[n - i][j - 1] + mat[n - i - 1][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n - i + 1; j++){
            for(int k = 0; k < n - i + 1; k++){
                int sa = a[j + i - 1][k + i - 1] - (j == 0 || k == 0 ? 0 : a[j - 1][k - 1]);
                int sb = b[j][k + i - 1] - (j + i == n || k == 0 ? 0 : b[j + i][k - 1]);
                sa -= sb;
                res = res > sa ? res : sa;
            }
        }
    }
    cout << res;
    return 0;
}