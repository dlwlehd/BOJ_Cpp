#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), d(n);
        for (int& i : a) cin >> i;

        d[0] = a[0];
        for (int i = 1; i < n; i++) {
            d[i] = max(d[i - 1] + a[i], a[i]);
        }
        cout << *max_element(d.begin(), d.end()) << "\n";
    }
}
