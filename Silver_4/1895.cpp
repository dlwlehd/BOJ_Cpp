#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int cnt = 0;
int board[42][42];
vector<int> filter;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

void mid(int x, int y) {
    vector<int> temp;

    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            temp.push_back(board[i][j]);
        }
    }

    sort(temp.begin(),temp.end());
    filter.push_back(temp[4]);
}

int main(void) {

    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cin >> t;
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            mid(i, j);
        }
    }

    for (int i : filter) if (i >= t) cnt++;
    
    cout << cnt;
}