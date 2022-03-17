#include <bits/stdc++.h>
using namespace std;

int n, k;
int res = 987654321;
vector<int> a;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
}

int main(void) {

    input();
    
    for (int i = 0; i < n; i++) {
        vector<int> t(n);
        t[i] = a[i];

        bool flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            t[j] = t[j + 1] - k;
            if (t[j] <= 0) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;

        for (int j = i + 1; j < n; j++) {
            t[j] = t[j - 1] + k;
        }

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != t[j]) cnt++;
        }

        res = min(res, cnt);
    }

    cout << res;
}