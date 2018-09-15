#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> data(n + 5, 0);
    int sq = sqrt(n);
    vector<vector<int> > tag(sq + 5, vector<int>(sq + 5, 0));
    while (k--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b, c; cin >> a >> b >> c;
            if (b >= sq) {
                for (int i = 0 ; i * b + a <= n ; i++)
                    data[i * b + a] += c;
            } else {
                tag[a][b] += c;
            }
        } else if (op == 2) {
            int q; cin >> q;
            int ans = data[q];
            for (int i = 1 ; i < sq ; i++)
                ans += tag[q % i][i];
            cout << ans << '\n';
        }
    }
}
