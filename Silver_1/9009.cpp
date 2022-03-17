#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
int fi[46];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int t;
    cin >> t;
    fi[0] = 0;
    fi[1] = 1;
    for (int i = 2; i <= 45; i++) fi[i] = fi[i - 1] + fi[i - 2];
    while (t--) {
        int n;
        cin >> n;
        vector<int> res;
        while (n > 0) {
            for (int i = 45; i >= 0; i--) {
                if (fi[i] <= n) {
                    n -= fi[i];
                    res.push_back(fi[i]);
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
        for (int i: res) cout << i << " ";
        cout << "\n";
    }
}