#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char B[MAXN][MAXN];
int n;
string s;
string step = "ICPCASIASG";
int dx[] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dy[] = { 2,  1, -1, -2, -2, -1, 1, 2};
bool _find;
void solve(int curStep, int x, int y) {
    if (curStep == step.size()) {
        _find = true;
        return ;
    }
    for (int d = 0 ; d < 8 ; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (step[curStep] == B[nx][ny]) {
            solve(curStep + 1, nx, ny);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n; cin >> s;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++) 
            B[i][j] = s[i * n + j];
    _find = false;
    for (int i = 0 ; i < n;  i++) {
        for (int j = 0 ; j < n ; j++) {
            if (B[i][j] == 'I') {
                solve(1, i, j);
            }
        }
    }
    if (_find) cout << "YES\n";
    else cout << "NO\n";
}
