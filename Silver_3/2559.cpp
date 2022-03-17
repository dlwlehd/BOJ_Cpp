#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

const int INF = 1e9 + 9;
int psum[100002] = {0}, a[100002], res = -INF;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) psum[i] = psum[i - 1] + a[i];
    for (int i = 1; i <= n - k + 1; i++) {
        res = max(res, psum[i + k - 1] - psum[i - 1]);
    }
    cout << res;
}