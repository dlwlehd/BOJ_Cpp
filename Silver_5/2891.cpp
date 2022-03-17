#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, s, r;
    cin >> n >> s >> r;
    vector<int> broken(s), spare(r);
    vector<bool> vis(n + 1);
    for (int &i: broken) cin >> i;
    for (int &i: spare) cin >> i;

    for (int i = 0; i < r; i++) {
        int x = spare[i];
        for (int j = 0; j < broken.size(); j++) {
            if (x == broken[j]) {
                broken.erase(broken.begin() + j);
                vis[x] = 1;
            }
        }
    }

    int res = broken.size();

    for (int i = 0; i < broken.size(); i++) {
        int x = broken[i];
        int a = x - 1;
        int b = x + 1;
        bool flag = 0;
        if (a >= 1) {
            for (int j = 0; j < spare.size(); j++) {
                if (spare[j] == a && !vis[spare[j]]) {
                    vis[spare[j]] = 1;
                    res--;
                    flag = 1;
                }
            }
        }
        if (flag) continue;

        if (b <= n) {
            bool flag = 0;
            for (int j = 0; j < spare.size(); j++) {
                if (spare[j] == b && !vis[spare[j]]) {
                    vis[spare[j]] = 1;
                    res--;
                    flag = 1;
                }
            }
        }
    }

    cout << res;
}