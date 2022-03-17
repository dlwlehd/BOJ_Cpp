#include <bits/stdc++.h>

using namespace std;


void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, a, d;
    cin >> n >> a >> d;
    vector<int> v(n);
    for (int &i: v) cin >> i;

    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == a) {
            cnt++;
            a += d;
        }
    }
    cout << cnt;
}