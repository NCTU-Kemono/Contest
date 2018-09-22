#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> data;
    for (int i = 0 ; i < n ; i++) {
        int input; cin >> input;
        data.push_back(input);
    }
    if (n == 1) {
        cout << 1 << '\n';
    } else if (n == 2 && data[0] == 0 && data[1] != 0) {
        cout << 1 << '\n';
    } else if (n == 2) {
        cout << 2 << '\n';
    } else {
        map<int, int> cnt; int ans = 2;
        for (int i = 0 ; i < n ; i++) {
            cnt[data[i]]++;
            ans = max(ans, cnt[data[i]]);
        }
        cout << ans << '\n';
    }
}
