#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    for (int i = 1; i < n; i++) {
        int x, y;
        x = a[0] / gcd(a[0], a[i]);
        y = a[i] / gcd(a[0], a[i]);
        cout << x << "/" << y << "\n";
    }
}
