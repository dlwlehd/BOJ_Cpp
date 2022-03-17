#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;

int n, m, x, y, d, cnt = 0;
int board[52][52];
bool vis[52][52] = {0};
int dx[4] = {-1, 0 ,1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int rev(int n) {
    n += 2;
    if (n > 3) n -= 4;
    return n;
}

int left(int d) {
    d--;
    if (d < 0) d = 3;
    return d;
}

int main() {
    input();
    cin >> n >> m >> x >> y >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    while (true) {
        if (vis[x][y] == 0) {
            vis[x][y] = 1;
            cnt++;
        }
        
        bool flag = 0;
        int i = 0;
        while (i != 4) {
            d = left(d);
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (board[nx][ny] == 0 && vis[nx][ny] == 0) {
                x = nx;
                y = ny;
                flag = 1;
                break;
            }
            i++;
        }
        
        if (flag) continue;
        
        int tempD = rev(d);
        int nx = x + dx[tempD];
        int ny = y + dy[tempD];
        if (board[nx][ny] == 1) break;
        else {
            x = nx;
            y = ny;
        }
    }
    cout << cnt;
}