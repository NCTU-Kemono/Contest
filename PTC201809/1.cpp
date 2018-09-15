#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline string to_string(const T &x) {
    stringstream ss;
    return ss << x, ss.str();
}
const int BASE = 1e9 + 0.5;
const int WIDTH = log10(BASE) + 0.5;
typedef long long LL;
struct bigN : vector<LL> {
    bigN(string s) {
        if (s.empty()) return ;
        for (int i = s.size() - 1 ; i >= 0 ; i -= WIDTH) {
            LL t = 0;
            for (int j = max(0, i - WIDTH + 1) ; j <= i ; j++)
                t = t * 10 + s[j] - '0';
            push_back(t);
        }
        trim();
    }
    template <typename T>
    bigN(const T &x) : bigN(to_string(x)) {}
    bigN() {}
    friend istream& operator >> (istream &in, bigN &b) {
        string s;
        return in >> s, b = s, in;
    }
    friend ostream& operator << (ostream &out, const bigN &b) {
        out << (b.empty() ? 0 : b.back());
        for (int i = b.size() - 2 ; i >= 0 ; i--)
            out << setw(WIDTH) << setfill('0') << b[i];
        return out;
    }
    inline void trim() {
        while (size() && !back()) pop_back();
    }
    bigN operator + (const bigN &b) const {
        bigN res = *this;
        if (b.size() > size()) res.resize(b.size());
        for (int i = 0 ; i< b.size() ; i++) 
            res[i] += b[i];
        return res.carry(), res.trim(), res;
    }
    inline void carry() {
        for (int i = 0 ; i < size() ; i++) {
            if (at(i) >= 0 && at(i) < BASE) continue;
            if (i + 1 == size()) push_back(0);
            int r = at(i) % BASE;
            if (r < 0) r += BASE;
            at(i + 1) += (at(i) - r) / BASE;
            at(i) = r;
        }
    }
};
int main() {
    bigN ans = 0;
    string s; while (cin >> s) {
        if (s == "0") {
            cout << ans << '\n';
            ans = 0;
        } else {
            bigN added(s);
            ans = ans + added;
        }
    }
}
