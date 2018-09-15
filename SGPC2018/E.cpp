#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35 * 5;
int n;
typedef long long LL;
const int MAXM = MAXN * MAXN;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int data[MAXN][MAXN];
struct Graph {
    struct Node; struct Edge;
    int V;
    struct Node : vector<Edge*> {
        iterator cur; int d;
        Node() { clear(); }
    }_memN[MAXN], *node[MAXN];
    struct Edge {
        Node *u, *v;
        Edge *rev;
        LL c, f;
        Edge() {}
        Edge(Node *u, Node *v, LL c, Edge *rev) : u(u), v(v), c(c), f(0), rev(rev) {}
    }_memE[MAXM], *ptrE;
    Graph(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
    }
    void addEdge(int _u, int _v, LL _c) {
        *ptrE = Edge(node[_u], node[_v], _c, ptrE + 1);
        node[_u]->push_back(ptrE++);
        *ptrE = Edge(node[_v], node[_u],  0, ptrE - 1);
        node[_v]->push_back(ptrE++);
    }
    Node *s, *t;
    LL maxFlow(int _s, int _t) {
        s = node[_s], t = node[_t];
        LL flow = 0;
        while (bfs()) {
            for (int i = 0 ; i < V ; i++) 
                node[i]->cur = node[i]->begin();
            flow += dfs(s, INF);
        }
        return flow;
    }
    bool bfs() {
        for (int i = 0 ; i < V ; i++) node[i]->d = -1;
        queue<Node*> q; q.push(s); s->d = 0;
        while (q.size()) {
            Node *u = q.front(); q.pop();
            for (auto e : *u) {
                Node *v = e->v;
                if (!~v->d && e->c > e->f)
                    q.push(v), v->d = u->d + 1;
            }
        }
        return ~t->d;
    }
    LL dfs(Node *u, LL a) {
        if (u == t || !a) return a;
        LL flow = 0, f;
        for (; u->cur != u->end() ; u->cur++) {
            auto &e = *u->cur; Node *v = e->v;
            if (u->d + 1 == v->d && (f = dfs(v, min(a, e->c - e->f))) > 0) {
                e->f += f; e->rev->f -= f;
                flow += f; a -= f;
                if (!a) break;
            }
        }
        return flow;
    }
};
bool check(int M) {
    Graph *sol = new Graph(2 * n + 2);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (data[i][j] < M) continue;
            sol->addEdge(i + 1, j + n + 1, 1);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        sol->addEdge(0, i + 1, 1);
    }

    for (int i = 0 ; i < n ; i++) {
        sol->addEdge(i + n + 1, 2 * n + 1, 1);
    }
    LL ans = sol->maxFlow(0, 2 * n + 1);
    delete sol;
    return ans == n;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            cin >> data[i][j];
    int L = 0, R = 1e6 + 5;
    while (R - L > 1) {
        int M = (R + L) >> 1;
        if (check(M)) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << L << '\n';
}
