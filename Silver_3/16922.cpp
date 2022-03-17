#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int rome[4] = { 1,5,10,50 };
bool check[1001];

void func(int idx, int x, int tot) {
    if (idx == n) {
        if (!check[tot]) {
            check[tot] = 1;
            cnt++;
        }
        return;
    }

    for (int i = x; i < 4; i++) {
        func(idx + 1, i, tot + rome[i]);
    }

}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n;
    func(0, 0, 0);

    cout << cnt;
}