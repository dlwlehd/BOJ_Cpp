#include <bits/stdc++.h>
using namespace std;

int t;

bool cmp (pair<int,int> a, pair<int,int> b) {
    return a.first * a.second > b.first * b.second;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> t;

    while (t--) {
        int j, n;
        cin >> j >> n;
        vector<pair<int, int>> box(n);
        for (int i = 0; i < n; i++) {
            cin >> box[i].first >> box[i].second;
        }

        sort(box.begin(), box.end(), cmp);
        int cnt = 0, i = 0;
        while(true) {
            if (j <= 0) break;

            j -= box[i].first * box[i].second;
            cnt++;
            i++;
        }

        cout << cnt << "\n";
    }
}