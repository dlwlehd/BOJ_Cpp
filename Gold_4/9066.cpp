#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

char board[22][22];
int row[22], col[22];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}


int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(row, row + 22, 0);
        fill(col, col + 22, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'V') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int s = row[i] + col[j];
                if (board[i][j] == 'V') s--;
                if (s % 2 != 0) res++;
            }
        }
        
        cout << res << "\n";
    }
}