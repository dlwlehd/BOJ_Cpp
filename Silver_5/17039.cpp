#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    vector<int> a(3);
    for (int &i: a) cin >> i;

    sort(a.begin(), a.end());
    if (a[2] == a[0] + 2) cout << 0;
    else if (a[1] == a[0] + 2 || a[2] == a[1] + 2) cout << 1;
    else cout << 2;
    cout << "\n";

    cout << (max(a[1] - a[0], a[2] - a[1]) - 1);

}