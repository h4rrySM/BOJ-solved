#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
int main(){ cin.tie(0)->sync_with_stdio(0);
    int k, n, score = 0;
    int A[100001], B[100001], output[3][100000], pieces[4][4][100000], c[4][4];
    cin >> k >> n;
    for(int i = 1; i <= k; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= k; i++){
        cin >> B[i];
        pieces[A[i]][B[i]][c[A[i]][B[i]]++] = i;
    }
    int p = 0;
    for(int k = 0; k < c[3][3]; k++){
        for(int u = 0; u < 3; u++){
            for(int v = 0; v < 3; v++){
                output[u][p + v] = pieces[3][3][k];
            }
        }
        p += 3;  
    }
    for(int k = 0; k < c[2][3]; k++){
        for(int u = 0; u < 3; u++){
            for(int v = 0; v < 2; v++){
                output[u][p + v] = pieces[2][3][k];
            }
        }
        p += 2;  
    }
    int t = p;
    for(int k = 0; k < c[2][2]; k++){
        for(int u = 0; u < 2; u++){
            for(int v = 0; v < 2; v++){
                output[u][p + v] = pieces[2][2][k];
            }
        }
        p += 2;  
    }
    int width = 0, shape1 = 0, shape2 = 0, shape3 = 0;
    for(; width < 2 * c[2][2]; ){
        if(shape2 < c[1][2]){
            output[2][width + t] = pieces[1][2][shape2];
            output[2][width + t + 1] = pieces[1][2][shape2++];
            width += 2;
        }else if(shape3 < c[1][3] && width + 3 <= 2 * c[2][2]){
            output[2][width + t] = pieces[1][3][shape3];
            output[2][width + t + 1] = pieces[1][3][shape3];
            output[2][width + t + 2] = pieces[1][3][shape3++];
            width += 3;
        }else if(width < 2 * c[2][2]){
            output[2][width + t] = pieces[1][1][shape1++];
            width++;
        }
    }
    for(; shape3 < c[1][3];){
        output[0][p] = pieces[1][3][shape3];
        output[1][p] = pieces[1][3][shape3];
        output[2][p] = pieces[1][3][shape3++];
        p++;
    }
    for(; shape2 + 3 <= c[1][2]; ){
        output[0][p] = pieces[1][2][shape2];
        output[0][p + 1] = pieces[1][2][shape2];
        output[1][p] = pieces[1][2][shape2 + 1];
        output[1][p + 1] = pieces[1][2][shape2 + 1];
        output[2][p] = pieces[1][2][shape2 + 2];
        output[2][p + 1] = pieces[1][2][shape2 + 2];
        shape2 += 3;
        p += 2;
    }
    for(; shape1 + 3 <= c[1][1]; ){
        output[0][p] = pieces[1][1][shape1];
        output[1][p] = pieces[1][1][shape1 + 1];
        output[2][p] = pieces[1][1][shape1 + 2];
        shape1 += 3;
        p++;
    }
    for(; shape2 < c[1][2]; ){
        output[0][p] = pieces[1][2][shape2];
        output[1][p] = pieces[1][2][shape2];
        output[2][p] = pieces[1][1][shape1];
        shape1++;
        shape2++;
        p++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << output[i][j] << ' ';
        }
        cout << output[i][n - 1] << '\n';
    }
    return 0;
}