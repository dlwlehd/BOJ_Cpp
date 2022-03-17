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
    vector<int> tip(n);
    for (int i = 0; i < n; i++) {
        cin >> tip[i];
    }
    sort(tip.begin(), tip.end(), greater<>());

    for (int i = 0; i < n; i++) {
        int temp = tip[i] - i;
        if (temp < 0) temp = 0;
        sum += temp;
    }
    cout << sum;
}