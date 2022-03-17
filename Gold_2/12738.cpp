#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int lis(const vector<int>& v) {
    vector<int> LIS;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0 || LIS.back() < v[i]) LIS.push_back(v[i]);
        else *lower_bound(LIS.begin(), LIS.end(), v[i]) = v[i];
    }
    return LIS.size();
}

int main() {
    input();
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << lis(v) << "\n";
}
