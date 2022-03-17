#include <bits/stdc++.h>
using namespace std;

int n;
long long mn = 0x7f7f7f7f7f;
long long mx = -1;
string max_string, min_string;
vector<bool> c;
bool vis[10];

void func(int idx, string s) {

    if (idx == n + 1) {
        long long t = stoll(s);
        mx = max(mx, t);
        if (mx == t) max_string = s;
        mn = min(mn, t);
        if (mn == t) min_string = s;

        return;
    }

    int x = s[s.length() - 1] - '0';

    for (int i = 0; i <= 9; i++) {

        if (vis[i]) continue;

        if (c[idx - 1]) {
            if (i < x) continue;
            vis[i] = 1;
            func(idx + 1, s + to_string(i));
            vis[i] = 0;
        }

        if (!c[idx - 1]) {
            if (i > x) continue;
            vis[i] = 1;
            func(idx + 1, s + to_string(i));
            vis[i] = 0;
        }
    }
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;

    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '<') c.push_back(1);
        else c.push_back(0);
    }

    for (int i = 0; i <= 9; i++) {
        vis[i] = 1;
        func(1, to_string(i));
        vis[i] = 0;
    }

    cout << max_string << "\n" << min_string;
}