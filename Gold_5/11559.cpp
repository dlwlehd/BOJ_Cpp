#include <bits/stdc++.h>
using namespace std;

int combo;
bool loop;
char board[12][6];
bool visited[12][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}


void bfs(int r, int c, char color) {
    queue<pair<int,int>> q;
    vector<pair<int, int>> v;
    q.push({ r, c });
    v.push_back(pair<int, int>(r, c));
    visited[r][c] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;

            if (!visited[nx][ny] && board[nx][ny] == color) {
                q.push({ nx, ny });
                v.push_back({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }

    if (v.size() >= 4) {
        for (int i = 0; i < v.size(); i++) {
            board[v[i].first][v[i].second] = '.';
        }
        loop = true;
    }
}

void puyo_down(int r, int c, char puyo) {
    bool flag = true;
    int x = r;
    int y = c;

    while (flag) {
        board[x][y] = '.';

        if (board[x + 1][y] == '.') {
            board[x + 1][y] = puyo;
            x++;
        }
        else {
            board[x][y] = puyo;
            flag = false;
        }
    }

}

int main(void) {
    input();

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }

    combo = 0;
    while (true) {
        loop = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] != '.') {
                    bfs(i, j, board[i][j]);
                }
            }
        }

        for (int i = 10; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] != '.' && board[i + 1][j] == '.') {
                    puyo_down(i, j, board[i][j]);
                }
            }
        }

        if (loop) combo++;
        else break;
    }

    cout << combo << "\n";

    return 0;
}