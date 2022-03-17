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

bool isFilled(string s, int d) {
    vector<int> a(d, 0);
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - '0']++;
    }
    for (int i = 0; i < d; i++) {
        if (a[i] != 1) return false;
    }
    return true;
}

ll conv(string s, int d) {
    reverse(all(s));
    ll res = 0, idx = 1;
    for (int i = 0; i < s.size(); i++) {
        res += (s[i] - '0') * idx;
        idx *= d;
    }
    return res;
}

int main() {
    input();
    int n, d;
    cin >> n >> d;
    vector<int> t;
    for (int i = 0; i < d; i++) t.push_back(i);
    do {
        string x;
        if (t[0] == 0) continue;
        for (int i = 0; i < d; i++) x += t[i] + '0';
        ll res = conv(x, d);
        if (res > n) {
            cout << res;
            return 0;
        }
    } while (next_permutation(all(t)));
    cout << -1;
}