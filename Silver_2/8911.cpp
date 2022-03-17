#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int curX, curY, dir = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void move(char c) {
    if (c == 'F') {
        curX += dx[dir];
        curY += dy[dir];
    }
    if (c == 'B') {
        curX -= dx[dir];
        curY -= dy[dir];
    }
    if (c == 'L') {
        dir--;
        if (dir == -1) dir = 3;
    }
    if (c == 'R') {
        dir++;
        if (dir == 4) dir = 0;
    }
}

void debug() {
    freopen("C:\\Users\\dltkd\\Desktop\\coding\\working\\input.txt", "r", stdin);
    freopen("C:\\Users\\dltkd\\Desktop\\coding\\working\\output.txt", "w", stdout);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        curX = curY = 0;
        int mxX = 0, mnX = 0, mxY = 0, mnY = 0;
        dir = 0;
        for (int i = 0; i < sz(x); i++) {
            move(x[i]);
            mxX = max(curX, mxX);
            mnX = min(curX, mnX);
            mxY = max(curY, mxY);
            mnY = min(curY, mnY);
        }

        int lenX = mxX - mnX;
        int lenY = mxY - mnY;
        cout << lenX * lenY << "\n";
    }
}