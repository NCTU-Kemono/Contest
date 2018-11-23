#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
int check(int n, int m) {
    long double sum = 0;
    for (int i = 1 ; i <= n ; i++)
        sum += log10(i);
    for (int i = 1 ; i <= m ; i++)
        sum -= log10(i);
    for (int i = 1 ; i <= n - m ; i++)
        sum -= log10(i);
    int ret = floor(sum);
    return ret;
}
long long c[MAXN][MAXN];
long long C(int n, int m) {
    if (~c[n][m]) return c[n][m];
    if (m == 0 || n == m) return 1;
    return c[n][m] = C(n - 1, m - 1) + C(n - 1, m);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(c, -1, sizeof(c));
    int t; cin >> t; while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int nn = n;
        bool used[MAXN];
        memset(used, false, sizeof(used));
        vector<int> ans;
        int minV = 1;
        while (m >= 1) {
            n--, m--;
            int chk = check(n, m);
            if (chk >= 6) {
                for (int i = minV ; i <= nn ; i++) {
                    if (!used[i]) {
                        ans.push_back(i);
                        used[i] = true;
                        break;
                    }
                }
            } else {
                int target = 1;
                while (k - C(n, m) > 0) {
                    k -= C(n, m);
                    n--;
                    target++;
                }
                for (int i = minV ; i <= nn ; i++) {
                    if (used[i]) continue;
                    target--;
                    if (target == 0) { 
                        ans.push_back(i);
                        minV = i + 1;
                    }
                }
            }
        }

        for (int i = 0 ; i < ans.size() ; i++)
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    }

}
