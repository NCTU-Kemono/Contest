#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
const int MAXN = 500 + 5;
const int MAXM = 8 * MAXN * MAXN;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<LL, LL> pLL;
struct Graph {
    struct Node; struct Edge; int V;
    struct Node : vector<Edge*> {
        bool inq; Edge *pa; LL a, d;
        Node() { clear(); }
    }_memN[MAXN], *node[MAXN];
    struct Edge {
        Node *u, *v; Edge *rev;
        LL c, f, _c; Edge() {}
        Edge(Node *u, Node *v, LL c, LL _c, Edge *rev) 
            : u(u), v(v), c(c), f(0), _c(_c), rev(rev) {}
    }_memE[MAXM], *ptrE;
    Graph(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
    }
    void addEdge(int u, int v, LL c, LL _c) {
        *ptrE = Edge(node[u], node[v], c, _c, ptrE + 1);
        node[u]->PB(ptrE++);
        *ptrE = Edge(node[v], node[u], 0, -_c, ptrE - 1);
        node[v]->PB(ptrE++);
    }
    Node *s, *t;
    bool SPFA() {
        for (int i = 0; i < V ; i++) node[i]->d = INF, node[i]->inq = false;
        queue<Node*> q; q.push(s); s->inq = true;
        s->d = 0, s->pa = NULL, s->a = INF;
        while (q.size()) {
            Node *u = q.front(); q.pop(); u->inq = false;
            for (auto &e : *u) {
                Node *v = e->v;
                if (e->c > e->f && v->d > u->d + e->_c) {
                    v->d = u->d + e->_c;
                    v->pa = e; v->a = min(u->a, e->c - e->f);
                    if (!v->inq) q.push(v), v->inq = true;
                }
            }
        }
        return t->d != INF;
    }
    pLL maxFlowMinCost(int _s, int _t) {
        s = node[_s], t = node[_t];
        pLL res = MP(0, 0);
        while (SPFA()) {
            res.F += t->a;
            res.S += t->d * t->a;
            for (Node *u = t ; u != s ; u = u->pa->u) {
                u->pa->f += t->a;
                u->pa->rev->f -= t->a;
            }
        }
        return res;
    }
};
struct Tuple {
    LL x, y, z;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        Graph *sol = new Graph(2 * n + 2);
        vector<Tuple> data;
        for (int i = 0 ; i < 2 * n ; i++) {
            LL x, y, z; cin >> x >> y >> z;
            data.push_back({x, y, z});
        }
        for (int i = 0 ; i < n;  i++) {
            sol->addEdge(0, i + 1, 1, 0);
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                LL d;
                d = (data[i].x - data[j + n].x) * (data[i].x - data[j + n].x)
                  + (data[i].y - data[j + n].y) * (data[i].y - data[j + n].y)
                  + (data[i].z - data[j + n].z) * (data[i].z - data[j + n].z);
                sol->addEdge(i + 1, j + n + 1, 1, d);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            sol->addEdge(i + n + 1, n + n + 1, 1, 0);
        }

        pLL res = sol->maxFlowMinCost(0, 2 * n + 1);
        cout << res.S << '\n';
        delete sol;
    }
}
