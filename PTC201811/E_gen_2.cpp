#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 1e5 + 5;
    for (int i = 0 ; i <= n ; i++) {
        stringstream ss; ss << i;
        string output; ss >> output;
        string rev = output;
        reverse(rev.begin(), rev.end());
        cout << output + rev << '\n';
        cout << output + rev.substr(1, rev.size()) << '\n';
    }
}
