#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
typedef pair<int, int> pii;

vector<pii> num;
int c[MAX];
int r[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while (T --) {
        int n, k; cin >> n >> k;
        num.clear(); num.resize(n + 1);
        
        for (int i = 1; i < n + 1; i ++) {
            num[i].second = i;
            num[i].first = n + 5;
            cin >> c[i];
        }

        for (int i = 1; i < n + 1; i ++)
            cin >> r[i];

        for (int i = 1; i < n + 1; i ++) {
            num[c[i]].first = r[i];
        }

        sort(num.begin() + 1, num.end());

        for (int i = 1; i < k + 1; i ++)
            cout << num[i].second << ' ';
        cout << '\n';

    }
}
