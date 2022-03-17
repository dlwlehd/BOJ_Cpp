#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    long long n;
    cin >> n;
    long long x = 0;
    long long idx = 1;
    while (true) {
        x = idx * (idx + 1) / 2;
        if (x >= n) {
            if (x == n) {
                cout << idx;
                return 0;
            }
            break;
        }
        idx++;
    }
    cout << idx - 1;
}