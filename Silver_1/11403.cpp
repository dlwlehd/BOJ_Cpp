#include <bits/stdc++.h>

using namespace std;

bool vis[102] = {0};
int board[102][102] = {0};
int n;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs(int cur) {
    for (int i = 0; i < n; i++) {
        if (board[cur][i] && !vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        fill(vis, vis + n, 0);
        dfs(i);
        for (int j = 0; j < n; j++) if (vis[j]) board[i][j] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}