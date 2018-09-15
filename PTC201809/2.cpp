#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int even_num; cin >> even_num;
        int deg[MAXN]; memset(deg, 0, sizeof(deg));
        bool isOdd[MAXN]; memset(isOdd, true, sizeof(isOdd));
        for (int i = 0 ; i < even_num ; i++) {
            int num; cin >> num;
            isOdd[num] = false;
        }
        vector<int> pa(n, -1);
        for (int i = 0 ; i < n - 1; i++) {
            int v, p; cin >> v >> p;
            pa[v] = p;
            deg[p]++;
        }
        int rt = 0;
        while (pa[rt] != -1) {  
            cout << rt << '\n';
            rt = pa[rt]; 
        }
        queue<int> q;
        for (int i = 0 ; i < n ; i++) {
            if (deg[i] == 0)
                q.push(i);
        }
        int ans = 0;
        while (q.size()) {
            int p = q.front(); q.pop();
            if (isOdd[p]) { 
                ans++;
                isOdd[pa[p]] ^= 1;
            }
            deg[pa[p]]--;
            if (pa[p] != rt && deg[pa[p]] == 0)
                q.push(pa[p]);
        }
        if (isOdd[rt]) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
