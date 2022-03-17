#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
int weight = 500;
vector<bool> vis;
vector<int> ex;

void func(int idx) {
    if (idx == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            if (weight + ex[i] - k >= 500) {
                weight += ex[i] - k;
                func(idx + 1);
                weight -= ex[i] - k;
                vis[i] = 0;
            }
            else vis[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ex.push_back(x);
        vis.push_back(0);
    }
    func(0);
    cout << cnt;
}