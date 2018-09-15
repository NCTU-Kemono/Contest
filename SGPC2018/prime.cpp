#include <bits/stdc++.h>
using namespace std;
int main() {
    int MOD = 1000007;
    int index = 2;
    while (MOD != 1 && index < MOD) {
        while (MOD % index == 0) MOD /= index;
        cout << MOD << '\n';
        index++;
    }
    cout << MOD << '\n';
}
