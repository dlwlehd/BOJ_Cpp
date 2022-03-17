#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<string> s;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool func(int idx1, int idx2) {
    if (s[idx1].length() != s[idx2].length()) return false;
    char visited1[26] = { 0 }, visited2[26] = { 0 };
    for (int i = 0; i < s[idx1].length(); i++) {
        if (!visited1[s[idx2][i] - 'a'] && !visited2[s[idx1][i] - 'a']) {
            visited1[s[idx2][i] - 'a'] = s[idx1][i];
            visited2[s[idx1][i] - 'a'] = s[idx2][i];
        }
        else if (visited1[s[idx2][i] - 'a'] != s[idx1][i] || visited2[s[idx1][i] - 'a'] != s[idx2][i]) return false;
    }
    return true;
}

int main(void) {

    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.push_back(x);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (func(i, j)) cnt++;
        }
    }

    cout << cnt;
}