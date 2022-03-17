#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    string a, b;
    while (cin >> a >> b) {
        int idx = 0;
        for (int i = 0; i < b.size(); i++) {
            if (a[idx] == b[i]) idx++;
            if (idx == a.size()) break;
        }
        cout << (idx == a.size() ? "Yes\n" : "No\n");
    }
}