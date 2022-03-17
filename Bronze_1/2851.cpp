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

int main() {
    input();
    vector<int> a(10);
    for (int &i: a) cin >> i;
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res += a[i];
        if (res == 100) {
            cout << 100;
            return 0;
        }
        if (res > 100) {
            if (abs(100 - (res - a[i])) >= abs(100 - res)) {
                cout << res;
                return 0;
            } else {
                cout << res - a[i];
                return 0;
            }
        }
    }
    cout << res;
}