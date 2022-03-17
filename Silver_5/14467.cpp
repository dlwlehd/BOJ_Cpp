#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<int> a[10];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, pos;
        cin >> num >> pos;
        a[num - 1].push_back(pos);
    }

    for (int i = 0; i < 10; i++) {
        if (a[i].size() < 2) continue;
        for (int j = 1; j < a[i].size(); j++) {
            if (a[i][j] != a[i][j - 1]) cnt++;
        }
    }
    cout << cnt;
}