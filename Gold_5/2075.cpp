#include <bits/stdc++.h>
using namespace std;

int n, x;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    for (int i = 0; i < n * n - n; i++) {
        cin >> x;
        if (x > pq.top()) {
            pq.push(x);
            pq.pop();
        }
    }
    cout << pq.top();
}