#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

string add(string& a, string& b) {
    int aSize = a.length();
    int bSize = b.length();

    int rest = 0;
    string result = "";

    while (aSize > 0 || bSize > 0) {
        int partA = 0;
        if (aSize > 0) {
            partA = a[--aSize] - '0';
        }

        int partB = 0;
        if (bSize > 0) {
            partB = b[--bSize] - '0';
        }

        int partR = partA + partB + rest;
        rest = partR / 10;
        partR %= 10;

        result += (partR + '0');
    }

    string answer = "";
    if (rest > 0) answer = "1";

    for (int i = result.length() - 1; i >= 0; i--) {
        answer += result[i];
    }

    return answer;
}

int main() {
    input();
    int n;
    cin >> n;
    string dp[10002];
    dp[0] = "0";
    dp[1] = dp[2] = "1";
    for (int i = 3; i <= n; i++) {
        dp[i] = add(dp[i - 2], dp[i - 1]);
    }
    cout << dp[n];
}