#include <bits/stdc++.h>
using namespace std;

const int MAX = 31;
const int INF = 1e9 + 7;
struct Color {
    int r, g, b;
};
int n, ans = INF;
int R, G, B, sumR, sumG, sumB;
Color c[MAX];
bool vis[MAX];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void solve(int cur, int cnt) {
    if (cnt >= 2)
        ans = min(ans, abs(sumR/cnt - R) + abs(sumG/cnt - G) + abs(sumB/cnt - B));
    for (int i = cur; i < n; i++) {
        if (!vis[i] && cnt <= 6) {
            vis[i] = true;
            sumR += c[i].r;
            sumG += c[i].g;
            sumB += c[i].b;
            // solve(cur+1, cnt+1) -> TLE
            solve(i + 1, cnt + 1);
            vis[i] = false;
            sumR -= c[i].r;
            sumG -= c[i].g;
            sumB -= c[i].b;
        }
    }
}

int main(void) {
    input();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i].r >> c[i].g >> c[i].b;
    }
    cin >> R >> G >> B;
    solve(0, 0);
    cout << ans;
}