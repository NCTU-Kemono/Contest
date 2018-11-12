#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 5;
int deg[MAXN], rest[MAXN];
struct State {
    int idx, rest, deg;
    bool operator < (const State &rhs) const {
        return rest == rhs.rest ? deg < rhs.deg : rest > rhs.rest;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        bool isW[MAXN]; memset(isW, false, sizeof(isW));
        for (int i = 0 ; i < n ; i++) {
            char c; cin >> c;
            if (c == 'W') isW[i] = true;
        }
        vector<vector<int> > G(n);
        memset(deg, false, sizeof(deg));
        for (int i = 0 ; i < m ; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            if (isW[u] != isW[v]) continue;
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++, deg[v]++;
        }
        memset(rest, 0, sizeof(rest));
        for (int i = 0 ; i < n ; i++) {
            for (auto v : G[i])
                rest[i] += deg[v];
            rest[i] -= deg[i];
        }
        bool vis[MAXN]; memset(vis, false, sizeof(vis));
        int ans[2] = {0}; // W: 0, B: 1;
        for (int i = 0 ; i < n ; i++) {
            if (vis[i]) continue;
            queue<int> q; q.push(i); vis[i] = true;
            priority_queue<State> pq;
            int cnt = 0;
            while (q.size()) {
                int p = q.front(); q.pop();
                cnt++;
                pq.push({p, rest[p]});
                for (auto v : G[p]) {
                    if (vis[v]) continue;
                    q.push(v); vis[v] = true;
                }
            }
            bool isOut[MAXN]; memset(isOut, false, sizeof(isOut));
            int sum = 0;
            while (pq.size()) {
                if (cnt == 0) break;
                State p = pq.top(); pq.pop();
                isOut[p.idx] = true;
                cnt--;
                sum++;
                for (auto v : G[p.idx]) { 
                    isOut[v] = true;
                    cnt--;
                }
                for (auto v : G[p.idx]) {
                    for (auto nv : G[v]) {
                        if (deg[v] <= 1) continue;
                        if (isOut[nv]) continue;
                        rest[nv] -= deg[v] - 1;
                        pq.push({nv, rest[nv]});
                        deg[nv]--;
                        for (auto nnv : G[nv]) {
                            if (deg[v] <= 1) continue;
                            if (isOut[nnv]) continue;
                            rest[nnv]--;
                            pq.push({nnv, rest[nnv]});
                        }
                    }
                }
            }
            if (isW[i]) ans[0] += sum;
            else ans[1] += sum;
        }
        cout << ans[0] << '\n';
        // cout << min(ans[0], ans[1]) << '\n';
    }

}
