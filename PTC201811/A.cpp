#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MAXN = 100;
bool G[MAXN][MAXN];
struct Set {
    bool s[MAXN]; int size;
    Set() { memset(s, false, sizeof(s)); size = 0; }
};
int n, ans;
inline void intersect(Set &S, int u) {
    for (int i = 0 ; i < n ; i++) {
        if (S.s[i] && !G[u][i]) {
            S.s[i] = false;
            S.size--;
        }
    }
}
void backtrack(Set R, Set P, Set X) {
    if (P.size == 0) {
        if (X.size == 0) {
            ans = max(ans, R.size);
        }
        return ;
    }
    int pivot;
    for (pivot = 0 ; pivot < n ; pivot++)
        if (P.s[pivot] || X.s[pivot])
            break;
    for (int i = 0 ; i < n ; i++) {
        if (P.s[i] && !G[pivot][i]) {
            R.s[i] = true; R.size++;
            Set A = P;
            Set B = X;
            intersect(A, i);
            intersect(B, i);
            backtrack(R, A, B);
            R.s[i] = false; R.size--;
            P.s[i] = false; P.size--;
            if (!X.s[i]) X.s[i] = true, X.size++;
        }
    }
}
inline void BK() {
    for (int i = 0 ; i < n ; i++) G[i][i] = false;
    Set R, P, X;
    for (int i = 0 ; i < n ; i++) R.s[i] = false;
    for (int i = 0 ; i < n ; i++) P.s[i] = true;
    for (int i = 0 ; i < n ; i++) X.s[i] = false;
    R.size = 0;
    P.size = n;
    X.size = 0;
    backtrack(R, P, X);
}
typedef unsigned int ui;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        ans = 0;
        cin >> n;
        vector<ui> data;
        for (int i = 0 ; i < n ; i++) {
            ui num; cin >> num;
            data.push_back(num);
        }
        memset(G, false, sizeof(G));
        for (int i = 0 ; i < n ; i++) {
            for (int j = i + 1 ; j < n ; j++) {
                if (i == j) continue;
                if (__builtin_popcount(data[i] ^ data[j]) > 4)
                    G[i][j] = G[j][i] = true;
            }
        }
        BK();
        cout << ans << '\n';
    }
}
