#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; n = 50, k = 125000 - 49 * 49 * 49;
    cout << n << ' ' << k << '\n';
    for (int i = 0 ; i < k ; i++)
        cout << i + 1 << ' ';
    cout << '\n';
}
