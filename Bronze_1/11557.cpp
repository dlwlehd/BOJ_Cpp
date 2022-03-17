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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string res;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            string a;
            int b;
            cin >> a >> b;
            if (b > mx) {
                res = a;
                mx = b;
            }
        }
        cout << res << "\n";
    }
}