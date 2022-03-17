#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> comm, team;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main(void) {

    input();
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        comm.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        team.push_back(x);
    }

    for (int i = 0; i <= k; i++) {
        int idx = 0;
        int max = -987654321;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n - i; k++) {
                if (comm[j] * team[k] > max) {
                    max = comm[j] * team[k];
                    idx = k;
                }
            }
        }
        if (i == k) {
            cout << max;
        }
        team[idx] = team[n - i - 1];
    }
}