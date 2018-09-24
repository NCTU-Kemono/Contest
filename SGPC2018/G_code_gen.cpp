#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    stringstream ss; ss << s;
    cout << "{";
    int tmp; while (ss >> tmp) {
        cout << tmp << ",";
    }
    cout << "}\n;";
}
