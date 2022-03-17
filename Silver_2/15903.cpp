#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}
int main() {
    input();
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll x; 
        cin >> x;
        pq.push(x);
    }
    for (int i = 0; i < m; i++) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    ll res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res;
}