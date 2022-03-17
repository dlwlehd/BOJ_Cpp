#include <bits/stdc++.h>
using namespace std;

int n, l;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> l;
    vector<int> fruit(n);
    for (int i = 0; i < n; i++) {
        cin >> fruit[i];
    }
    sort(fruit.begin(), fruit.end());

    int i = 0;
    while(true) {
        if (i == n || fruit[i] > l) break;

        i++;
        l++;
    }
    cout << l;
}