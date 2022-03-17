#include <bits/stdc++.h>
using namespace std;

int n;
int tot = 0;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {

    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x,y });
    }

    sort(v.begin(), v.end(), cmp);

    tot += v[1].first - v[0].first;

    for (int i = 1; i < v.size() - 1; i++) {

        if (v[i].second != v[i - 1].second) {
            tot += v[i + 1].first - v[i].first;
        }

        else if (v[i].second != v[i + 1].second) {
            tot += v[i].first - v[i - 1].first;
        }

        else {
            tot += min(v[i].first - v[i - 1].first, v[i + 1].first - v[i].first);
        }

    }

    tot += v[v.size() - 1].first - v[v.size() - 2].first;
    cout << tot;
}