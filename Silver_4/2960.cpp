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
    int a[10];
    int sum = 0;
    fill(a, a + 10, 0);
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - '0']++;
        sum += s[i] - '0';
    }

    if (sum % 3 != 0 || a[0] == 0) {
        cout << -1;
        return 0;
    }

    string res = "";
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < a[i]; j++) {
            res += to_string(i);
        }
    }
    cout << res;
}