#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end(), greater<>());
    int idx, res = 0;
    for (int i = 1; i <= *max_element(a.begin(), a.end()); i++) {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] - i >= 0) {
                cnt++;
            }
        }

        if (cnt > n) continue;

        if (max(res, cnt * i) == cnt * i) {
            res = max(res, cnt * i);
            idx = i;
        }
    }
    cout << idx << " " << res;
}