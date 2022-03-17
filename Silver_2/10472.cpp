#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[9] = {
        {0, 1, 3}, {0, 1, 2, 4}, {1, 2, 5},
        {0, 3, 4, 6}, {1, 3, 4, 5, 7}, {2, 4, 5, 8},
        {3, 6, 7}, {4, 6, 7, 8}, {5, 7, 8}
};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int click(string s) {
    queue<string> q;
    set<string> check;
    q.push("000000000");
    check.insert("000000000");
    int dist = 1;
    while(!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            string cur = q.front(); q.pop();
            for (int i = 0; i < 9; i++) {
                string x = cur;
                for (int j = 0; j < adj[i].size(); j++) {
                    if (x[adj[i][j]] == '1') x[adj[i][j]] = '0';
                    else x[adj[i][j]] = '1';
                }
                if (check.find(x) != check.end()) continue;
                if (s == x) return dist;
                q.push(x);
                check.insert(x);
            }
        }
        dist++;
    }
}

int main(void) {

    input();
    cin >> n;
    while (n--) {
        int bit = 0;
        string s = "";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char x;
                cin >> x;
                if (x == '*') s += '1';
                else s += '0';
            }
        }
        if (s == "000000000") cout << 0 << "\n";
        else cout << click(s) << "\n";
    }
}