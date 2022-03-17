#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
typedef long long ll;

int n, k;

struct medal {
    int idx, g, s, b;

    bool operator<(const medal &a) const {
        if (g == a.g) {
            if (s == a.s) {
                if (b == a.b) {
                    return idx == k;
                }
                return b > a.b;
            }
            return s > a.s;
        }
        return g > a.g;
    }
};

bool isEqual(medal a, medal b) {
    if (a.g != b.g) return false;
    if (a.s != b.s) return false;
    if (a.b != b.g) return false;
    return true;
}

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    cin >> n >> k;
    vector<medal> a;
    for (int i = 0; i < n; i++) {
        medal temp;
        int t, g, s, b;
        cin >> t >> g >> s >> b;
        temp = {t, g, s, b};
        a.push_back(temp);
    }
    sort(all(a));
    for (int i = 0; i < n; i++) {
        if (a[i].idx == k) {
            cout << i + 1;
            return 0;
        }
    }
}