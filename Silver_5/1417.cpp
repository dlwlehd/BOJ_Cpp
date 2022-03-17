#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, idx;
    cin >> n >> idx;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> a(n - 1);
    for (int &i: a) cin >> i;
    int cnt = 0;
    while (true) {
        if (idx > *max_element(a.begin(), a.end())) break;
        idx++;
        cnt++;
        a[max_element(a.begin(), a.end()) - a.begin()]--;
    }
    cout << cnt;
}