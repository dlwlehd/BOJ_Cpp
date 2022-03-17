#include <bits/stdc++.h>
using namespace std;

int t, n;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> t;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<>> pq2;
    while (t--) {
        cin >> n;
        if (pq1.size() > pq2.size()) pq2.push(n);
        else pq1.push(n);
        while (pq1.size() && pq2.size() && pq1.top() > pq2.top()) {
            int t1 = pq1.top(); pq1.pop();
            int t2 = pq2.top(); pq2.pop();
            pq1.push(t2); pq2.push(t1);
        }
        cout << pq1.top() << "\n";
    }
}