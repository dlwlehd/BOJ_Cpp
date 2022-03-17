#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

int n;
bool vis[52] = {0};

void inp#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

int n, res = 0;
int a[26];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    vector<string> v(n);
    for (string &i: v) cin >> i;

    for (int i = 0; i < n; i++) {
        int pow = 1;
        for (int j = v[i].size() - 1; j >= 0; j--) {
            int val = v[i][j] - 'A';
            a[val] += pow;
            pow *= 10;
        }
    }
    sort(a, a + 26);
    int num = 9;
    for (int i = 25; i >= 0; i--) {
        if (a[i] == 0) break;
        res += (a[i] * num);
        num--;
    }
    cout << res;
}
ut() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = n - 1; i > 0; i--) {
        if (vis[i] || vis[i - 1]) continue;
        if (a[i] > 1 && a[i - 1] > 1) {
            res += a[i] * a[i - 1];
            vis[i] = vis[i - 1] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (vis[i] || vis[i + 1]) continue;
        if (a[i] < 0 && a[i + 1] < 0) {
            res += a[i] * a[i + 1];
            vis[i] = vis[i + 1] = 1;
        }
    }
    int z = 0;
    for (int i = 0; i < n; i++) if (a[i] == 0) z++;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (z > 0 && a[i] < 0) z--;
            else res += a[i];
        }
    }

    cout << res;
}
