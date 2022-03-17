#include <bits/stdc++.h>
using namespace std;

int n, p, m, mul, d;
int mx = -987654321;
int mn = 987654321;
vector<int> num;

void func(int P, int M, int Mul, int D, int Sum, int idx) {
    if (idx == n) {
        if (Sum > mx) mx = Sum;
        if (Sum < mn) mn = Sum;
        return;
    }

    if (P < p) func(P + 1, M, Mul, D, Sum + num[idx], idx + 1);
    if (M < m) func(P, M + 1, Mul, D, Sum - num[idx], idx + 1);
    if (Mul < mul) func(P, M, Mul + 1, D, Sum * num[idx], idx + 1);
    if (D < d) func(P, M, Mul, D + 1, Sum / num[idx], idx + 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    cin >> p >> m >> mul >> d;
    func(0, 0, 0, 0, num[0], 1);
    cout << mx << "\n" << mn;
}