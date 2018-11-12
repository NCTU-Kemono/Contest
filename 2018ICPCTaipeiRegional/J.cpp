#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 5;
const LL INF = 0x3f3f3f3fLL;
struct F {
    LL a, b; F() { a = 0, b = 1; }
    F(LL a, LL b) : a(a), b(b) {
        if (b < 0) {
            b *= -1;
            a *= -1;
        }
        trim();
    }
    void trim() {
        LL g = __gcd(abs(a), abs(b));
        a /= g; b /= g;
    }
};
F max(F a, F b) {
    LL g = __gcd(abs(a.b), abs(b.b));
    LL l = a.b * b.b / g;
    if (a.a * l / a.b < b.a * l / b.b) return b;
    else return a;
}
F min(F a, F b) {
    LL g = __gcd(abs(a.b), abs(b.b));
    LL l = a.b * b.b / g;
    if (a.a * l / a.b > b.a * l / b.b) return b;
    else return a;
}
struct Edge {
    LL u, v, w;
};
F MMC(vector<vector<Edge> > &G) {
    int n = G.size(); G.resize(n + 1);
    for (int i = 0 ; i < n ; i++)
        G[n].push_back({n, i, 0});
    LL d[MAXN][MAXN];
    int s = n++;
    for (int i= 0 ; i <= n ; i++)
        for (int j = 0 ; j < n ; j++)
            d[i][j] = INF;
    d[0][s] = 0;
    for (int k = 0 ; k < n ; k++)
        for (int i = 0 ; i < n ; i++)
            for (auto p : G[i])
                if (d[k][i] + p.w < d[k + 1][p.v])
                    d[k + 1][p.v] = d[k][i] + p.w;


    F ans = F(INF, 1);
    // double ans = INF;
    for (int i = 0 ; i < n ; i++) {
        if (d[n][i] == INF) continue;
        F maxW = F(-INF, 1);
        // double maxW = -INF;
        for (int k = 0 ; k < n - 1 ; k++) {
            maxW = max(maxW, F(d[n][i] - d[k][i], n - k));
            // maxW = max(maxW, (double)(d[n][i] - d[k][i]) / (n - k));
        }
        ans = min(ans, maxW);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<Edge> > G(n);
        for (int i = 0 ; i < m ; i++) {
            LL u, v, w; cin >> u >> v >> w;
            u--, v--;
            G[u].push_back({u, v, w});
        }
        // double ans = MMC(G);
        // cout << ans << '\n';
        F ans = MMC(G);
        if (ans.a == INF && ans.b == 1) cout << -1 << '\n';
        else cout << ans.a << ' ' << ans.b << '\n';
    }
}
