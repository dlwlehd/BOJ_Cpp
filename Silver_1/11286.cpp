#include <bits/stdc++.h>
using namespace std;

int t, n;

struct cmp {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        else return abs(a) > abs(b);
    }
};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> t;
    priority_queue<int, vector<int>, cmp> pq;
    while (t--) {
        cin >> n;
        if (n == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(n);
    }
}