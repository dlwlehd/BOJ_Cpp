#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

int t;
ll n;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            pq.push(x);
        }

        ll res = 0;
        while (pq.size() != 1) {
            ll x = 0;
            x += pq.top();
            pq.pop();
            x += pq.top();
            pq.pop();
            res += x;
            pq.push(x);
        }
        cout << res << "\n";
    }
}
