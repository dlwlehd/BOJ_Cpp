#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

bool cmp(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    input();
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto &i: a) cin >> i.first >> i.second;
    sort(a.begin(), a.end(), cmp);
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        if (t < a[i].first) t = a[i].first;
        t += a[i].second;
    }
    cout << t;
}