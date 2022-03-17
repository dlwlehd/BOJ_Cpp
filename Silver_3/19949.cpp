#include <bits/stdc++.h>
using namespace std;

int cnt;
int temp[10];
int ans[10];

void func(int idx, int x, int series) {

    if (series == 3) return;

    if (idx == 10) {
        int scr = 0;
        for (int i = 0; i < 10; i++) {
            if (temp[i] == ans[i]) scr++;
        }
        if (scr >= 5) cnt++;
        return;
    }

    for (int i = 1; i <= 5; i++) {
        if (i == x) {
            temp[idx] = i;
            func(idx + 1, i, series + 1);
        }
        else {
            temp[idx] = i;
            func(idx + 1, i, 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 10; i++) {
        cin >> ans[i];
    }
    func(0, 0, 0);
    cout << cnt;
}