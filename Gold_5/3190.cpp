#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

bool oob(int x, int y) {
    return x > n || x <= 0 || y > n || y <= 0;
}

int turn_left(int d) {
    d--;
    if (d == -1) d = 3;
    return d;
}

int turn_right(int d) {
    d++;
    if (d == 4) d = 0;
    return d;
}

int main() {
    input();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) fill(board[i], board[i] + n, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    cin >> l;
    vector<int> time(l);
    vector<char> direction(l);
    for (int i = 0; i < l; i++) {
        cin >> time[i] >> direction[i];
    }
    
    int idx = 0;
    int dir = 0;
    int cur_time = 0;
    int head_x = 1;
    int head_y = 1;
    queue<pair<int,int>> q;
    board[1][1] = 2;
    q.push({1,1});
    
    while(true) {
        cur_time++;
        int next_x = head_x + dx[dir];
        int next_y = head_y + dy[dir];
        
        if (oob(next_x, next_y) || board[next_x][next_y] == 2) break;
        
        if (board[next_x][next_y] == 1) {
            board[next_x][next_y] = 2;
            q.push({next_x, next_y});
            head_x = next_x;
            head_y = next_y;
        }
        else {
            q.push({next_x, next_y});
            board[next_x][next_y] = 2;
            head_x = next_x;
            head_y = next_y;
            int front_x = q.front().first;
            int front_y = q.front().second;
            board[front_x][front_y] = 0;
            q.pop();
        }
            
        if (cur_time == time[idx]) {
            if (direction[idx] == 'L') dir = turn_left(dir);
            else dir = turn_right(dir);
            idx++;
        }
    }

    cout << cur_time;
}