#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL fpow(LL a, int n) {
	if (n == 0) return 1;
	LL k = fpow(a, n >> 1);
	if (n & 1) return k * k % MOD * a % MOD;
	return k * k % MOD;
}
string s;
const int MAXLEN = 200 + 5;
LL dp[MAXLEN][MAXLEN][MAXLEN];
LL solve(int L, int R, int rem) {
	if (~dp[L][R][rem]) return dp[L][R][rem];
	if (R - L > 2 * rem) return dp[L][R][rem] = 0;
	if (R - L <= 0) return dp[L][R][rem] = fpow(26, rem);
	if (s[L] == s[R - 1]) {
		return dp[L][R][rem] = (25 * solve(L, R, rem - 1) + solve(L + 1, R - 1, rem - 1)) % MOD;
	} else {
		return dp[L][R][rem] = (24 * solve(L, R, rem - 1) + solve(L, R - 1, rem - 1) + solve(L + 1, R, rem - 1)) % MOD;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, s.size(), n) << '\n';
}
