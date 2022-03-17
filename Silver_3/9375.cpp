#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            if (m.find(b) == m.end()) m[b] = 1;
            else m[b]++;
        }

        int ans = 1;
        for (auto i: m) ans *= (i.second + 1);
        ans--;
        cout << ans << "\n";
    }

}