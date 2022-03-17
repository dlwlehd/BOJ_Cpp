#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<pii> a(n);

    for (auto &i: a) cin >> i.second;
    for (auto &i: a) cin >> i.first;

    sort(a.begin(), a.end());
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += a[i].first * i + a[i].second;

    cout << res;
}