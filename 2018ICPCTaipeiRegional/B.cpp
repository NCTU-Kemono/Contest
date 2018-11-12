#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 205;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        LL d[MAXN][MAXN]; memset(d, INF, sizeof(d));
        for (int i = 1 ; i <= n ; i++)
            d[i][i] = 0;
        for (int i = 0 ; i < m ; i++) {
            int u, v; LL w;
            cin >> u >> v >> w;
            d[u][v] = min(d[u][v], w);
            d[v][u] = min(d[v][u], w);
        }
        for (int k = 1 ; k <= n ; k++)
            for (int i = 1 ; i <= n ; i++)
                for (int j = 1 ; j <= n ; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


        LL ans[MAXN]; memset(ans, INF, sizeof(ans));

        for (int i = 1 ; i <= n ; i++) { // good
            for (int j = 1 ; j <= n ; j++) {
                if (i == j) continue;
                LL sum = 0;
                for (int k = 1 ; k <= n ; k++)
                    if (d[i][k] <= d[j][k])
                        sum++;
                ans[i] = min(ans[i], sum);
            }
        }
        LL output = -1;
        for (int i = 1 ; i <= n ; i++)
            output = max(output, ans[i]);
        cout << output << '\n';
    }

}
