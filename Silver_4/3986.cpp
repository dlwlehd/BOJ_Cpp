#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    input();
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
	
    for (int i = 0; i < n; i++) {
        string x = v[i];
        stack<char> s;
        s.push(x[0]);

        for (int j = 1; j < x.length(); j++) {
            if (!s.empty()) {
                char t = s.top();
                if (t == x[j]) s.pop();
                else s.push(x[j]);
            }
            else {
                s.push(x[j]);
            }
        }

        while (true) {
            if (s.empty() || s.size() == 1) break;

            char t = s.top();
            s.pop();
            if (t == s.top()) s.pop();
            else break;
        }

        if (s.empty()) cnt++;
    }
    cout << cnt;
}