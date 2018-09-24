#include <bits/stdc++.h>
using namespace std;
const int MAXP = 1e9 + 7;
vector<bool> isPrime;
vector<int> prime;
void build_prime() {
    isPrime.clear(); isPrime.resize(MAXP, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2 ; i < MAXP ; i++) {
        if (isPrime[i]) prime.push_back(i);
        for (int j = 0 ; j < prime.size() && i * prime[j] < MAXP ; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}
vector<bool> dp;
int main() {
    build_prime();
    dp.clear(); dp.resize(MAXP);
    dp[0] = false;
    vector<int> ans;
    for (int i = 0 ; i < MAXP ; i++) {
        if (i % 10000 == 0) cerr << i << '\n';
        if (dp[i]) continue;
        ans.push_back(i);
        for (auto p : prime) {
            if (i + p - 1 >= MAXP) break;
            dp[i + p - 1] = 1;
        }
    }
    for (auto num : ans) cout << num << ' ';
    cout << '\n';
}
