#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;

    ans += (n / 5);
    n -= (5 * ans);

    if (ans > 0 && n % 2 == 1) {
        ans--;
        n += 5;
    }

    ans += (n / 2);
    int x = n / 2;
    n -= 2 * x;
    
    if (n != 0) cout << -1;
    else cout << ans;
}