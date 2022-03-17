#include <bits/stdc++.h>
using namespace std;

int n, q;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> q;
    unordered_map<string, int> name_to_idx;
    unordered_map<int, string> idx_to_name;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        name_to_idx[s] = i;
        idx_to_name[i] = s;
    }

    while (q--) {
        string s;
        cin >> s;
        if (isdigit(s[0])) cout << idx_to_name[stoi(s)] << "\n";
        else cout << name_to_idx[s] << "\n";
    }
}