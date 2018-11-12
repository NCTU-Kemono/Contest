#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<vector<int> > G(n);
        for (int i = 1 ; i < n ; i++) {
            int p; cin >> p; 
            G[p].push_back(i);
            G[i].push_back(p);
        }
        vector<int> d(n, -1);
        d[0] = 0;
        queue<int> q; q.push(0);
        while (q.size()) {
            int p = q.front(); q.pop();
            for (auto v : G[p]) {
                if (~d[v]) continue;
                d[v] = d[p] + 1;
                q.push(v);
            }
        }
        int tree_head = -1;
        int maxV = -1;
        for (int i = 0 ; i < n ; i++) {
            if (maxV < d[i]) {
                maxV = d[i];
                tree_head = i;
            }
        }
        d.clear(); d.resize(n, -1);
        d[tree_head] = 0;
        q.push(tree_head);
        while (q.size()) {
            int p = q.front(); q.pop();
            for (auto v : G[p]) {
                if (~d[v]) continue;
                d[v] = d[p] + 1;
                q.push(v);
            }
        }
        maxV = -1;
        for (int i = 0 ; i < n ; i++)
            maxV = max(maxV, d[i]);
        vector<int> target;
        for (int i = 0 ; i < n ; i++) {
            if (maxV % 2) {
                if (d[i] == maxV / 2 || d[i] == maxV / 2 + 1)
                    target.push_back(i);
            } else {
                maxV /= 2;
                if (d[i] == maxV / 2)
                    target.push_back(i);
            }
        }
        int ans = INF, minV = INF;
        for (int i = 0 ; i < target.size() ; i++) {
            q.push(target[i]);
            d.clear(); d.resize(n, -1);
            d[target[i]] = 0;
            while (q.size()) {
                int p = q.front(); q.pop();
                for (auto v : G[p]) {
                    if (~d[v]) continue;
                    d[v] = d[p] + 1;
                    q.push(v);
                }
            }
            int sum = 0;
            for (int i = 0 ; i < n ; i++)
                sum += d[i];
            if (minV == sum) {
                ans = min(ans, target[i]);
            } else if (minV > sum) {
                ans = target[i];
                minV = sum;
            }
        }
        cout << ans << '\n';
    }
}
