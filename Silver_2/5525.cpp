#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, m;
    string s;
    cin >> n >> m >> s;
    int ans = 0;

    for (int i = 1; i < s.size(); i++) {
        int count = 0;
        if (s[i - 1] == 'I') {
            while (s[i] == 'O' && s[i + 1] == 'I') {
                i += 2;
                count++;
                if (count == n) {
                    count--;
                    ans++;
                }
            }
        }
    }

    cout << ans;
}