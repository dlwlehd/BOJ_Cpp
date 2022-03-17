#include <bits/stdc++.h>

using namespace std;
int n, q;
int R[100001]; // 주먹
int P[100001]; // 보
int S[100001]; // 가위

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        R[i] = R[i - 1] + (x == 'S');
        P[i] = P[i - 1] + (x == 'H');
        S[i] = S[i - 1] + (x == 'P');
    }

    int ans = 0;
    for (int x = 1; x <= n; x++) {
        int m1 = R[x] + P[n] - P[x];
        int m2 = R[x] + S[n] - S[x];
        int m3 = S[x] + P[n] - P[x];
        int m4 = S[x] + R[n] - R[x];
        int m5 = P[x] + R[n] - R[x];
        int m6 = P[x] + S[n] - S[x];
        ans = max({ans, m1, m2, m3, m4, m5, m6});
    }
    cout << max({ans, R[n], S[n], P[n]});
}