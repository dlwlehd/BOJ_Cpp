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
    vector<int> a(n), lds;
    for (int &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        if (i == 0 || lds.back() > a[i]) lds.push_back(a[i]);
        else *lower_bound(lds.begin(), lds.end(), a[i], greater<int>()) = a[i];
    }
    cout << n - lds.size();
}