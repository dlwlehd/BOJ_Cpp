#include <bits/stdc++.h>
using namespace std;

string s, t;

string Apop(string s) {
    s.pop_back();
    return s;
}

string rev(string s) {
    reverse(s.begin(), s.end());
    s.pop_back();
    return s;
}

bool go(string s, string t) {
    if (s.size() == t.size()) {
        if (s == t) return true;
        else return false;
    }
    if (t.size() >= 1) {
        if (t.front() == 'A' && t.back() == 'A')
            return go(s, Apop(t));

        if (t.front() == 'A' && t.back() == 'B')
            return false;

        if (t.front() == 'B' && t.back() == 'A') {
            return go(s, Apop(t)) || go(s, rev(t));
        }

        if (t.front() == 'B' && t.back() == 'B') {
            return go(s, rev(t));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> s >> t;
    if (go(s, t)) cout << 1;
    else cout << 0;
}