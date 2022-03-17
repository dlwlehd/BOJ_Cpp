#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int T, N, cnt;
string board[30];
bool vis[30][30];
int res[1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] == '0') continue;

            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({ i,j });
            int area = 0;
            while (!Q.empty()) {
                area++;
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] != '1') continue;

                    vis[nx][ny] = 1;
                    Q.push({ nx,ny });
                }
            }
            res[cnt] = area;
        }
    }
    
    sort(res + 1, res + cnt + 1);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << res[i] << "\n";
    }
}