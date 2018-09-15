#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; n = 30; cout << n << '\n';
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++)
            cout << rand() % 1000000 + 1 << ' ';
        cout << '\n';
    }
}
