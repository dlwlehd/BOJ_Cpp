#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int m, n, cnt = 0;
    cin >> m >> n;
    vector<int> a[m], uni[m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    
    for (int i = 0; i < m; i++) {
        vector<int> t = a[i];
        vector<int> tmp;
        sort(t.begin(), t.end());
        for (int j = 0; j < n; j++) {
            if (j == 0 || t[j - 1] != t[j]) tmp.push_back(t[j]);
        }
        for (int j = 0; j < n; j++) {
            uni[i].push_back(lower_bound(tmp.begin(), tmp.end(), a[i][j]) - tmp.begin());
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool flag = 1;
            for (int k = 0; k < n; k++) {
                if (uni[i][k] != uni[j][k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) cnt++;
        }
    }
    cout << cnt;
}