#include <bits/stdc++.h>
using namespace std;

int t, n, x;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> t;

    while (t--) {
        int cnt = 0;
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<>> pq2;
        cin >> n;
        if (n % 2 == 0) cout << n / 2 << "\n";
        else cout << n / 2 + 1 << "\n";

        for (int i = 0; i < n; i++) {
            cin >> x;
            if (pq1.size() > pq2.size()) pq2.push(x);
            else pq1.push(x);
            while (pq1.size() && pq2.size() && pq1.top() > pq2.top()) {
                int t1 = pq1.top();
                pq1.pop();
                int t2 = pq2.top();
                pq2.pop();
                pq1.push(t2);
                pq2.push(t1);
            }
            if (i % 2 == 0) {
                cout << pq1.top() << " ";
                cnt++;
                if (cnt % 10 == 0) cout << "\n";
            }
        }
        cout << "\n";
    }
}