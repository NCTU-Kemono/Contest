#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
char B[MAXN][MAXN];
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define F first
#define S second
int main() {
    int t; cin >> t; while (t--) {
        int r, c; cin >> r >> c;
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++)
                cin >> B[i][j];
        }
        char G[MAXN][MAXN];
        int dir[MAXN][MAXN]; // 0: right, 1 : down
        memset(dir, -1, sizeof(dir));
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (B[i][j] == 'B') {
                    if (i - 1 >= 0) {
                        if (B[i - 1][j] == 'X' || B[i - 1][j] == 'B')
                            dir[i][j] = 1;
                    }
                    if (j - 1 >= 0) {
                        if (B[i][j - 1] == 'X' || B[i][j - 1] == 'B')
                            dir[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++)
                cout << dir[i][j] << ' ';
            cout << '\n';
        }
        int ans[3]; memset(ans, 0, sizeof(ans));
        for (int i = 0 ; i < r ; i++)
            for (int j = 0 ; j < c ; j++)
                G[i][j] = B[i][j];
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (G[i][j] == '.') continue;
                ans[0]++;
                queue<pii> q; q.push(make_pair(i, j));
                while (q.size()) {
                    pii p = q.front(); q.pop();
                    if (B[p.F][p.S] == 'B') {
                        pii np = make_pair(p.F + dx[dir[p.F][p.S]], p.S + dy[dir[p.F][p.S]]);
                        if (G[np.F][np.S] == '.') continue;
                        G[np.F][np.S] = '.';
                        q.push(np);
                    } else {
                        for (int d = 0 ; d < 2 ; d++) {
                            pii np = make_pair(p.F + dx[d], p.S + dy[d]);
                            if (np.F < 0 || np.F >= r || np.S < 0 || np.S >= c) continue;
                            if (G[np.F][np.S] == '.') continue;
                            G[np.F][np.S] = '.';
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
                if (G[i][j] == '.' || G[i][j] == 'B') continue;
                ans[1]++;
                queue<pii> q; q.push(make_pair(i, j));
                while (q.size()) {
                    pii p = q.front(); q.pop();
                    for (int d = 0 ; d < 4 ; d++) {
                        pii np = make_pair(p.F + dx[d], p.S + dy[d]);
                        if (np.F < 0 || np.F >= r || np.S < 0 || np.S >= c) continue;
                        if (G[np.F][np.S] == '.' || G[np.F][np.S] == 'B') continue;
                        G[np.F][np.S] = '.';
                        q.push(np);
                    }
                }
            }
        }
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (B[i][j] != 'X') continue;
                bool ok;
                ok = false;
                for (int x = 1 ; ; x++) {
                    if (i + x >= r) break;
                    if (B[i + x][j] == 'B') {
                        ok = true;
                        continue;
                    }
                    if (B[i + x][j] == 'X' && ok) {
                        ans[2]++;
                        break;
                    } else break;
                }
                ok = false;
                for (int y = 1 ; ; y++) {
                    if (j + y >= c) break;
                    if (B[i][j + y] == 'B') { 
                        ok = true;
                        continue;
                    }
                    if (B[i][j + y] == 'X' && ok) { 
                        ans[2]++;
                        break;
                    }
                    else break;
                }
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
}
