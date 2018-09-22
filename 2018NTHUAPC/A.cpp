#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main() {
    long long PHI[MAXN + 1];
    for (int i = 1 ; i <= MAXN ; i++) PHI[i] = i;
    for (int i = 1 ; i <= MAXN ; i++) 
        for (int j = i * 2 ; j <= MAXN ; j += i)
            PHI[j] -= PHI[i];
    vector<long long> pre; pre.push_back(0);
    for (int i = 1 ; i <= MAXN ; i++)
        pre.push_back(pre.back() + PHI[i]);
    int t; cin >> t; while (t--) {
        int L, R; cin >> L >> R;
        cout << pre[R] - pre[L - 1] << '\n';
    }
}
