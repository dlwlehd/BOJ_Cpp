#include <bits/stdc++.h>

using namespace std;


void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

string rev(string a) {
    reverse(a.begin(), a.end());
    return a;
}

int main() {
    input();
    int n, k;
    cin >> n >> k;
    string st = "";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st += to_string(x);
    }
    string dest = st;
    sort(dest.begin(), dest.end());
    set<string> vis;
    queue<string> q;
    q.push(st);
    int res = 0;
    while (!q.empty()) {
        int x = q.size();
        string cur;
        for (int i = 0; i < x; i++) {
            cur = q.front();
            q.pop();
            if (cur == dest) {
                cout << res;
                return 0;
            }
            if (vis.find(cur) != vis.end()) continue;

            vis.insert(cur);
            for (int j = 0; j <= n - k; j++) {
                q.push(cur.substr(0, j) + rev(cur.substr(j, k)) +
                       cur.substr(j + k, n - j - k));
            }
        }
        res++;
    }

    cout << -1;
}