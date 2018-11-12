#include <bits/stdc++.h>
using namespace std;
string str;
vector<int> ans;
bool solve(int front, int back, int chance) {
    if (front >= back) { 
        return true;
    }
    bool legal = false;
    if (str[front] == str[back]) {
        bool output = solve(front + 1, back - 1, chance);
        if (chance == 0) return output;
        legal |= output;
    }
    if (chance == 0) return false;
    bool res = solve(front + 1, back, chance - 1);
    legal |= res;
    if (res) ans.push_back(front);
    
    res = solve(front, back - 1, chance - 1);
    legal |= res;
    if (res) ans.push_back(back);
   
    return legal;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        ans.clear();
        cin >> str;
        solve(0, str.size() - 1, 1);
        sort(ans.begin(), ans.end());
        cout << ans.size(); 
        for (int i = 0 ; i < ans.size() ; i++)
            cout << ' ' << ans[i];
        cout << '\n';
    }
}
