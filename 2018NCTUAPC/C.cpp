#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> cnt;
    string s; while (cin >> s) {
        cnt[s]++;
    }
    int ans = 0;
    for (auto p : cnt) {
        if (p.second != 1) continue;
        ans = max(ans, (int)p.first.size());
    }
    cout << ans << '\n';
}
