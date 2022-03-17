#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

class cmp {
public:
    bool operator()(pi a, pi b) {
        if (a.X == b.X) {
            return a.Y < b.Y;
        }
        return a.X > b.X;
    }
};


int main() {
    input();
    int n;
    cin >> n;
    vector<pi> a(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    for (int j = 0; j < n; j++) {
        int dead = a[j].first;
        pq.push(-a[j].second);
        if (pq.size() > dead) pq.pop();
    }
    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << -ans << '\n';
}