#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, arr[100002];
ll ans = 0;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    input();
    while (true) {
        cin >> n;
        if (n == 0) break;

        ll ans = 0;
        fill(arr, arr + 100002, 0);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        stack<int> S;
        S.push(0);
        for (int i = 1; i <= n + 1; i++) {
            while (arr[S.top()] > arr[i]) {
                ll height = arr[S.top()];
                S.pop();
                ll width = i - S.top() - 1;
                ans = max(ans, height * width);
            }
            S.push(i);
        }
        cout << ans << '\n';
    }
}