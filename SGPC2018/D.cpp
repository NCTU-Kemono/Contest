#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int n;
bool isB[MAXN][MAXN];
struct Graph { int V;
    struct Node : vector<Node*> {
        int low, dfn;
        bool is_cut;
        Node *pa;
        Node() {
            clear();
            low = dfn = -1;
            is_cut = false;
            pa = NULL;
        }
    }_memN[2 * MAXN], *node[2 * MAXN];
    Graph (int _V) : V(_V) {
        for (int i = 0 ; i < V ;i ++)
            node[i] = _memN + i;
    }
    void addEdge(int u, int v) {
        node[u]->push_back(node[v]);
        node[v]->push_back(node[u]);
    }
    int stamp;
    void findBridge() {
        memset(isB, false, sizeof(isB));
        stamp = 0;
        Tarjan(node[0], NULL);
        for (int i = 0 ; i < V ; i++) {
            Node *pa = node[i]->pa;
            if (pa && node[i]->low > pa->dfn) {
                isB[pa - _memN][node[i] - _memN] = true;
                isB[node[i] - _memN][pa - _memN] = true;
            }
        }
    }
    void Tarjan(Node *u, Node *pa) {
        u->pa = pa;
        u->dfn = u->low = stamp++;
        for (auto to : *u) {
            if (!~to->dfn) {
                Tarjan(to, u);
                u->low = min(u->low, to->low);
            } else if (pa != to) 
                u->low = min(u->low, to->dfn);
        }
    }
    int solve() {
        findBridge();
        queue<Node*> q; q.push(node[0]);
        bool vis[MAXN]; memset(vis, 0, sizeof(vis));
        vis[0] = true; int ans = 0;
        while (q.size()) {
            Node *u = q.front(); q.pop();
            if (u - _memN < n) ans++;
            for (auto v : *u) {
                if (isB[u - _memN][v - _memN]) continue;
                if (vis[v - _memN]) continue;
                vis[v - _memN] = true;
                q.push(v);
            }
        }
        return ans;
    }
};
int isLink[MAXN][MAXN];
int main() {
    int m; cin >> n >> m;
    Graph *sol = new Graph(2 * n + 5);
    memset(isLink, 0, sizeof(isLink));
    int newNode = n;
    for (int i = 0 ; i < m ; i++) {
        int u, v; cin >> u >> v;
        if (isLink[u][v] == 2) continue;
        if (isLink[u][v] == 1) {
            sol->addEdge(u, newNode);
            sol->addEdge(newNode, v);
            isLink[u][v] = isLink[v][u] = 2;
        } else {
            isLink[u][v] = isLink[v][u] = 1;
            sol->addEdge(u, v);
        }
    }
    cout << sol->solve() << '\n';
}
