#include <bits/stdc++.h>

using namespace std;

string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<pair<string, string>> s;
    for (int i = 0; i < n; i++) {
        string a, b, x;
        cin >> a >> x >> x >> x >> x >> b;
        s.push_back({a, b});
    }

    sort(cows, cows + 8);
    vector<int> v;
    for (int i = 0; i < 8; i++) v.push_back(i);
    do {
        vector<string> t;
        for (int i = 0; i < 8; i++) t.push_back(cows[v[i]]);
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            string x = s[i].first, y = s[i].second;
            int idx1 = find(t.begin(), t.end(), x) - t.begin();
            int idx2 = find(t.begin(), t.end(), y) - t.begin();
            if (abs(idx1 - idx2) != 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (string i: t) cout << i << "\n";
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
}