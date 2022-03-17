#include <bits/stdc++.h>
using namespace std;

int score[6][3];
int games[6][3], ans;
vector<pair<int, int>> teams;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void go(int idx) {

    if (idx == 15) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (score[i][j] != games[i][j]) return;
            }
        }
        ans = 1;
        return;
    }

    int t1 = teams[idx].first, t2 = teams[idx].second;

    games[t1][0]++, games[t2][2]++;
    go(idx + 1);
    games[t1][0]--, games[t2][2]--;

    games[t1][2]++, games[t2][0]++;
    go(idx + 1);
    games[t1][2]--, games[t2][0]--;

    games[t1][1]++, games[t2][1]++;
    go(idx + 1);
    games[t1][1]--, games[t2][1]--;
}

int main() {

    input();
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            teams.push_back({i, j});
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> score[j][k];
                games[j][k] = 0;
            }
        }
        go(0);
        cout << ans << ' ';
        ans = 0;
    }
}