#include <bits/stdc++.h>
using namespace std;

long long n, sum = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;
    vector<long long> milk(n);
    for (int i = 0; i < n; i++) {
        cin >> milk[i];
    }
    sort(milk.begin(), milk.end(), greater<>());

    for (int i = 0; i < n; i++) {
        if (i % 3 != 2) sum += milk[i];
    }
    cout << sum;
}