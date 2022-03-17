#include <bits/stdc++.h>
using namespace std;

int n, star;
string pattern, after, before;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {

    input();
    cin >> n >> pattern;

    for (int i = 0; i < n; i++) {
        if (pattern[i] == '*') star = i;
    }
    before = pattern.substr(0, star);
    after = pattern.substr(star + 1, pattern.size());

    while (n--) {
        string input;
        cin >> input;

        bool flag = true;
        if (input.size() < pattern.size() - 1) {
            cout << "NE\n";
            continue;
        }
        if (before.compare(input.substr(0,before.size())) != 0) flag = false;
        if (after.compare(input.substr(input.size() - after.size(), input.size())) != 0) flag = false;
        flag == true ? cout << "DA\n" : cout << "NE\n";
    }
}