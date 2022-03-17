#include <bits/stdc++.h>
using namespace std;

int n, m;
int cow[11];
bool prime[9002], p_vis[9002], vis[11];
vector<int> ans;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void func(int cur, int cnt, int tot) {
    if (cnt == m) {
        if (!prime[tot] && !p_vis[tot]) {
            p_vis[tot] = 1;
            ans.push_back(tot);
        }
        return;
    }

    for (int i = cur; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        func(i + 1, cnt + 1, tot + cow[i]);
        vis[i] = 0;
    }
}

int main(void) {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> cow[i];

    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= 9002; i++) {
        if (prime[i]) continue;
        for (int j = i + i; j <= 9002; j += i) {
            prime[j] = 1;
        }
    }

    func(0,0,0);
    if (ans.empty()) {
        cout << -1;
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << " ";
}