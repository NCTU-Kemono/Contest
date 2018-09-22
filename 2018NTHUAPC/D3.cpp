#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int MAXN = 100;
int main() {
    int t; cin >> t; while (t--) {
        int r, c; cin >> r >> c;
        char B[MAXN][MAXN];
        for (int i = 0 ; i < r ; i++)
            for (int j = 0 ; j < c ; j++)
                cin >> B[i][j];
        int ans[3] = {0};
        char G[MAXN][MAXN];
        for (int i = 0 ; i < r ; i++)
            for (int j = 0 ; j < c ; j++)
                G[i][j] = B[i][j];
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (G[i][j] == '.') continue;
                ans[0]++;
                queue<pii> q; q.push(make_pair(i, j));
                G[i][j] = '.';
                while (q.size()) {
                    pii p = q.front(); q.pop();
                    for (int d = 0 ; d < 4 ; d++) {
                        pii np = make_pair(p.x + dx[d], p.y + dy[d]);
                        if (np.x < 0 || np.x >= r || np.y < 0 || np.y >= c) continue;
                        if (B[p.x][p.y] == 'B' && (B[np.x][np.y] != 'B' && B[np.x][np.y] != 'X')) continue;
                        if (G[np.x][np.y] == '.') continue;
                        G[np.x][np.y] = '.';
                        q.push(np);
                    }
                }
            }
        }
        for (int i = 0 ; i < r ; i++)
            for (int j = 0 ; j < c ; j++)
                G[i][j] = B[i][j];
        for (int i = 0 ; i < r; i ++) {
            for (int j = 0 ; j < c ; j++) {
                if (G[i][j] == 'X' || G[i][j] == '#') {
                    queue<pii> q; q.push(make_pair(i, j));
                    G[i][j] = '.';
                    ans[1]++;
                    while (q.size()) {
                        pii p = q.front(); q.pop();
                        for (int d = 0 ; d < 2 ; d++) {
                            pii np = make_pair(p.x + dx[d], p.y + dy[d]);
                            if (np.x < 0 || np.x >= r || np.y < 0 || np.y >= c) continue;
                            if (G[np.x][np.y] != '#' && G[np.x][np.y] != 'X') continue;
                            G[np.x][np.y] = '.';
                            q.push(np);
                        }
                    }
                }
            }
        }
        for (int i = 0 ; i < r ; i++)
            for (int j = 0 ; j < c ; j++)
                G[i][j] = B[i][j];
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (G[i][j] == 'B') {
                    queue<pii> q; q.push(make_pair(i, j));
                    G[i][j] = '.';
                    ans[2]++;
                    while (q.size()) {
                        pii p = q.front(); q.pop();
                        for (int d = 0 ; d < 2 ; d++) {
                            pii np = make_pair(p.x + dx[d], p.y + dy[d]);
                            if (np.x < 0 || np.x >= r || np.y < 0 || np.y >= c) continue;
                            if (G[np.x][np.y] != 'B') continue;
                            G[np.x][np.y] = '.';
                            q.push(np);
                        }
                    }
                }
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
}
