#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35;
vector<vector<int> > G;
vector<int> deg;
int n, m;
int solve(int S) {
    if (S == 0) return 0;
    int target;
    for (int i = 0 ; i < n && !find ; i++) {
        if (S & (1 << i))
            find = true, target = i;
    }
    if (deg[target] == 0) return 1 + solve(S ^ (1 << target));
    else if (deg[target] == 1) {
        
    }
}
int main() {
    cin >> n >> m;
    G.resize(n);
    bool adj[MAXN][MAXN]; memset(adj, true, sizeof(adj));
    for (int i = 0 ; i < n ; i++) adj[i][i] = false;
    for (int i = 0 ; i < m ; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = false;
    }
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++) 
            if (adj[i][j])
                G[i].push_back(j);
    for (int i = 0 ; i < n ; i++) deg.push_back(G[i].size());
    for (int i = 0 ; i < n ; i++) cout << deg[i] << (i == n - 1 ? '\n' : ' ');
    cout << solve((1<<n) - 1) << '\n';
}
