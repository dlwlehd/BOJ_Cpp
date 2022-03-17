#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int st = 0, en = 0, sum = a[0], len = n + 1;
    while (st <= en && en < n) {
        if (sum < s) {
            sum += a[++en];
        } else {
            len = min(len, en - st + 1);
            sum -= a[st++];
        }
    }
    if (len == n + 1) cout << 0;
    else cout << len;
}
