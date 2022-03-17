#include <bits/stdc++.h>
using namespace std;

string s;
int cnt0 = 0, cnt1 = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> s;

    char idx = s[0];
    if (idx == '0') cnt0++;
    else cnt1++;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != idx) {
            if (s[i] == '0') cnt0++;
            else cnt1++;

            idx = s[i];
        }
    }
    if (cnt0 == 0 || cnt1 == 0) cout << 0;
    else cout << min(cnt0, cnt1);
}