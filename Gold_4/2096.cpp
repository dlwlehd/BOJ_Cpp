#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

int n;
int board[100002][3], maxDP[3], minDP[3];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
            if (i == 0) {
                maxDP[j] = board[i][j];
                minDP[j] = board[i][j];
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        int a[3], b[3];
        for (int j = 0; j < 3; j++) {
            a[j] = maxDP[j];
            b[j] = minDP[j];
        }
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                maxDP[j] = max(a[j], a[j + 1]) + board[i][j];
                minDP[j] = min(b[j], b[j + 1]) + board[i][j];
            }
            
            if (j == 1) {
                maxDP[j] = max(max(a[j], a[j + 1]), a[j - 1]) + board[i][j];
                minDP[j] = min(min(b[j], b[j + 1]), b[j - 1]) + board[i][j];
            }
            
            if (j == 2) {
                maxDP[j] = max(a[j], a[j - 1]) + board[i][j];
                minDP[j] = min(b[j], b[j - 1]) + board[i][j];
            }
        }
    }
    cout << *max_element(maxDP, maxDP + 3) << " " << *min_element(minDP, minDP + 3);
}