#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long n) {
    if (n == 1) return a;
    long long k = power(a, n / 2);
    if (n % 2) {
        return k * k % MOD * a % MOD;
    }else{
        return k * k % MOD;
    }
}
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (!b) return x = 1, y = 0, a;
    long long res = ext_gcd(b, a % b, y, x);
    return y -= a / b * x, res;
}
long long modinv(long long a, long long m) {
    long long x, y, d = ext_gcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
int main() {
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        long long D, V; cin >> D >> V;
        if (D >= 2 && V < 2) { 
            cout << -1 << '\n';
            continue;
        }
        if (D == 0) {
            cout << 1 << '\n';
            continue;
        }
        if (D == 1) {
            cout << V + 1 << '\n';
            continue;
        }
        if (V == 1) {
            cout << D + 1 << '\n';
            continue;
        }
        if (V == 2) {
            cout << 1 + 2 * D << '\n';
        }else{
            cout << (V * (power(V - 1, D) - 1) % MOD * modinv(V - 2, MOD) + 1) % MOD << '\n';
        }
    }
}
