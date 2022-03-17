#include <bits/stdc++.h>

using namespace std;

set<int> res;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void func(int day, pair<int, vector<int>> x, pair<int, vector<int>> y) {
    if (day == 4) {
        res.insert(x.first);
        return;
    }
    for (int i = 0; i < int((x.second).size()); i++) {
        // Bucket to transfer.
        int t = x.second[i];
        vector<int> X = x.second;
        X.erase(begin(X) + i);
        vector<int> Y = y.second;
        Y.push_back(t);
        func(day + 1, {y.first + t, Y}, {x.first - t, X});
    }
}

int main() {
    input();
    vector<int> a(10), b(10);
    int tot = 1000;
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    func(0, {1000, a}, {1000, b});
    cout << res.size();
}