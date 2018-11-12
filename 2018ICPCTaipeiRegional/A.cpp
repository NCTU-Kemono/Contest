#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        double A, B;
        cin >> A >> B;
        LL a = 0;
        for (a = 0 ;; a++) {
            if (A >= B) break;
            if (a % 3 == 0 && a % 14 != 12 && a % 14 != 13)
                A *= 1.1;
        }
        cout << a + 1 << '\n';
    }

}
