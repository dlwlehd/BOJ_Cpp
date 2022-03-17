#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> desc;
queue<long long> q;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {
    input();
    cin >> n;
    for (int i=0; i<=9; i++) {
        desc.push_back(i);
        q.push(i);
    }

    while (!q.empty()) {
        long long cur = q.front(); q.pop();
        for (int i = 0; i < cur % 10; i++) {
            long long n = 10 * cur + i;
            desc.push_back(n);
            q.push(n);
        }
    }

    cout << ((n > desc.size()) ? -1 : desc[n - 1]);
}