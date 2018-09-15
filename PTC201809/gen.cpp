#include <bits/stdc++.h>
using namespace std;
vector<int> pa;
int _find(int x) {
    return pa[x] == x ? x : pa[x] = _find(pa[x]);
}
vector<vector<int> > G;
void dfs(int u, int p) {
    for (int i = 0 ; i < G[u].size() ; i++) {
        if (G[u][i] == p) continue;
        cout << G[u][i] << ' ' << u << '\n';
        dfs(G[u][i], u);
    }
}
int main() {
    srand(time(NULL));
    int t = 10;
    cout << t << '\n';
    while (t--) {
    int n = 50000; cout << n << '\n';
    cout << 0 << '\n';
    pa.clear(); pa.resize(n);
    G.clear(); G.resize(n);
    for (int i = 0 ; i < n ; i++) pa[i] = i;
    for (int i = 0 ; i < n - 1 ; i++) {
        int u = rand() % n, v = rand() % n;
        int x = _find(u), y = _find(v);
        if (x == y) {
            i--;
            continue;
        }
        pa[x] = y;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    }
}
