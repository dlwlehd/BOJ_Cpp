#include <bits/stdc++.h>
using namespace std;

int n, m, Map[33][33];
int answer = 0;

bool check(int y, int x) {
    return Map[y - 1][x] && Map[y][x - 1] && Map[y - 1][x - 1];
}

void go(int usedCnt) {
    if (usedCnt == n * m) {
        answer++;
        return;
    }

    int y = usedCnt / m + 1;
    int x = usedCnt % m + 1;

    go(usedCnt + 1);
    if (!check(y, x)) {
        Map[y][x] = 1;
        go(usedCnt + 1);
        Map[y][x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    go(0);
    cout << answer;

    return 0;
}