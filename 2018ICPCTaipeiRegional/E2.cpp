#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 400 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL nl, nr;
LL pre[MAXN];
LL slack[MAXN];
LL W[MAXN][MAXN];
LL lx[MAXN], ly[MAXN];
LL mx[MAXN], my[MAXN];
bool vx[MAXN], vy[MAXN];
void augment(LL u) {
    if (!u) return ;
    augment(mx[pre[u]]);
    mx[pre[u]] = u;
    my[u] = pre[u];
}
inline void match(LL x) {
    queue<LL> q;
    q.push(x);
    while (1) {
        while (q.size()) {
            x = q.front(); q.pop();
            vx[x] = 1;
            for (LL y = 1 ; y <= nr ; y++) {
                if (vy[y]) continue;
                LL t = lx[x] + ly[y] - W[x][y];
                if (t > 0) {
                    if (slack[y] >= t) slack[y] = t, pre[y] = x;
                    continue;
                }
                pre[y] = x;
                if (!my[y]) {
                    augment(y);
                    return ;
                }
                vy[y] = 1;
                q.push(my[y]);
            }
        }
        LL t = INF;
        for (LL y = 1 ; y <= nr ; y++) if (!vy[y]) t = min(t, slack[y]);
        for (LL x = 1 ; x <= nl ; x++) if (vx[x]) lx[x] -= t;
        for (LL y = 1 ; y <= nr ; y++) {
            if (vy[y]) ly[y] += t;
            else slack[y] -= t;
        }
        for (LL y = 1 ; y <= nr ; y++) {
            if (vy[y] || slack[y]) continue;
            if (!my[y]) {
                augment(y);
                return ;
            }
            vy[y] = 1;
            q.push(my[y]);
        }
    }
}
struct Point {
    LL x, y, z;
};
LL dist(Point &a, Point &b) {
    return   (a.x - b.x) * (a.x - b.x)
           + (a.y - b.y) * (a.y - b.y)
           + (a.z - b.z) * (a.z - b.z);
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        memset(pre, 0, sizeof(pre));
        memset(W, 0, sizeof(W));
        memset(lx, 0, sizeof(lx));
        memset(ly, 0, sizeof(ly));
        memset(mx, 0, sizeof(mx));
        memset(my, 0, sizeof(my));
        memset(vx, 0, sizeof(vx));
        memset(vy, 0, sizeof(vy));
        int n; cin >> n;
        nl = nr = n;
        vector<Point> data; data.push_back({-1, -1, -1});
        for (int i = 0 ; i < n ; i++) {
            LL x, y, z; cin >> x >> y >> z;
            data.push_back({x, y, z});
        }
        for (int i = 0 ; i < n ; i++) {
            LL x, y, z; cin >> x >> y >> z;
            data.push_back({x, y, z});
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++)
                W[i][j] = -dist(data[i], data[j + n]);
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int x = 1 ; x <= n ; x++) vx[x] = 0;
            for (int y = 1 ; y <= n ; y++) vy[y] = 0, slack[y] = INF;
            match(i);
        }
        LL ans = 0LL;
        for (int x = 1 ; x <= n ; x++) ans += W[x][mx[x]];
        cout << -ans << '\n';
    }
}
