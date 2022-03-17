#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    vector<int> a;

    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }

    do {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
}