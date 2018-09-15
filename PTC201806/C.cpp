#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int main() {
    int t; cin >> t; while(t--) {
        vector<pair<int, int> > op[3];
        int n, m; cin >> n >> m;
        for (int i = 0 ; i < m ; i++) {
            int a, b; string c; cin >> a >> c >> b;
            if (c[0] == '*') op[0].push_back(make_pair(a, b));
            else if (c[0] == '^') op[1].push_back(make_pair(a, b));
            else op[2].push_back(make_pair(a, b));
        }
        /*
        for (int i = 0 ; i < 3 ; i++) {
            for (auto p : op[i])
                cout << p.first << ' ' << p.second << '\n';
            cout << '\n';
        }
        */
        bool legal = true;
        int type[MAXN]; memset(type, 0, sizeof(type)); // odd 1, even -1, und 0   
        for (auto p : op[0])
            type[p.first] = type[p.second] = 1;
        for (auto p : op[1])
            type[p.first] = 1;
        while (1) {
            int chg_num = 0;
            for (auto p : op[2]) {
                if (type[p.first] != 0 && type[p.first] == type[p.second]) {
                    legal = false; break;
                }
                if (type[p.first] != 0 && type[p.second] == 0) {
                    type[p.second] = type[p.first] * (-1);   
                    chg_num++;
                } else if (type[p.first] == 0 && type[p.second] != 0) {
                    type[p.first] = type[p.second] * (-1);
                    chg_num++;
                } 
            }
            if (chg_num == 0) break;
        }
        vector<int> G[MAXN];
        for (auto p : op[2]) {
            if (type[p.first] == 0 && type[p.second] == type[p.first]) {
                G[p.first].push_back(p.second);
                G[p.second].push_back(p.first);
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            if (type[i] == 0) {
                queue<int> q; q.push(i); type[i] = 1;
                while (q.size()) {
                    int p = q.front(); q.pop();
                    for (auto v : G[p]) {
                        if (type[v] == 0) {
                            type[v] = type[p] * (-1);
                            q.push(v);
                        } else {
                            if (type[v] == type[p])
                                legal = false;
                        }
                    }
                }
            }
        }
        if (legal) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
