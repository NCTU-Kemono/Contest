#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        vector<bool> check(s.size(), false);
        if (s.size() % 2) {
            int mid = s.size() / 2;
            int l = mid - 1;
            int r = mid;
            int chance = -1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    l--, r++;
                } else {
                    if (chance != -1) { 
                        chance = -2;
                        break;
                    }
                    chance = r;
                    r++;
                }
            }
            if (chance != -2) {
                if (chance == -1) chance = s.size() - 1;
                int cur = chance;
                while (cur >= 0) {
                    if (s[cur] == s[chance]) check[cur] = true;
                    else break;
                    cur--;
                }
                    
            }
            chance = -1;
            l = mid;
            r = mid + 1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    l--, r++;
                } else {
                    if (chance != -1) { 
                        chance = -2;
                        break;
                    }
                    chance = l;
                    l--;
                }
            }
            if (chance != -2) {
                if (chance == -1) chance = 0;
                int cur = chance;
                while (cur < s.size()) {
                    if (s[cur] == s[chance]) check[cur] = true;
                    else break;
                    cur++;
                }       
            }
        } else {
            int mid = s.size() / 2 - 1;
            int l = mid - 1;
            int r = mid + 1;
            int chance = -1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    l--, r++;
                } else {
                    if (chance != -1) { 
                        chance = -2;
                        break;
                    }
                    chance = r;
                    r++;
                }
            }
            if (chance != -2) {
                if (chance == -1) chance = s.size() - 1;
                int cur = chance;
                while (cur >= 0) {
                    if (s[cur] == s[chance]) check[cur] = true;
                    else break;
                    cur--;
                }
                    
            }
            chance = -1;
            mid = s.size() / 2;
            l = mid - 1;
            r = mid + 1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    l--, r++;
                } else {
                    if (chance != -1) { 
                        chance = -2;
                        break;
                    }
                    chance = l;
                    l--;
                }
            }
            if (chance != -2) {
                if (chance == -1) chance = 0;
                int cur = chance;
                while (cur < s.size()) {
                    if (s[cur] == s[chance]) check[cur] = true;
                    else break;
                    cur++;
                }       
            }
        }
        int sum = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            sum += check[i];
        }
        if (sum == 0) {
            cout << 0 << '\n';
        } else {
            cout << sum;
            for (int i = 0 ; i < s.size() ; i++) {
                if (check[i])
                    cout << ' ' << i;
            }
            cout << '\n';
        }
    }
}
