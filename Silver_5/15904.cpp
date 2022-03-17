#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    string s;
    getline(cin, s);
    char a[4] = {'U', 'C', 'P', 'C'};

    int idx = 0;
    for (char i: s) {
        if (i == a[idx]) idx++;
        if (idx == 4) break;
    }
    cout << (idx == 4 ? "I love UCPC" : "I hate UCPC");
}