#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<long long> data;
    long long num;
    while (cin >> num) {
        data.push_back(num);
    }
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    int cnt = 0;
    for (int i = 0 ; i < data.size() ; i++) {
        if (data[i] > 1000000000) break;
        cnt++;
        cout << data[i] << ',';
    }
    cout << '\n';
    cout << cnt << '\n';
}
