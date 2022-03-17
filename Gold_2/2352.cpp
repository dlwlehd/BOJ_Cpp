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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        if (i == 0 || lis.back() < a[i]) lis.push_back(a[i]);
        else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
    }
    cout << lis.size();
}