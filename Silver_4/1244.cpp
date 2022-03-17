#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m;
vector<int> a;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void man(int num) {
    int x = num;
    while (num <= n) {
        a[num] = a[num] ? 0 : 1;
        num += x;
    }
}

void girl(int num) {
    int l = num - 1, r = num + 1;
    a[num] = a[num] ? 0 : 1;
    while (l >= 1 && r <= n) {
        if (a[l] != a[r]) break;
        a[l] = a[l] ? 0 : 1;
        a[r] = a[r] ? 0 : 1;
        l--;
        r++;
    }
}

int main() {
    input();
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1) {
            man(num);
        } else {
            girl(num);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
}