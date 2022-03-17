#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    string s;
    cin >> s;
    vector<pair<int, int>> v(26);
    for (int i = 0; i < 52; i++) {
        int now = s[i] - 'A';
        if (v[now].first == 0) v[now].first = i + 1;
        else v[now].second = i + 1;
    }

    int ans = 0;
    int n = 26;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int s1 = v[i].first;
            int e1 = v[i].second;
            int s2 = v[j].first;
            int e2 = v[j].second;
            if (s1 < s2 && s2 < e1 && e1 < e2) ans++;
        }
    }
    cout << ans;
}