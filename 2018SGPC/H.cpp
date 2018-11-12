#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 55;
typedef pair<int, int> pii;
int B[MAXN][MAXN];
unordered_map<int, pii> trans;
#define F first
#define S second
int dx[] = {0, -1, -1,  0, 1, 1};
int dy[] = {1,  0, -1, -1, 0, 1};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int R, k; cin >> R >> k;
    memset(B, -1, sizeof(B));
    int index = 0;
    for (int i = 0 ; i < R - 1 ; i++) {
        for (int j = 0 ; j < R + i ; j++) {
            trans[++index] = make_pair(1 + i, j + 1);
        }
    }
    for (int i = 0 ; i < R + R - 1 ; i++) {
        trans[++index] = make_pair(R, i + 1);
    }
    for (int i = 0 ; i < R - 1 ; i++) {
        for (int j = 0 ; j < R + R - 2 - i ; j++) {
            trans[++index] = make_pair(R + i + 1, i + 1 + j + 1);
        }
    }
    for (int i = 0 ; i < k ; i++) {
        int x; cin >> x;
        pii pos = trans[x];
        B[pos.F][pos.S] = 1;
    }
    int ans = 0;
    queue<pii> q; q.push(make_pair(0, 0)); B[0][0] = 0;
    while (q.size()) {
        pii p = q.front(); q.pop();
        for (int d = 0 ; d < 6 ; d++) {
            pii np = make_pair(p.F + dx[d], p.S + dy[d]);
            if (np.F < 0 || np.F >= MAXN || np.S < 0 || np.S >= MAXN) continue;
            if (B[np.F][np.S] == 0) continue;
            if (B[np.F][np.S] == 1) ans++;
            else {
                B[np.F][np.S] = 0;
                q.push(np);
            }
        }
    }
    cout << ans << '\n';
}
