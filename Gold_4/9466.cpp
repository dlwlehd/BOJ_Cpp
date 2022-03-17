#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int T, N, cnt;
int arr[100001];
bool vis[100001];
bool done[100001];

void DFS(int n) {
    vis[n] = true;
    int next = arr[n];
    if (!vis[next])
        DFS(next);
    else if (!done[next]) {
        for (int i = next; i != n; i = arr[i]) {
            cnt++;
        }
        cnt++;
    }
    done[n] = true;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> T;
    while (T--)
    {
        cnt = 0;
        fill(done, done + 100001, false);
        fill(vis, vis + 100001, false);
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        for (int i = 1; i <= N; i++)
            if (!vis[i])
                DFS(i);
        cout << N - cnt << '\n';
    }
    return 0;
}