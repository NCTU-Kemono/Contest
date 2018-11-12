#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
int solve(int u, int p) {
    for (auto v : G[u]) {
        if (v == p) continue;
        
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        G.clear(); G.resize(n);
        for (int i = 1 ; i < n ; i++) {
            int p; cin >> p;
            G[p].push_back(i);
            G[i].push_back(p);
        }
        cout << solve(0, 0) << '\n';
    }
}
