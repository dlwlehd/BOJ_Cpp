#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

ll n, res = 0;
ll a[26];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    cin >> n;
    vector<string> v(n);
    for (string &i: v) cin >> i;

    for (int i = 0; i < n; i++) {
        ll pow = 1;
        for (int j = v[i].size() - 1; j >= 0; j--) {
            ll val = v[i][j] - 'A';
            a[val] += pow;
            pow *= 10;
        }
    }
    sort(a, a + 26);
    int num = 9;
    for (int i = 25; i >= 0; i--) {
        if (a[i] == 0) break;
        res += (a[i] * num);
        num--;
    }
    cout << res;
}
