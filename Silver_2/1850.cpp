#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    long long n, m;
    cin >> n >> m;
    string s = "";
    for (int i = 0; i < gcd(n, m); i++) {
        s += "1";
    }
    cout << s;
}