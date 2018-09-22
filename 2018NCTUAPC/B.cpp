#include <bits/stdc++.h>
using namespace std;
int main() {
    int dp[125][125][45];
    int n; cin >> n;
    memset(dp, 0, sizeof(dp));
    int data[3][2];
    for (int i = 0 ; i < 3 ; i++) cin >> data[i][0] >> data[i][1];
    dp[0][0][0] = 1;
    for (int x = 0 ; x < n ; x++) {
        int p, f, c; 
        cin >> p >> f >> c;
        for (int P = 124 ; P >= p ; P--) {
            for (int F = 124 ; F >= f ; F--) {
                for (int C = 44 ; C >= c ; C--) {
                    dp[P][F][C] += dp[P - p][F - f][C - c];
                }
            }
        }
    }
    long long ans = 0;
    for (int p = data[0][0] ; p <= data[0][1] ; p++) {
        for (int f = data[1][0] ; f <= data[1][1] ; f++) {
            for (int c = data[2][0] ; c <= data[2][1] ; c++) {
                ans += dp[p][f][c];
            }
        }
    }
    cout << ans << '\n';
}
