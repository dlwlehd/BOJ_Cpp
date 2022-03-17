#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> c[100];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int func(int i, int j) {
    int cnt = 0;
    vector<string> &v1 = c[i], &v2 = c[j];
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> s >> x;
        for (int j = 0; j < x; j++) {
            cin >> s;
            c[i].push_back(s);
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res = max(res, func(i, j));
        }
    }
    cout << res + 1;
}