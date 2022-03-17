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
    for (int& i : a) cin >> i;

    vector<int> big(100002), small(100002);

    big[0] = small[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) big[i] = big[i - 1] + 1;
        else big[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) small[i] = small[i - 1] + 1;
        else small[i] = 1;
    }

    cout << max(*max_element(big.begin(), big.begin() + n), *max_element(small.begin(), small.begin() + n));
}
