#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> lis, pos(n), ans;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (i == 0 || lis.back() < a[i]) {
            lis.push_back(a[i]);
            pos[i] = lis.size();
            continue;
        }
        int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        lis[idx] = a[i];
        pos[i] = idx + 1;
    }
    int x = lis.size();
    for (int i = n - 1; i >= 0; i--) {
        if (x == pos[i]) {
            ans.push_back(a[i]);
            x--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << lis.size() << "\n";
    for (int i : ans) cout << i << " ";
}