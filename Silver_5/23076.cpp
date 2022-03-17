#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main() {
    input();
    int t;
    cin >> t;
    int idx = 1;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> left(n, -INF), right(n, INF);

        int x = -INF;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') x = i;
            left[i] = x;
        }

        x = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') x = i;
            right[i] = x;
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(right[i] - i, i - left[i]);
        }

        cout << "Case #" << idx << ": " << sum << "\n";
        idx++;
    }
}