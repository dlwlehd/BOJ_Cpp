#include <bits/stdc++.h>
using namespace std;

int board[5][5];
bool check[5][5];
int num[25];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

bool func() {
    int cnt = 0;
    bool flag;
    for (int i = 0; i < 5; i++) {
        flag = 1;
        for (int j = 0; j < 5; j++) {
            if (check[i][j] != 1) flag = 0;
        }
        if (flag) {
            cnt++;
        }
    }

    for (int i = 0; i < 5; i++) {
        flag = 1;
        for (int j = 0; j < 5; j++) {
            if (check[j][i] != 1) flag = 0;
        }
        if (flag) {
            cnt++;
        }
    }

    flag = 1;
    for (int i = 0; i < 5; i++) {
        if (check[i][i] != 1) flag = 0;
    }
    if (flag) {
        cnt++;
    }

    flag = 1;
    for (int i = 0; i < 5; i++) {
        if (check[i][4 - i] != 1) flag = 0;
    }
    if (flag) {
        cnt++;
    }

    if (cnt >= 3) {
        return true;
    }
    else return false;
}

int main(void) {
    input();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
            check[i][j] = 0;
        }
    }

    for (int i = 0; i < 25; i++) {
        cin >> num[i];
    }

    int idx = 0;
    while(true) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (num[idx] == board[i][j]) check[i][j] = 1;
            }
        }
        if (func()) {
            cout << idx + 1;
            return 0;
        }
        else idx++;
    }
}