#include <bits/stdc++.h>

using namespace std;

int psum[200002][26] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < 26; i++) {
        char x = i + 'a';
        if (s[0] == x) psum[0][i] = 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == x) psum[j][i] = psum[j - 1][i] + 1;
            else psum[j][i] = psum[j - 1][i];
        }
    }

    for (int i = 0; i < n; i++) {
        char x;
        int a, b;
        cin >> x >> a >> b;
        int t = x - 'a';
        if (a == 0) cout << psum[b][t] << "\n";
        else cout << psum[b][t] - psum[a - 1][t] << "\n";
    }
}