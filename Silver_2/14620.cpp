#include <bits/stdc++.h>
using namespace std;

int n;
int ans = -1;
int cost[10][10];
bool check[10][10];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int calc() {
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j]) {
                sum += cost[i][j];
                cnt++;
                if (cnt == 15) return sum;
            }
        }
    }
}

void select(int cnt) {
    if (cnt == 3) {
        int tmp = calc();
        if (ans == -1 || ans > tmp)
            ans = tmp;
        return;
    }
    
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {

            bool flag = true;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (check[nx][ny]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            
            check[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                check[nx][ny] = true;
            }

            select(cnt + 1);
            check[i][j] = false;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                check[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    select(0);
    cout << ans;
}