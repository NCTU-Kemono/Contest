#include <bits/stdc++.h>
using namespace std;
typedef pair<int, long long> pii;
#define F first
#define S second
const int MAXN = 5e4 + 5;
const long long INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while (T--) {
        int n, m, f, s, t; cin >> n >> m >> f >> s >> t;
        vector<vector<pii> > G(n);
        for (int i = 0 ; i < m ; i++) {
            int u, v, c; cin >> u >> v >> c;
            G[u].push_back(make_pair(v, c));
            G[v].push_back(make_pair(u, c));
        }
        for (int i = 0 ; i < f ; i++) {
            int u, v; cin >> u >> v;
            G[u].push_back(make_pair(v, 0));
        }
        long long d[MAXN];
        memset(d, INF, sizeof(d));
        queue<pair<int, int> > q; q.push(make_pair(s, 0)); d[s] = 0;
        while (q.size()) {
            pair<int, int> p = q.front(); q.pop();
            for (auto e : G[p.F]) {
                if (e.S == 0 && p.S == 1) continue;
                if (d[p.F] + e.S < d[e.F]) {
                    d[e.F] = d[p.F] + e.S;
                    if (e.S == 0) q.push(make_pair(e.F, 1));
                    else q.push(make_pair(e.F, p.S));
                }
            }
        }
        cout << d[t] << '\n';
    }
}
