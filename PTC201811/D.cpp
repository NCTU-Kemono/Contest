#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<long long> depth(n + 5, 0);
        vector<long long> app(n + 5, 0);
        int pre = -1;
        for (int i = 0 ; i < 2 * n - 1 ; i++) {
            int id; cin >> id;
            app[id]++;
            if (app[id] != 1) {
                depth[id] = max(depth[id], depth[pre] + 1);
            }
            pre = id;
        }
        long long sum = 0;
        for (int i = 1 ; i <= n ; i++)
            sum += depth[i];
        cout << sum << '\n';
    }

}
