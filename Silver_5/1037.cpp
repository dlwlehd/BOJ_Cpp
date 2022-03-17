#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);            
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[n - 1];
}