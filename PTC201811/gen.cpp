#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int T = 100000;
    cout << T << '\n';
    for (int t = 0 ; t < T ; t++) {
    int n = 80;
    cout << n << '\n';
    for (int i = 0 ; i < n; i += 2)
        cout << rand() % 60 << '\n';
    }
}
