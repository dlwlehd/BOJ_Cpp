#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string> um;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        um[a] = b;
    }
    
    while(m--) {
        string s;
        cin >> s;
        cout << um[s] << "\n";
    }
}