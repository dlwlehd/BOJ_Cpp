#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 101;
const int MAX_K = 10001;
const int IMPOSSIBLE = 1000000000;
int N, K, cost[MAX_N], dp[MAX_N][MAX_K];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int coin(int n, int k){
    if(n == N) return (k==0 ? 0 : IMPOSSIBLE); // base case
    if(dp[n][k] != -1) return dp[n][k]; // 이미 계산됨

    int result = coin(n+1, k);
    if(k >= cost[n]) result = min(result, coin(n, k-cost[n]) + 1);
    dp[n][k] = result; // dp 배열 값 갱신
    return result;
}

int main() {
    input();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    // dp 배열 초기화
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
        }
    }

    // dp로 문제 품
    int result = coin(0, K);

    if (result == IMPOSSIBLE) cout << "-1";
    else cout << result;
}