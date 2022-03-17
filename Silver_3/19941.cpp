#include <bits/stdc++.h>
using namespace std;

bool vis[20002] = {0};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n, k;
    int res = 0;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            for (int j = i - k; j <= i + k; j++) {
                if (j < 0 || j >= n || i == j) continue;
                if (s[j] == 'H') {
                    if (!vis[j]) {
                        vis[j] = 1;
                        res++;
                        break;
                    }
                }
            }
        }
    }
    cout << res;
}