#include <bits/stdc++.h>
using namespace std;
struct djs {
    vector<int> pa; int n;
    djs(int _n) : n(_n) { pa.resize(n, -1); }
    int find(int x) { return pa[x] < 0 ? x : pa[x] = find(pa[x]); }
    bool Union(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (pa[x] < pa[y]) swap(x, y);
        pa[y] += pa[x], pa[x] = y;
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    djs *sol = new djs(n);
    for (int i = 0 ; i < k ; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        sol->Union(u, v);
    }
    bool legal = true;
    for (int i = 0 ; i < n / 2 && legal ; i++) {
        if (sol->find(i) != sol->find(n - i - 1))
            legal = false;
    }
    if (legal) cout << "Yes\n";
    else cout << "No\n";
}
