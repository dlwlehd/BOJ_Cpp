#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n;
    while (cin >> n) {
        vector<int> a(n);
        vector<int> lis;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            if (i == 0 || lis.back() < a[i]) {
                lis.push_back(a[i]);
            }
            else {
                int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
                lis[idx] = a[i];
            }
        }
        cout << lis.size() << "\n";
    }
}