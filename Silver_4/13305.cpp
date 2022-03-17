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
    vector<long long> price(n), city(n-1);
    for (int i = 0; i < n - 1; i++) {
        cin >> city[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    long long buy = 9876543211;
    for (int i = 0; i < n - 1; i++) {
        if (price[i] < buy) buy = price[i];
        sum += buy * city[i];
    }

    cout << sum;
}