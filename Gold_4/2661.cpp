#include <bits/stdc++.h>
using namespace std;

int n;
bool flag = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void func(string t, int depth) {
    if (flag) return;

    int len = t.size();
    for (int i = 1; i <= (len / 2); i++) {
        if (t.substr(len - i, i) == t.substr(len - (2 * i), i)) {
            t = "";
            return;
        }
    }

    if (depth > n) return;

    if (depth == n) {
        flag = true;
        cout << t << "\n";
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            func(t + "1", depth + 1);
            func(t + "2", depth + 1);
            func(t + "3", depth + 1);
        }
    }
}

int main(void) {
    input();
    cin >> n;

    func("", 0);
}