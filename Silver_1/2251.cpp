#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int A, B, C;
bool vis[202][202][202] = {0};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> A >> B >> C;
    queue<tuple<int, int, int>> q;
    vector<int> res;
    q.push({0, 0, C});
    while (!q.empty()) {
        auto[a, b, c] = q.front();
        q.pop();
        if (vis[a][b][c]) continue;
        vis[a][b][c] = 1;
        if (a == 0) res.push_back(c);

        // a -> b
        if (a + b > B) q.push({a + b - B, B, C});
        else q.push({0, a + b, c});
        // a -> c
        if (a + c > C) q.push({a + c - C, b, C});
        else q.push({0, b, a + c});
        // b -> c
        if (b + c > C) q.push({a, b + c - C, C});
        else q.push({a, 0, b + c});
        // b -> a
        if (b + a > A) q.push({A, a + b - A, c});
        else q.push({a + b, 0, c});
        // c -> a
        if (a + c > A) q.push({A, b, a + c - A});
        else q.push({a + c, b, 0});
        // c -> b
        if (b + c > B) q.push({a, B, b + c - B});
        else q.push({a, b + c, 0});
    }

    sort(all(res));
    for (int i: res) cout << i << " ";
}