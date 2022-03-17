#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    string s;
    cin >> s;
    int res = 0;
    bool minus = false;
    string snum = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1 || s[i] == '+' || s[i] == '-') {
            if (i == s.size() - 1) snum += s[i];
            res += (minus ? stoi(snum) * (-1) : stoi(snum));
            snum = "";
            if (s[i] == '-') minus = true;
        }
        else snum += s[i];
    }
    cout << res;
}
