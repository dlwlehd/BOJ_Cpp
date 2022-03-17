#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

void debug() {
    freopen("E:\\BOJ_Cpp\\input.txt", "r", stdin);
    freopen("E:\\BOJ_Cpp\\output.txt", "w", stdout);
    freopen("E:\\BOJ_Cpp\\debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

bool cmp(pi a, pi b) {
    if (a.X == b.X) return a.Y > b.Y;
    return a.X > b.X;
}

int main() {
    input();
    vector<pi> a;
    vector<int> b;
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(all(a), cmp);
    int tot = 0;
    for (int i = 0; i < 5; i++) {
        tot += a[i].X;
    }
    cout << tot << "\n";
    for (int i = 0; i < 5; i++) {
        b.push_back(a[i].Y);
    }
    sort(all(b));
    for (int i: b) cout << i << " ";
}