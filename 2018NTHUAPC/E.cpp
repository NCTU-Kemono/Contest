#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second
const int MAXN = 5e4 + 5;
const int INF = 0x3f3f3f3f;
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
            G[v].push_back(make_pair(u, 0));
        }
        int d[MAXN];
        memset(d, INF, sizeof(d));
        // (dist, node)
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(make_pair(0, s)); d[s] = 0;
        int vis[MAXN], cnt = 0; memset(vis, false, sizeof(vis));
        while (cnt != n) {
            pii p;
            do {
                p = pq.top(); pq.pop();
            } while (vis[p.S]);
            cnt++;
            vis[p.S] = true;
            for (auto e : G[p.S]) {
                if (d[p.S] + e.S < d[e.F]) {
                    d[e.F] = d[p.S] + e.S;
                    pq.push(make_pair(d[e.F], e.F));
                }
            }
        }
        cout << d[t] << '\n';
    }
}
