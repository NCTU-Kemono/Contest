#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL extgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) return x = 1, y = 0, a;
    LL res = extgcd(b, a % b, y, x);
    return y -= a / b * x, res;
}
LL modInv(LL a, LL m) {
    LL x, y, d = extgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
const int MAXN = 2e5 + 5;
const LL MOD = 1e6 + 7;
LL fact[MAXN], inv[MAXN];
LL C(int n, int m) {
    cout << fact[n] << ' ' << inv[n - m] << ' ' << inv[m] << '\n';
    return fact[n] * inv[n - m] % MOD * inv[m] % MOD;
}
LL trans(LL a) {
    while (a < 0) a += MOD;
    return a;
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, m, k; cin >> n >> m >> k;
    fact[0] = 1;
    inv[0] = 1;
    cout << modInv(659629, MOD) << '\n';
    LL x, y;
    for (int i = 1 ; i < MAXN ; i++) {
        fact[i] = (fact[i - 1] * i % MOD);
        cout << fact[i] << ' ';
        cout << extgcd(fact[i], MOD, x, y) << ' ';
        cout << modInv(fact[i], MOD) << ' ';
        inv[i] = modInv(fact[i], MOD);
        cout << inv[i] << '\n';
        if (i > 35) while (1);
    }
    if (n * m < k) {
        cout << 0 << '\n';
    } else if (k <= m) {
        cout << n + k  - 1 << ' ' << k << ' ';
        cout << C(n + k - 1, k) << '\n';
    } else if (k > m) {
        int i = 0; LL ans = 0;
        while (k - i * (m + 1) >= 0) {
            LL add = C(n, i) * C(n + k - i * (m + 1) - 1, k - i * (m + 1));
            // cout << add << '\n';
            if (i % 2) ans -= add;
            else ans += add;
            ans = trans(ans);
            i++;
        }
        cout << ans << '\n';
    }
}
