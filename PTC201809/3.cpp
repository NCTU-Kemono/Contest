#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int dp[MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        memset(dp, 0, sizeof(dp));
        string a, b; cin >> a >> b;
        for (int i = 0 ; i <= a.size() ; i++)
            dp[i][0] = i;
        for (int i = 0 ; i <= b.size() ; i++)
            dp[0][i] = i;
        for (int i = 1 ; i <= a.size() ; i++) {
            for (int j = 1 ; j <= b.size() ; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
                }
            }
        }
        cout << dp[a.size()][b.size()] << '\n';
    }
}
