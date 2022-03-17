#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair<int, int> pi;
typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 2; i--) {
        if (a[i] < a[i - 1] + a[i - 2]) {
            cout << a[i] + a[i - 1] + a[i - 2];
            return 0;
        }
    }
    cout << -1;
}