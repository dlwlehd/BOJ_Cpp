#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n;
    cin >> n;
    unordered_set<string> s;
    for (int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if (log == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> res(s.begin(), s.end());
    sort(res.begin(), res.end(), greater<string>());
    for (auto i : res) cout << i << "\n";
}