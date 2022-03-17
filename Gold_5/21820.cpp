#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;

int n, l;
vector<int> a;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int idx() {
    int h = a.size();
    while (h > 0 && a[h - 1] < h) h--;
    return h;
}

int main() {
    input();
    cin >> n >> l;
    a.resize(n);
    for (int &i: a) cin >> i;
    sort(all(a), greater<>());

    int h = idx();
    if (h < n) {
        for (int i = h; i >= max(0, h - l + 1); i--) {
            a[i]++;
        }
    }
    sort(all(a), greater<>());
    cout << idx();
}