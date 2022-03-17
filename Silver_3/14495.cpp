#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

string add(string a, string b) {
    int aSize = a.size();
    int bSize = b.size();
    int carry = 0;

    string res = "";
    while (aSize > 0 || bSize > 0) {
        int partA = 0;
        if (aSize > 0) partA = a[--aSize] - '0';
        int partB = 0;
        if (bSize > 0) partB = b[--bSize] - '0';
        int sum = partA + partB + carry;
        carry = sum / 10;
        sum %= 10;

        res += (sum + '0');
    }
    string ans = "";
    if (carry) ans = "1";
    for (int i = res.size() - 1; i >= 0; i--) ans += res[i];
    return ans;
}

int main() {
    input();
    int n;
    cin >> n;
    string d[120];
    d[1] = d[2] = d[3] = "1";
    for (int i = 4; i <= n; i++) {
        d[i] = add(d[i - 1], d[i - 3]);
    }
    cout << d[n];
}
