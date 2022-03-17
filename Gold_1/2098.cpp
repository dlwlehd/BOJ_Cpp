#include <bits/stdc++.h>

using namespace std;

int n;
const int INF = 987654321;
int w[18][18], dp[18][1 << 18];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int func(int curr, int vis) {
    int &ret = dp[curr][vis];
    if (ret != -1) return ret;

    if (vis == (1 << n) - 1) {
        if (w[curr][0] != 0) return w[curr][0];
        return INF;
    }

    ret = INF;
    for (int i = 0; i < n; i++) {
        if (vis & (1 << i) || w[curr][i] == 0) continue;
        ret = min(ret, func(i, vis | (1 << i)) + w[curr][i]);
    }
    return ret;
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << func(0, 1);
}